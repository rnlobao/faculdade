Avaliaçao empírica do MergeSort, RadixSort e SelectionSort.

<p float="left">
  <img src="https://user-images.githubusercontent.com/66230142/188340840-d321b618-cdc3-4795-8de9-05446aadc488.gif" width="300" height="200"/>
  <img src="https://user-images.githubusercontent.com/66230142/188340843-33a20eb9-c408-47ea-80a5-6753fce22327.gif" width="300" height="200"/>
  <img src="https://user-images.githubusercontent.com/66230142/188340846-7cb4c443-920c-4959-8dad-5a19f33a0d5e.gif" width="300" height="200"/>
</p>

Sendo o mergeSort O(n * log n), SelectionSort O(𝑛2) e o Radix O(nk)

Fez-se a análise estatística dos métodos fazendo 20 testes com instâncias variando de 100, 1.000, 10.000, 100.000 e 1.000.000 para saber seu desempenho e foi chegado nos seguintes resultados:

<p align="center">
  <img src="https://user-images.githubusercontent.com/66230142/188341306-397f3d30-6ad2-4362-b942-e739c837e9ce.png" width="700" height="350"/>
</p>


Averiguando que quanto maior a instância mais o algoritmo com análise assintótica pior, no caso o Selection, vai se tornando ineficiente:

<p align="center">
  <img src="https://user-images.githubusercontent.com/66230142/188341501-ab6935e3-3cae-487c-95e4-7afda8473b0b.png" width="400" height="350"/>
</p>
