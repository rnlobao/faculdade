#include "duende.h"
#include<stdio.h>

int main()
{
    int qtd;
    TADduende *D;
    TADtime *T;

    lerQuantidade(&qtd);
    D = alocaDuendes(D, qtd);
    T = alocaTimes(T, qtd/3);
    lerDuendes(D, qtd);
    escalarTimes(D, T, qtd);
    printTimes(T, qtd/3);
    D = desalocaDuendes(D);
    T = desalocaTimes(T);

    return 0;//nao remova
}
