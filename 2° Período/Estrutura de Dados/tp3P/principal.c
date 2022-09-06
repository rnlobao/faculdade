#include <stdio.h>
#include <stdlib.h>
#include "buscabinaria.h"

int main() {
    int n;
    double a, remove[200000], metrosquadradosremovidos, maior = 0;
    scanf("%d", &n);
    scanf("%lf", &a);
    
    while((n != 0) && (a != 0)) {
        metrosquadradosremovidos = 0;

        for(int i = 0; i < n; i++) {
            scanf("%lf", &(remove[i]));
            metrosquadradosremovidos = remove[i] + metrosquadradosremovidos;

            if(remove[i] > maior) {
                maior = remove[i];
            }
        }
        PrintResultado(metrosquadradosremovidos, a, remove, n, maior);
        scanf("%d", &n);
        scanf("%lf", &a);
    }
    return 0;
}