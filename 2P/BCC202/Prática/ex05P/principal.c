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
    TLista_Inicia(&original);
    TLista_Inicia(&nova);

    //le a primeira linha
    fgets (str, MAX_STR, stdin);
    //remove o \n incluido pelo fgets
    str[strcspn(str, "\n")] = 0;

    //tokenizacao da string original, divide em strings delimitadas por espaco em branco
    token = strtok(str, " ");

    while (token != NULL) {
      strcpy(x.nome, token);
      //inserir o item na lista adequada
      TLista_InsereFinal(&original, x);
      token = strtok(NULL, " ");
    }




    //ler a segunda linha, igual a primeira e preencher a segunda lista
    fgets (str2, MAX_STR, stdin);
    //remove o \n incluido pelo fgets
    str2[strcspn(str2, "\n")] = 0;

    //tokenizacao da string original, divide em strings delimitadas por espaco em branco
    token = strtok(str2, " ");

    while (token != NULL) {
      strcpy(x.nome, token);
      //inserir o item na lista adequada
      TLista_InsereFinal(&nova, x);
      token = strtok(NULL, " ");
    }


    //ler a terceira linha, usando apenas scanf
    scanf(" %s", str3);


    //dependendo se ha indicacao ou nao, manipular as listas de acordo

    if (strcmp(str3, "nao") == 0) {
      TLista_append(&original, &nova);
    }

    else {
      TLista_include(&original, &nova, str3);
    }
    //imprimir a lista final
    TLista_Imprime(&original);
    //ao final as duas listas estarao unificadas, entao basta esvaziar a original
    TLista_Esvazia(&original);
    return 0;//nao remova
}
