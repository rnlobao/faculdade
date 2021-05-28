//Robson Novato Lobao 20.1.4018

#include <stdio.h>
int main()
{
    double M[12][12];//utilize esta matriz para ler os 144 numeros reais
    char O;
    scanf("%c", &O);
    double soma = 0;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            scanf("%lf", &M[i][j]);
        }
    }
    int ajuda = 0;
    
    for (int k = 0; k < 5; k++) {
        for (int l = k+1; l < 11-ajuda; l++) {
            soma += M[k][l]; 
        }
        ajuda++;
        
    }
    float media;
    if (O == 'M'){
        soma = soma/30;
        printf("%.1lf", soma);
    }

    else if (O == 'S') {
        printf("%.1lf", soma);
    }

    return 0;
}
