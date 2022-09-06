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

//Uso de tipo abstrato de dados para armazenar as informações submetidas alocao dinamicamente
TADalunos *alocaAlunos(TADalunos *A, int ordem){
    A = (TADalunos*) malloc (ordem * sizeof(TADalunos)); 
    if (A == NULL){
        printf ("Memoria insuficiente");
        exit(1);
    }
    return A;
}

//Desalocando o tipo abstrato que será chamado no principal no final dos procedimentos
TADalunos *desalocaAlunos(TADalunos *A){
  free(A);
  return NULL;
}

//Função que lê os alunos e os armazena nas structs
void lerAlunos(TADalunos *A, int ordem) {
    int i;
    for (i = 0; i < ordem; i++) {
        scanf(" %c", &A[i].letra);
        scanf("%d", &A[i].tempo);
        scanf(" %s", A[i].situacao);
    }
}

//Essa função é a que vai descobrir o primeiro numero printado, comparando a string e encontrando os corretos
int contandocorretos(TADalunos *A, int ordem) {
    int contador = 0;
    for (int i = 0; i < ordem; i++) {
        if (strcmp(A[i].situacao, "correto") == 0) {
            contador++;
        }
    }
    return contador;
}

//Essa função Calcula o tempo todo gasto
int tempototal(TADalunos *A, int ordem) {
    int temponofinal = 0; //Essa é a variável que vai ser retornada no final
    int quantidadedeincompleto = 0;
    for (int i = 0; i < ordem; i++) {
        if (strcmp(A[i].situacao, "correto") == 0) {
            temponofinal += A[i].tempo; //se tiver correto já soma o tempo na variável
        }
        else if (strcmp(A[i].situacao, "incompleto") == 0) {
            //se foi incompleto eu vou verificar se naquela letra em algum momento tem um correto
            char letrabase = A[i].letra;
            for (int j = i; j < ordem; j++) {
                if (A[j].letra == letrabase && strcmp(A[j].situacao, "correto") == 0) {
                    quantidadedeincompleto++;
                }
            } 
            //Armazenando qual o char da letra na variável letrabase eu vejo se a letra é aquela que algum
            //dia esteve incompleta, se sim eu percorro ela e descubro se ela em algum momento vem a ser correta
            //Se sim eu somo na variável quantidade de incompleto pra ser multiplicada por 20 e somada no
            //tempo final, sendo então retornada   
        }
    }
    int valordebitado = quantidadedeincompleto * 20;
    temponofinal += valordebitado;
    return temponofinal;
}

void printsaida(int s, int p) {
    printf("%d %d", s, p);
}
