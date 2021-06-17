#include "corretor.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Struct dos alunos
struct alunos {
    char letra;
    int tempo;
    char situacao[10];
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
        scanf(" %c", &A[i].letra);
        scanf("%d", &A[i].tempo);
        scanf(" %s", A[i].situacao);
    }
}

int contandocorretos(TADalunos *A, int ordem) {
    int contador = 0;
    for (int i = 0; i < ordem; i++) {
        if (strcmp(A[i].situacao, "correto") == 0) {
            contador++;
        }
    }
    return contador;
}

int tempototal(TADalunos *A, int ordem) {
    int temponofinal = 0;
    int quantidadedeincompleto = 0;
    for (int i = 0; i < ordem; i++) {
        if (strcmp(A[i].situacao, "correto") == 0) {
            temponofinal += A[i].tempo;
        }
        else if (strcmp(A[i].situacao, "incompleto") == 0) {
            //se nunca teve um correto vai seguir essas instruções:
            char letrabase = A[i].letra;
            for (int j = i; j < ordem; j++) {
                if (A[j].letra == letrabase && strcmp(A[j].situacao, "correto") == 0) {
                    quantidadedeincompleto++;
                }
            }
            
            
        }
    }
    int valordebitado = quantidadedeincompleto * 20;
    temponofinal += valordebitado;
    return temponofinal;
}

void printsaida(int s, int p) {
    printf("%d %d", s, p);
}
