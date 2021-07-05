#include "lista.h"
#include<stdio.h>
#include<string.h>
//tamanho maximo de uma string
#define MAX_STR 1200
int main()
{
    TLista original, nova;
    char str[MAX_STR], str2[MAX_STR], str3[20];
    char* token;
    TItem x;

    //iniciar listas

    //le a primeira linha
    fgets (str, MAX_STR, stdin);
    //remove o \n incluido pelo fgets
    str[strcspn(str, "\n")] = 0;

    //tokenizacao da string original, divide em strings delimitadas por espaco em branco
    token = strtok(str, " ");

    while (token != NULL) {
      strcpy(x.nome, token);
      //inserir o item na lista adequada
      token = strtok(NULL, " ");
    }

    //ler a segunda linha, igual a primeira e preencher a segunda lista

    //ler a terceira linha, usando apenas scanf

    //dependendo se ha indicacao ou nao, manipular as listas de acordo

    //imprimir a lista final

    //ao final as duas listas estarao unificadas, entao basta esvaziar a original

    return 0;//nao remova
}
