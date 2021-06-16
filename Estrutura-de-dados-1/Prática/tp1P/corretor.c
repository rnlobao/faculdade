#include "corretor.h"
#include<stdio.h>
#include<stdlib.h>

struct alunos {
    char letra;
    int tempo;
    char situacao[9];
};

void lerOrdem(int *ordem){
    scanf("%d", ordem);
}

TADalunos *alocaAlunos(TADalunos *A, int ordem){
    A = (TADalunos*) malloc (ordem * sizeof(TADalunos)); 
    if (A == NULL){
        printf ("Memoria insuficiente");
        exit(1);
    }
    return A;
}

TADalunos *desalocaAlunos(TADalunos *A){
  free(A);
  return NULL;
}


void lerAlunos(TADalunos *A, int ordem) {
    int i;
    for (i = 0; i < ordem; i++) {
        scanf("%c %d %s", &A[i].letra, &A[i].tempo, A[i].situacao);
    }

}