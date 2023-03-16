#!/usr/bin/env python3
import argparse
import os

import numpy as np
import pandas as pd
import cv2

from sklearn.model_selection import train_test_split

import keras
import tensorflow as tf
from tensorflow.keras.applications import EfficientNetB0 as EfficientNet

from utils import *


# ------------ Some parameters ------------ #
csv_file = "dataset/ISIC_2020_Training_GroundTruth_v2.csv"
duplicates_csv_file = "dataset/ISIC_2020_Training_Duplicates.csv"
images_folder = "dataset/train_jpeg/"

epochs = 2
batch_size = 256
input_shape = (224, 224, 3)

logging_frequency = 1000


# ------------ Arguments ------------ #
parser = argparse.ArgumentParser()
parser.add_argument("--segmentation", action="store_true", help="Perform segmentation using the k-means algorithm")
args = parser.parse_args()


# ------------ Some setup ------------ #
os.makedirs("checkpoints", exist_ok=True)
os.makedirs("preloaded_data", exist_ok=True)

print("Started")


# ------------ Load images and metadata ------------ #
metadata = pd.read_csv(csv_file)
duplicates = list(pd.read_csv(duplicates_csv_file)['image_name_2'])
metadata.drop(metadata[metadata['image_name'].map(lambda x: x in duplicates)].index, inplace=True)
metadata.reset_index(drop=True, inplace=True)

nb_images = len(metadata)
nb_benign = len(metadata[metadata['benign_malignant'] == 'benign'])
nb_malignant = len(metadata[metadata['benign_malignant'] == 'malignant'])
nb_malignant_augmented = nb_malignant*7
nb_malignant_tot = nb_malignant + nb_malignant_augmented


# Loading full ISIC dataset (without duplicates)
try:
    isic = np.load(f"preloaded_data/isic2020_{input_shape[0]}x{input_shape[1]}.npy", mmap_mode='r')
    assert isic.shape == (nb_images, *input_shape)
except:
    print("Loading ISIC dataset images...")
    isic = np.empty((nb_images, *input_shape), dtype=np.uint8)
    for i, img_filename in enumerate(images_folder + metadata['image_name'] + ".jpg"):
        if i % logging_frequency == 0: print(f"Loading image {i}/{nb_images}")
        isic[i] = cv2.resize(load_image(img_filename), input_shape[:2])
    np.save(f"preloaded_data/isic2020_{input_shape[0]}x{input_shape[1]}.npy", isic)


# Allocating array for our sampled dataset
_images = np.empty((nb_malignant_tot*2, *input_shape), dtype=np.uint8)

images = _images[:nb_malignant_tot+nb_malignant]
augmented_images = _images[nb_malignant_tot+nb_malignant:]

benign = images[:nb_malignant_tot]
malignant = images[nb_malignant_tot:]

benign[:] = isic[metadata[metadata['benign_malignant'] == 'benign'].sample(nb_malignant_tot, random_state=6).index]
malignant[:] = isic[metadata[metadata['benign_malignant'] == 'malignant'].index]

labels = np.array([0]*nb_malignant_tot + [1]*nb_malignant_tot, dtype=np.uint8)

# ------------ Segmentation ------------ #
if args.segmentation:
    print("Segmenting images...")
    for i, img in enumerate(images):
        if i % logging_frequency == 0: print(f"Segmenting image {i}/{len(images)}")
        images[i] = kmeans_segmentation(img, force_copy=False)


# ------------ Data augmentation ------------ #
print("Augmenting data...")
count = 0
for img in malignant:
    for augmented_img in augment_image(img):
        augmented_images[count] = augmented_img
        count += 1

# ------------ Dataset split ------------ #
X_train, X_test, y_train, y_test = train_test_split(_images, labels, train_size=0.9, random_state=6, stratify=labels)
X_train, X_val, y_train, y_val = train_test_split(X_train, y_train, train_size=0.9, random_state=6, stratify=y_train)

train_count, val_count, test_count = np.bincount(y_train), np.bincount(y_val), np.bincount(y_test)
print("""Dataset split:
    Train set:      {} benign ({:.2%}), {} malignant ({:.2%})
    Validation set: {} benign ({:.2%}), {} malignant ({:.2%})
    Test set:       {} benign ({:.2%}), {} malignant ({:.2%})
""".format(
    train_count[0], train_count[0]/sum(train_count), train_count[1], train_count[1]/sum(train_count),
    val_count[0],   val_count[0]/sum(val_count),     val_count[1],   val_count[1]/sum(val_count),
    test_count[0],  test_count[0]/sum(test_count),   test_count[1],  test_count[1]/sum(test_count)
))

# ------------ Training ------------ #
print("Starting training model")

mirrored_strategy = tf.distribute.MirroredStrategy()

with mirrored_strategy.scope():
    efficientnet = EfficientNet(weights='imagenet', include_top=False, input_shape=input_shape, classes=2)

    model = keras.models.Sequential()
    model.add(efficientnet)
    model.add(keras.layers.GlobalAveragePooling2D())
    model.add(keras.layers.Dense(1, activation='sigmoid'))

    model.summary()

    model.compile(optimizer='adam', loss='binary_crossentropy', metrics=['binary_accuracy'])

# Early stopping to monitor the validation loss and avoid overfitting
early_stop = keras.callbacks.EarlyStopping(monitor='val_loss', mode='min', verbose=1, patience=50, restore_best_weights=True)

# Reducing learning rate on plateau
reduce_lr = keras.callbacks.ReduceLROnPlateau(monitor='val_loss', mode='min', patience=5, factor=0.5, verbose=1)

callbacks = [early_stop, reduce_lr]

try:
    history = model.fit(
        x=X_train,
        y=y_train,
        validation_data=(X_val, y_val),
        epochs=epochs,
        batch_size=batch_size,
        verbose=2,
        callbacks=callbacks,
        shuffle=True
    )
except:
    print("===Error===")
    pass

print("Saving model...")
model.save_weights("final_model.h5")

print("Training finished!")

# Plotting loss and accuracy history
plt.figure()
plt.plot(history.history['loss'], label="Training loss")
plt.plot(history.history['val_loss'], label="Validation loss")
plt.title("Training and validation loss during training")
plt.xlabel("No. epoch")
plt.ylabel("Loss")
plt.legend()
plt.savefig("checkpoints" + "/loss_history.png")

plt.figure()
plt.plot(history.history['binary_accuracy'], label="Training accuracy")
plt.plot(history.history['val_binary_accuracy'], label="Validation accuracy")
plt.title("Training and validation accuracy during training")
plt.xlabel("No. epoch")
plt.ylabel("Binary accuracy")
plt.legend()
plt.savefig("checkpoints" + "/accuracy_history.png")


# ------------ Evaluation ------------ #
metrics = model.evaluate(X_test, y_test, return_dict=True)
print(f"Model evaluation on test data:\n{metrics}")

with open("checkpoints" + "/eval_metrics", 'w') as f:
    f.write(str(metrics))