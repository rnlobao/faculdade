#include "fib.h"
#include<stdio.h>

int main()
{
    //adicionar variaveis conforme necessidade
    TADfib f;
    //fazer a leitura do numero de casos de teste
    int n;
    scanf("%d", &n);
    //ler o caso de teste e processar antes de ler o proximo
    for (int k = 0; k < n; k++) {
        f.chamadas = -1;
        scanf("%d", &f.i);
        f.resultado = fibonacci(f.i, &f);
        printf("fib(%d) = %ld chamadas = %ld\n", f.i, f.chamadas, f.resultado);
    }
    return 0;
}
