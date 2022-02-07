#include "buscabinaria.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    double a, areaTira;
    int n;
    double tira[100000];
    
    scanf("%d %lf", &n, &a);
    
    double maior = 0;
    
    while(n != 0 && a != 0) {
        areaTira = 0;
        for(int i = 0; i < n; i++) {
            scanf("%lf", &tira[i]);
            areaTira += tira[i];
            if(tira[i] > maior) {
                maior = tira[i];
            }
        }
        imprimirRESULT(areaTira, a, tira, n, maior);
        scanf("%d %lf", &n, &a);
    }
    return 0;
}