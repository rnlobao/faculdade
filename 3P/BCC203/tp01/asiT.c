#include <stdio.h>

#define ITENSPAGINA 4
#define MAXTABELA 100

typedef struct {
    int posicao;
    int chave;
} tipoindice;

typedef struct {
    char titulo[31]; int chave; float preco;
} tipoitem;

int pesquisaASI(FILE* arq, int chave, int tam){

    tipoindice tabela[MAXTABELA];
    tipoitem x, temp; 
    int pos, cont, ind = 0;


    cont = 0; pos = 0;
    while (ind < tam){
        fread(&x, sizeof(x), 1, arq);
        cont++;
        if (cont%ITENSPAGINA == 1) {
            tabela[pos].chave = x.chave;
            tabela[pos].posicao = pos+1;
            pos++;
        }
        ind++;
    } 

    temp.chave = chave;
    
    // ativa a função de pesquisa
    if (pesquisa (tabela, pos, &temp, arq))
        printf ("Livro %s (codigo %d) foi localizado",x.titulo, x.chave);
    else
        printf ("Livro de código %d nao foi localizado",x.chave);

    return 0;

}