#include "prioridade.h"
#include <stdio.h>
#include <stdlib.h>

//Manter como especificado
TipoCaixa *alocaVetor(TipoCaixa *heap, int n){
    heap = (TipoCaixa*) malloc (n * sizeof(TipoCaixa)); 
    if (heap == NULL){
        printf ("Memoria insuficiente");
        exit(1);
    }
  return heap;
}

//Manter como especificado
TipoCaixa *desalocaVetor(TipoCaixa *heap){
    free(heap);
    return NULL;
}

//Manter como especificado
void Heap_Constroi(TipoCaixa *heap, int n){
    int esq = (n/2) - 1;
    while (esq < (n/2)-1) {
        Heap_Refaz(heap, esq, n-1);
        esq--;
    }
}

//Manter como especificado
void Heap_Refaz(TipoCaixa *heap, int esq, int dir){
    int i = esq;
    int j = i * 2 + 1;
    TipoCaixa aux;
    aux.tempolevado = heap[i].tempolevado;
    while (j <= dir) {
        if ((j < dir) && (heap[j].tempolevado < heap[j+1].tempolevado)) {
            j = j+1;
        }
        if (aux.tempolevado >= heap[j].tempolevado) {
            break;
        }
        heap[i].tempolevado = heap[j].tempolevado;
        i = j;
        j = i * 2 + 1;
    }
    heap[i].tempolevado = aux.tempolevado;
}
