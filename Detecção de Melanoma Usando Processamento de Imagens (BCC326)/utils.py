import numpy as np
import cv2
import matplotlib.pyplot as plt

# Images loading
def load_image(filename):
    img = cv2.imread(filename)
    return cv2.cvtColor(img, cv2.COLOR_BGR2RGB)


# KMeans segmentation
def kmeans_mask(image, return_rgb=False):
    K = 2
    attempts = 1
    _, labels, centers = cv2.kmeans(np.float32(image.reshape((-1, 3))), K, None, None, attempts, cv2.KMEANS_RANDOM_CENTERS)
    centers = np.uint8(centers)
    lesion_cluster = np.argmin(np.mean(centers, axis=1))
    lesion_mask = labels.flatten() == lesion_cluster
    if return_rgb:
        rgb_mask = np.zeros(image.shape)
        rgb_mask[~lesion_mask.reshape(image.shape[:2])] = 255
        return rgb_mask
    return lesion_mask

def kmeans_segmentation(image, force_copy=True, mask=None):
    lesion_mask = mask if mask else kmeans_mask(image)
    segmented_img = image.reshape((-1, 3))
    if force_copy and segmented_img.base is image:
        segmented_img = segmented_img.copy()
    segmented_img[~lesion_mask] = 255
    return segmented_img.reshape(image.shape)


# Data augmentation
def augment_image(image):
    augmented_images = []
    vertical_flip = cv2.flip(image, 0)
    horizontal_flip = cv2.flip(image, 1)
    augmented_images.append(cv2.rotate(image, cv2.ROTATE_90_CLOCKWISE))
    augmented_images.append(cv2.rotate(image, cv2.ROTATE_90_COUNTERCLOCKWISE))
    augmented_images.append(cv2.rotate(image, cv2.ROTATE_180))
    augmented_images.append(vertical_flip)
    augmented_images.append(horizontal_flip)
    augmented_images.append(cv2.rotate(vertical_flip, cv2.ROTATE_90_CLOCKWISE))
    augmented_images.append(cv2.rotate(horizontal_flip, cv2.ROTATE_90_CLOCKWISE))
    return augmented_images
