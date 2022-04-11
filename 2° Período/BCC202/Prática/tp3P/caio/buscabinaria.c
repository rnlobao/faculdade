#include "buscabinaria.h"
#include <stdio.h>
#include <stdlib.h>

#define ERRO 0.000005

double buscaBinaria(double area, double tira[], int n, double begin, double end) {
    
    double corte = (end + begin) / 2.0, areaCorte = 0;
    
    for(int i = 0; i < n; i++) {
        if(tira[i] > corte) {
            areaCorte += (tira[i] - corte);
        }
    }
    if(end - begin < ERRO) {
        return corte;
    } else if(areaCorte > area) {
        return buscaBinaria(area, tira, n, corte, end);
    } else {
        return buscaBinaria(area, tira, n, begin, corte);
    }
}

void imprimirRESULT(double areaTira, double a, double tira[], int n, double maior) {
    double h = 0.0;
    if(areaTira == a) {
            printf(":D\n");
        } else if(areaTira < a) {
            printf("-.-\n");
    } else {
            h = buscaBinaria(a, tira, n, 0.0, maior);
            printf("%.4f\n", h);
        }        
}
