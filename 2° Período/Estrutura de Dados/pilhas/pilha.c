#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicia as variaveis da pilha
void Pilha_Inicia(Pilha *pilha) {
    pilha->cabeca = (Celula*) malloc(sizeof(Celula));
    pilha->cabeca->prox = NULL;
}

//Retorna se a pilha esta vazia
int Pilha_EhVazia(Pilha *pilha) {
    if (pilha->cabeca->prox == NULL) {
        return 1;
    }
    return 0;
}

// Insere um item no topo da pilha
int Pilha_Push(Pilha *pilha, Item item) {
    Celula *celula = (Celula*) malloc(sizeof(Celula));
    if (celula == NULL) {
        return 0;
    }
    celula->item = item;
    celula->prox = pilha->cabeca->prox;
    pilha->cabeca->prox = celula;
    pilha->tamanho++;
    return 1;
}

// Retira o item do topo da pilha
int Pilha_Pop(Pilha *pilha, Item *item) {
    if (Pilha_EhVazia(pilha)) {
        return 0;
    }
    Celula *celula = pilha->cabeca->prox;
    pilha->cabeca->prox = celula->prox;
    (*item) = celula->item;
    free(celula);
    pilha->tamanho--;
    return 1;
}

//Remove cada elemento de uma pilha e libera a memória
void Pilha_Esvazia(Pilha *pilha) {
    Celula *celula = pilha->cabeca;
    Celula *aux;
    while (celula != NULL) {
        aux = celula->prox;
        free(celula);
        celula = aux;
    }
}
