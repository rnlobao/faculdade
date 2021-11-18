#ifndef arvore_binaria_h
#define arvore_binaria_h

typedef struct {
    int chave;
    long int dado1;
    char dado2[1000];
    char dado3[5000];
}Registro;

typedef struct{
    int chave;
    long int dir, esq, posicao;
}Indice;

void arvoreBinaria(char *nome, int tam, int *comp, int *transf);

void add(FILE *arquivo, Indice indice, int flag, Indice filho);

void adicionarIndice(long int seek, FILE *arquivo, Indice item, int *comp, int *transf);

Registro pesquisaArvoreBinaria(char *nome, int chave, char *arq, int *comp, int *transf);

long int pesquisa(long int seek, FILE *arquivo, Indice item, int *comp, int *transf);

#endif