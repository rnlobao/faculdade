Nesse trabalho foi criado uma rede neural convolucional que é um algoritmo de Aprendizado Profundo que pode captar uma imagem de entrada, atribuir importância (pesos e vieses que podem ser aprendidos) a vários aspectos / objetos da imagem e ser capaz de diferenciar um do outro.

![image](https://user-images.githubusercontent.com/66230142/225484967-5e55937f-b71b-48fe-afcb-a310486373fd.png)

Em que dada uma imagem de uma lesão de pele utilizando o dataset do ISIC 2020 de 33000 imagens aproximadamente

<img width="774" alt="image" src="https://user-images.githubusercontent.com/66230142/225485138-8fece60a-de2e-485f-a4e0-c4ddb4ce14ad.png">

O algoritmo deveria ser capaz de dizer se a lesao é um melanoma ou nao.

Para a tarefa de classificação, foi usado EfficientNet B0 pré-treinada em ImageNet sem as camadas densas no final, que foram substituídas por uma camada densa conectada a um único nó com a função de ativação sigmoid, para que o modelo produza uma probabilidade de que a imagem de entrada seja maligna. A função sigmoid é frequentemente usada para produzir uma saída de probabilidade entre 0 e 1. Isso é útil para tarefas de classificação binária, como determinar se uma imagem é maligna ou benigna. Quando a saída da função sigmoid é 0.5 ou superior, é provável que a imagem seja maligna, e quando a saída é inferior a 0.5, é provável que a imagem seja benigna.

Além disso foi adicionado um GlobalAveragePooling2D antes da última camada densa, o pooling global de média é uma técnica de pooling que calcula a média dos valores de cada canal de recurso em uma camada convolucional. Essa técnica reduz a dimensionalidade dos recursos de uma imagem para um vetor de tamanho fixo, independentemente do tamanho da imagem de entrada.

```
mirrored_strategy = tf.distribute.MirroredStrategy()

with mirrored_strategy.scope():
    efficientnet = EfficientNet(weights='imagenet', include_top=False, input_shape=input_shape, classes=2)
    model = keras.models.Sequential()
    model.add(efficientnet)
    model.add(keras.layers.GlobalAveragePooling2D())
    model.add(keras.layers.Dense(1, activation='sigmoid'))
    model.summary()
    model.compile(optimizer='adam', loss='binary_crossentropy', metrics=['binary_accuracy'])
```

Ademais, dois callbacks foram adicionados ao model antes de fazer seu fit, o earlyStopping que é usado para interromper o treinamento da rede neural quando uma determinada métrica não melhora mais depois de um certo número de épocas; já o ReduceLROnPlateau é usado para reduzir a taxa de aprendizagem da rede neural quando uma determinada métrica não melhora mais depois de um certo número de épocas.

```
early_stop = keras.callbacks.EarlyStopping(monitor='val_loss', mode='min', verbose=1, patience=50, restore_best_weights=True)
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
```


Com isso pudemos fazer o treinamento utilizando imagens segmentadas e nao segmentadas, que é basicamente com a lesao recortada ou nao, como no exemplo:

![image](https://user-images.githubusercontent.com/66230142/225485619-00a87c14-35af-49ad-a2d2-998a0f491f8e.png)

Com os modelos de treinamento gerados, com e sem segmentaçao chegamos nos seguintes resultados: 

 Sem segmentaçao | Com segmentaçao 
  :---------: | :---------:
  ![image](https://user-images.githubusercontent.com/66230142/225485931-d469bf09-cc03-4d61-90eb-7e4e379177f2.png) | ![image](https://user-images.githubusercontent.com/66230142/225485962-f7194938-7387-477a-9d19-66c93a1b1c5f.png)

Mostrando ligeira vantagem para o modelo de treinamento sem segmentacao, onde foram treinados com 35 epochs e 8000 imagens do Dataset.

Além disso, mais detalhes sobre o código podem ser encontrados no vídeo: https://youtu.be/18UqTLnRVeQ

