#include "matriz.h"
#include<stdio.h>

void lerOperacao(char *operacao){
    scanf("%c", operacao);
}

void lerMatriz(double M[][12]){
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            scanf("%lf", &M[i][j]);
        }
    }
}

double somaMatriz(double M[][12]){
    double soma = 0;
    int ajuda = 0;
    for (int k = 0; k < 5; k++) {
        for (int l = k+1; l < 11-ajuda; l++) {
            soma += M[k][l]; 
        }
        ajuda++;
        
    }
    return soma;
}

double media(double resultado){
    return resultado/30;
}

void printResultado(double resultado){
    printf("%.1lf", resultado);
}
