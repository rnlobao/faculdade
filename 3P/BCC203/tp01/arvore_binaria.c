#include <stdio.h>

#include "arvore_binaria.h"

//Função que adiciona um item ao arquivo de forma recursiva
void adicionarIndice(long int seek, FILE *arquivo, Indice item, int *comp, int *transf){

    Indice indice;
    fseek(arquivo, seek * sizeof(Indice), SEEK_SET);
    fread(&indice, sizeof(Indice), 1, arquivo);//le o primeiro item
    (*transf) += 1;

    //e depois compara com a chave pesquisada
    if(item.chave > indice.chave){//se for maior entra aqui
        (*comp) += 1;//contadores, apenas ignore
        if(indice.dir == -1){//verifica se é uma posição valida para inserção
            add(arquivo,indice, 1, item);//caso seja, adiciona
            return;
        }
        //caso nao, vai recursivamnte pelo arquivo ate o filho da direita
        adicionarIndice(indice.dir, arquivo, item, comp, transf);

    }else if(item.chave < indice.chave){//se for menor entra aqui
        (*comp) += 1;//contadores, apenas ignore
        if(indice.esq == -1){//verifica se é uma posição valida para inserção
            add(arquivo,indice, 0, item);//caso seja, adiciona
            return;
        }

        //caso nao, vai recursivamnte pelo arquivo ate o filho da esquerda
        adicionarIndice(indice.esq, arquivo, item, comp, transf);
    }else{ //caso chegue aqui, é porque o item ja existe
        return;
    }

    return;

}

//função que atualiza o arquivo e adiciona o filho
void add(FILE *arquivo, Indice indice, int flag, Indice filho){

    long int tellpai = (ftell(arquivo) - sizeof(Indice));//pega a posição do pai

    fseek(arquivo, 0, SEEK_END);
    long int tellfilho = ftell(arquivo);//pega a posição do filho

    fwrite(&filho, sizeof(Indice), 1, arquivo);//adiciona o filho

    if(flag == 1){//verifica se é da direita ou da esquerda
        indice.dir = tellfilho/sizeof(Indice);
    }else{
        indice.esq = tellfilho/sizeof(Indice);
    }

    //atualiza o pai com o novo endereço do filho
    fseek(arquivo, tellpai, SEEK_SET);
    fwrite(&indice, sizeof(Indice), 1, arquivo);
}

//Função que gerencia a criação da arvore binaria
void arvoreBinaria(char *nome, int tam, int *comp, int *transf){

    FILE *arquivo = fopen(nome, "rb");//abre o arquivo texto
    if(arquivo == NULL){
        printf("ERRO NA ABERTURA ARQUIVO ARVORE BINARIA \n");
        return;
    }

    char nome_arvore[] = "arvore_binaria";
    FILE *arvore = fopen(nome_arvore, "wb");//abre o arquivo da arvore
    if(arvore == NULL){
        printf("ERRO NA CRIAÇÃO DO ARQUIVO DA ARVORE BINARIA \n");
        return;
    }
    
    Indice aux; //auxiliares
    Registro temp;

    //faz uma primeira leitura e escrita para criar o arquivo, e apagar algum velho
    aux.posicao = ftell(arvore);
    fread(&temp, sizeof(Registro), 1, arquivo);//le
    aux.chave = temp.chave;
    aux.dir = aux.esq = -1;
    (*transf) += 1;//contadores, apenas ignore

    //escreve a raiz da arvore
    fwrite(&aux, sizeof(Indice), 1, arvore);

    //reabre o arquivo para saida e sobreescrever dados
    arvore = freopen(nome_arvore, "r+b", arvore);

    int i;//loop que adiciona cada item
    for(i = 1; i < tam; i++){
        aux.posicao = ftell(arquivo);
        fread(&temp, sizeof(Registro), 1, arquivo);//le do arquivo
        aux.chave = temp.chave;
        aux.dir = aux.esq = -1;
        (*transf) += 1;//contadores, apenas ignore

        adicionarIndice(0, arvore, aux, comp, transf);//adiciona na arvore
    }

    fclose(arvore);//fecha os FILE
    fclose(arquivo);
}

Registro pesquisaArvoreBinaria(char *nome, int chave, char *arq, int *comp, int *transf){

    Registro t;         //
    t.chave = -1;       //
    t.dado1 = -1;       //
    t.dado2[0] = 'z';   // Infelizmente nao tinha uma forma bonita de fazer isso
    t.dado2[1] = '\0';  //
    t.dado3[0] = 'z';   //
    t.dado3[1] = '\0';  //


    FILE *arvore = fopen(nome, "rb");//abre o arquivo da arvore
    if(arvore == NULL){
        printf("ERRO NA ABERTURA DO ARQUIVO DA ARVORE BINARIA \n");
        return t;
    }

    Indice temp;//auxiliares
    temp.chave = chave;

    //efetua e pasquisa e retorna a posição do arquivo
    long int seek = pesquisa(0, arvore, temp, comp, transf);

    //se for -1, arquivo nao exixte
    if(seek == -1){
        return t;
    }

    //abre o arquivo pra poder imprimir o registro
    FILE *arquivo = fopen(arq, "rb");
    if(arquivo == NULL){
        printf("ERRO NA PESQUISA\n");
        return t;
    }

    //Le a aloca ele no registro que vai ser retornado
    fseek(arquivo,seek, SEEK_SET);
    fread(&t, sizeof(Registro), 1, arquivo);
    (*transf) += 1;

    fclose(arquivo);//fecha os FILE
    fclose(arvore);

    return t;//retorna o registro encontrado

}

//função que pesquisa por um item, e retorna a posição do item no arquivo
long int pesquisa(long int seek, FILE *arquivo, Indice item, int *comp, int *transf){

    Indice indice;
    //abre o arquivo na posição do pai
    fseek(arquivo, (int)seek * sizeof(Indice), SEEK_SET);
    fread(&indice, sizeof(Indice), 1, arquivo);
    (*transf) += 1;

    //verifica se o item de pesquisa é maior--
    if(item.chave > indice.chave){
        (*comp) += 1;
        if(indice.dir == -1){//se chegar a um endereço nulo, retorna falha
            return -1;
        }
        //se tiver um endereço, vai recursivamnte ate ele
        return pesquisa(indice.dir, arquivo, item, comp, transf);
    //--ou menor
    }else if(item.chave < indice.chave){
        (*comp) += 1;
        if(indice.esq == -1){//se chegar a um endereço nulo, retorna falha
            return -1;
        }
        //se tiver um endereço, vai recursivamnte ate ele
        return pesquisa(indice.esq, arquivo, item, comp, transf);
    }else{//se nao for maior ou menor, é igual
        return indice.posicao;//retorna a posição do item
    }

}