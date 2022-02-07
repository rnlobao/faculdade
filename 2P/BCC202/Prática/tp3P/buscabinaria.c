#include <stdio.h>
#include <stdlib.h>
#include "buscabinaria.h"
#define UNKNOWNERROR 0.000005

double BuscaBinaria(double area, double remove[], int n, double inicio, double final) {
    
    double delimita = (final + inicio) / 2.0;
    double metrosquadrados = 0;
    
    for (int i = 0; i < n; i++) {
        if(remove[i] > delimita) {
            metrosquadrados = (remove[i] - delimita) + metrosquadrados;
        }
    }
    double diferenca = final - inicio;
    if (diferenca < UNKNOWNERROR) {
        return delimita;
    } 

    else if(metrosquadrados > area) {
        return BuscaBinaria(area, remove, n, delimita, final);
    } 

    else {
        return BuscaBinaria(area, remove, n, inicio, delimita);
    }
}

void PrintResultado(double metrosquadradosremovidos, double a, double remove[], int n, double maior) {
    double altura = 0.0;

    if (metrosquadradosremovidos == a) {
        HappyFace();
    } 

    else if(metrosquadradosremovidos < a) {
        SadFace();
    } 

    else {
        altura = BuscaBinaria(a, remove, n, 0.0, maior);
        printf("%.4f\n", altura);
    }        
}

void HappyFace() {
    printf(":D\n");
}

void SadFace() {
    printf("-.-\n");
}
