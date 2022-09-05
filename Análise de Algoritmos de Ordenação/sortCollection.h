#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void mergeSort(int *v, int l, int r);
void merge(int *v, int l, int m, int r);
int *alocaVetor(int *vetor, int n);
int *desalocaVetor(int *vetor);
void mergeSortConquest(int *vetor, int margem_Esquerda, int nova_Margem, int n);
void selectionSort (int *vetor, int n);
int getMax(int array[], int n);
void countingSort(int array[], int size, int place);
void radixSort(int array[], int size);
