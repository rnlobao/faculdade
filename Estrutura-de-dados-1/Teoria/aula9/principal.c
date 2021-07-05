#include "arrays.h"
#include<stdio.h>

void concatena(TADLista *A, TADLista *B){
    int j=0;
    for (int i = A->last; i<=(A->last + B->last - 1); i++){
        A->item[i].key = B->item[j].key;
        j++;
    }
    //empurrando para adicionar ao ultimo elemento
    A->last = A->last + B->last;
}

void divide(TADLista *A, TADLista *parte1, TADLista *parte2, int x){
    for (int i = inicio; i<x; i++){
        parte1->item[i].key = A->item[i].key;   
    }
    parte1->first = 0;
    parte1->last = x;
    int j=0;
    for (int i = x; i<A->last; i++){
        parte2->item[j].key = A->item[i].key;
        j++;
    }
    parte2->first = 0;
    parte2->last = A->last-x;
}

void copia(TADLista *A, TADLista *C){
    C->first = inicio;
    C->last = A->last;
    for (int i=inicio; i<A->last; i++){
        C->item[i].key = A->item[i].key;
    }

}

int pesquisa(TADLista *A, int x){
    for (int i=0; i<A->last; i++){
        if(A->item[i].key == x){
            printf("%d esta na posição [%d]!\n", x, i);
            return i;
        }
    }
    printf("%d não existe no array :(\n", x);
    return -1;
}



int main()
{
    TADLista A, B, parte1, parte2, C;
    //printf("linha 21\n");

    A.first = 0;
    A.last = 5;

    A.item[0].key = 0;
    A.item[1].key = 1;
    A.item[2].key = 2;
    A.item[3].key = 3;
    A.item[4].key = 4;

    imprime(&A);

    B.first = 0;
    B.last = 5;

    B.item[0].key = 5;
    B.item[1].key = 6;
    B.item[2].key = 7;
    B.item[3].key = 8;
    B.item[4].key = 9;

    concatena(&A, &B);

    imprime(&A);
    divide(&A, &parte1, &parte2, 5);

    printf("parte 1: \n");
    imprime(&parte1);

    printf("\n\nparte 2: \n");
    imprime(&parte2);

    copia(&A, &C);
    imprime(&C);

    pesquisa(&A, 5);
    pesquisa(&A, 56);



    return 0;
}


