#include<stdio.h>

void lerOperacao(char *operacao){
    printf("Digite a letra: ");
    scanf("%c", operacao); //quando for ler um ponteiro no scanf nunca passe o &
}

int main()
{
    double M[12][12], resultado;
    char operacao;

    lerOperacao(&operacao);
    printf("%c foi a letra digitada", operacao);
    /*lerMatriz(M);
    resultado = somaMatriz(M);

    if(operacao == 'M')
      resultado = media(resultado);

    printResultado(resultado);*/

    return 0;//nao remova
}