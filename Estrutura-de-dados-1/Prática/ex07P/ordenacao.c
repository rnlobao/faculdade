#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Manter como especificado
TipoAluno *alocaAlunos(TipoAluno *alunos, int n){
   alunos = (TipoAluno*) malloc (n * sizeof(TipoAluno)); 
    if (alunos == NULL){
        printf ("Memoria insuficiente");
        exit(1);
    }
    return alunos;
}

//Manter como especificado
TipoAluno *desalocaAlunos(TipoAluno *alunos){
  free(alunos);
  return NULL;
}

//Usando selectionsort
void ordena(TipoAluno *alunos, int n){
  int min;
    for (int i = 0; i < n; i++) {
        min = i;
        for (int j = i+1; j < n; j++) {
            if (strcmp(alunos[j].nome, alunos[min].nome) < 0) {
                min = j;
            }
        }
        TipoAluno aux = alunos[i];
        alunos[i] = alunos[min];
        alunos[min] = aux;
    }
}
