#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "contimpri.h"

void imprimeRegistro(TipoRegistro registro){

    //printf ("DADOS:\n");
    printf ("Chave:  %ld\n", registro.chave);
    /*printf ("Dado 1: %ld\n", registro.dado1);
    printf ("Dado 2: %s\n", registro.dado2);
    printf ("Dado 3: %s\n", registro.dado3);*/

}

//Imprime todasa as chaves de pesquisa do arquivo
void imprimeChaves(FILE *arq){
    TipoRegistro reg;

    int contChave = 1;

    rewind(arq);

    while(fread(&reg, sizeof (TipoRegistro), 1, arq) == 1){

        printf("%dº Chave: %ld\n", contChave, reg.chave);
        contChave++;
    }

    rewind(arq);
}

//Imprime os valores dos contadores de transferencias e o tempo de execução tanto da pesquisa quanto do pre-processamento
//do metodo utilizado
void imprimirExperimento(int contComp, int contTrans, double tPreProce, double tPesquisa, double tTotal){
    //printf("EXPERIMENTO:\n");
    printf("transferencias: %d\n", contTrans);
    printf("comparacoes: %d\n", contComp);
    //printf("Tempo gasto no pre-processamento (em milissegundos): %lf\n", tPreProce);
    //printf("Tempo gasto na pesquisa (em milissegundos): %lf\n", tPesquisa);
    printf("Tempo total: %.3lf s\n", tTotal);
}

//Inicia todos os contadores com 0 para evitar lixo de memoria
void inicializaContadores(int *contComp, int *contTrans, double *tPreProce, double *tPesquisa, double *tTotal) {
    contComp = 0;

    contTrans = 0;

    tPreProce = 0;

    tPesquisa = 0;

    tTotal = 0;
}

//Faz a contagem onde iniciou a execuçao do pre-precessamento
void iniciarTempoPreProcessamento(clock_t *InicioPreProcessamento){
    *InicioPreProcessamento = clock();
}

//Faz a contagem onde finalizou a execuçao do pre-precessamento
void finalizarTempoPreProcessamento(clock_t *FinalPreProcessamento){
    *FinalPreProcessamento = clock();
}

//Faz a contagem onde iniciou a execuçao da pesquisa
void iniciarTempoPesquisa(clock_t *InicioPesquisa){
    (*InicioPesquisa) = clock();
}

//Faz a contagem onde finalizou a execuçao da pesquisa 
void finalizarTempoPesquisa(clock_t *FinalPesquisa) {
    *FinalPesquisa = clock();
}

//Calcula o tempo total gasto no preprocessamento e guarda uma variavel 
void calcularTempoPreProcessamento(clock_t InicioPreProcessamento, clock_t FinalPreProcessamento, double *tPreProce){
    *tPreProce = (FinalPreProcessamento - InicioPreProcessamento) * 1000.0 / CLOCKS_PER_SEC; // nao sei se ta certo
} 

//Calcula o tempo total gasto na pesquisa e guarda uma variavel 
void calcularTempoPesquisa(clock_t InicioPesquisa, clock_t FinalPesquisa, double *tPesquisa){
    *tPesquisa = (FinalPesquisa - InicioPesquisa) * 1000.0 / CLOCKS_PER_SEC; // nao sei se ta certo
}
