#include "sortCollection.h"

/* Merge Sort */

void mergeSort(int *v, int l, int r) {
	int m;
	if (l < r) {
		m = (l+r)/2;
		mergeSort(v, l, m);
		mergeSort(v, m+1, r);
		merge(v, l, m, r);
	}
}

void merge(int *v, int l, int m, int r) {
	int sizeL = (m-l+1), sizeR = (r-m), i, j;
	int *vetorL = NULL, *vetorR = NULL;
	vetorL = alocaVetor(vetorL, sizeL);
	vetorR = alocaVetor(vetorR, sizeR);

	for (i = 0; i < sizeL; i++) {
		vetorL[i] = v[i+l];
	}
	for (j = 0; j < sizeR; j++) {
		vetorR[j] = v[m+j+1];
	}

	i = 0; j = 0;
	for (int k = l; k <= r; k++) {
		if (i == sizeL) {
			v[k] = vetorR[j++];
		} else if (j == sizeR) {
			v[k] = vetorL[i++];
		} else if (vetorL[i] <= vetorR[j]) {
			v[k] = vetorL[i++];
		} else {
			v[k] = vetorR[j++];
		}
	}

	vetorL = desalocaVetor(vetorL);
	vetorR = desalocaVetor(vetorR);
}

int *alocaVetor(int *vetor, int n)
{
    vetor = (int *)malloc(n * sizeof(int));
    if (vetor == NULL)
    {
        printf("Memória insuficiente.\n");
        exit(1);
    }

    return vetor;
}

int *desalocaVetor(int *vetor)
{
    free(vetor);
    return NULL;
}


/* selection Sort */   

void selectionSort (int *vetor, int n) {                                        //  Instruções  |       Quantidade
    int aux;                                                                    //  Atribuição  |           1
    int menorAtual;                                                             //  Atribuição  |           1
    for(int i = 0; i < n; i++) {                                                //   Inc/Comp   |          n+1                        
        menorAtual = i;                                                         //  Atribuição  |           n
        for (int j = i + 1; j < n; j++) {                                       //   Inc/Comp   | ((n-1) + (n-2) + ... + 1) + 1
            if (vetor[j] < vetor[menorAtual])                                   //  Comparação  | ((n-1) + (n-2) + ... + 1)
                menorAtual = j;                                                 //  Atribuição  | ((n-1) + (n-2) + ... + 1)(ti) p/i
        }                                                                       
        if(menorAtual != i) {                                                   //  Comparação  |           n
            aux = vetor[i];                                                     //  Atribuição  |       n(ti) p/i
            vetor[i] = vetor[menorAtual];                                       //  Atribuição  |       n(ti) p/i   
            vetor[menorAtual] = aux;                                            //  Atribuição  |       n(ti) p/i
        }
    }
}

/* Radix Sort */

int getMax(int array[], int n) {
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

void countingSort(int array[], int size, int place) {
  int output[size + 1];
  int max = (array[0] / place) % 10;

  for (int i = 1; i < size; i++) {
    if (((array[i] / place) % 10) > max)
      max = array[i];
  }
  int count[max + 1];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;
    
  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];

  for (int i = size - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];
}

void radixSort(int array[], int size) {
  int max = getMax(array, size);

  for (int place = 1; max / place > 0; place *= 10)
    countingSort(array, size, place);
}