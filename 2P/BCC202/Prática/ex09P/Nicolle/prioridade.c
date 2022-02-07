#include "prioridade.h"
#include <stdio.h>
#include <stdlib.h>

//Manter como especificado
TipoCaixa *alocaVetor(TipoCaixa *heap, int n){
	for (int i = 0; i < n; i++){
   		heap = malloc (n * sizeof (TipoCaixa)) ;
	}
	return heap;
}

//Manter como especificado
TipoCaixa *desalocaVetor(TipoCaixa *heap){
	free(heap);
	return heap;
}

void Heap_Constroi(TipoCaixa *heap, int n){
	int esq = (n/2) - 1;
	//imprime(heap, n);
	while(esq >= 0){
		Heap_Refaz(heap, esq, n-1);
		esq = esq - 1;
	}
}

void Heap_Refaz(TipoCaixa *heap, int esq, int dir){
	int i = esq;
	int j = i * 2 + 1; // filho da esquerda. o outro é j+1
	
	TipoCaixa aux = heap[i];

	while(j <= dir){
		if(j<dir){
			if((heap[j].timeused > heap[j+1].timeused) || ((heap[j].timeused == heap[j+1].timeused) && (heap[j].index > heap[j+1].index))){//acha o menor filho, esq ou dir
				j = j +1;
			}
		}
		if((aux.timeused < heap[j].timeused) || ((aux.timeused == heap[j].timeused) && (aux.index < heap[j].index))){ //se for menor, ok
			break;
		}
		heap[i] = heap[j];
		i = j;
		j = i * 2 + 1; //proximo filho
	}
	heap[i] = aux;
}

void leitor(TipoCaixa *heap, int n){
	for (int i = 0; i < n; i++){
  		scanf("%d", &heap[i].time);
  		heap[i].index = i;
  		heap[i].timeused = 0;
  	}
}


void imprime(TipoCaixa *heap, int n){
	printf("\n\n");
	for (int i = 0; i < n; i++){
  		printf("o caixa %d(%d) demora %dmin/item e está atendendo há %d minutos \n", i, heap[i].index, heap[i].time, heap[i].timeused);
  	}
}

