#include "ordenacao.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct paises {
    char pais[50];
    int ouro;
    int prata;
    int bronze;
    int score;
};

void lerTam(int *tam) {
    scanf("%d", tam);
}

TADpaises *alocaPaises(TADpaises *p, int tam){
    p = (TADpaises*) malloc (tam * sizeof(TADpaises)); 
    if (p == NULL){
        printf ("Memoria insuficiente");
        exit(1);
    }
    return p;
}

TADpaises *desalocaPaises(TADpaises *p){
  free(p);
  return NULL;
}

void lerPaises(TADpaises *p, int tam) {
    for (int i = 0; i < tam; i++) {
        scanf(" %s", p[i].pais);
        scanf("%d", &p[i].ouro);
        scanf("%d", &p[i].prata);
        scanf("%d", &p[i].bronze);
    }
}

TADpaises *organizascore(TADpaises *p, int tam) {
    int min;
    for (int i = 0; i < tam; i++) {
        min = i;
        for (int j = i+1; j < tam; j++) {
            if (p[j].score > p[min].score) {
                min = j;
            }
        }
        TADpaises aux = p[i];
        p[i] = p[min];
        p[min] = aux;
    }
    return p;
} 

TADpaises *pontuar(TADpaises *p, int tam) {
    int valor1, valor2, valor3, valor4 = 0;
    for (int i = 0; i < tam; i++) {
        valor1 = p[i].ouro * 10000000;
        valor2 = p[i].prata * 10000;
        valor3 = p[i].bronze * 10;
        valor4 = valor1 + valor2 + valor3;
        p[i].score = valor4;
    }
    return p;
}

TADpaises *confererepetido(TADpaises *p, int tam) {
   int valordaprimeiraletra1, valordaprimeiraletra2;
    for (int i = 0; i < tam; i++) {
        if (i == 0) {
            if (p[i].score == p[i+1].score) {
                valordaprimeiraletra1 = p[i].pais[0];
                valordaprimeiraletra2 = p[i+1].pais[0];
                if (valordaprimeiraletra1 > valordaprimeiraletra2) {
                    p[i+1].score = p[i+1].score + 1;
                }
                else {
                    p[i].score = p[i].score + 1;
                }
            }
        }

        if (i == tam-1) {
            if (p[i].score == p[i-1].score) {
                valordaprimeiraletra1 = p[i].pais[0];
                valordaprimeiraletra2 = p[i-1].pais[0];
                if (valordaprimeiraletra1 > valordaprimeiraletra2) {
                    p[i-1].score = p[i-1].score + 1;
                }
                else {
                    p[i].score = p[i].score + 1;
                }
            }
        }
        else {
            if (p[i].score == p[i+1].score || p[i].score == p[i-1].score) {
                if (p[i].score == p[i+1].score) {
                    valordaprimeiraletra1 = p[i].pais[0];
                    valordaprimeiraletra2 = p[i+1].pais[0];
                    if (valordaprimeiraletra1 > valordaprimeiraletra2) {
                        p[i+1].score = p[i+1].score + 1;
                    }
                    else {
                        p[i].score = p[i].score + 1;
                    }
                if (p[i].score == p[i-1].score) {
                valordaprimeiraletra1 = p[i].pais[0];
                valordaprimeiraletra2 = p[i-1].pais[0];
                if (valordaprimeiraletra1 > valordaprimeiraletra2) {
                    p[i-1].score = p[i-1].score + 1;
                }
                else {
                    p[i].score = p[i].score + 1;
                }
            }
            }
        }
        }
        
    }
    return p;
}

void printatad(TADpaises *p, int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%s %d %d %d\n", p[i].pais, p[i].ouro, p[i].prata, p[i].bronze);
    }
}