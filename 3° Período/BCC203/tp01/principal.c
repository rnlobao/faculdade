#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "arvoreb.h"
#include "contimpri.h"
#include "asi.h"
#include "arvore_binaria.h"
#include "arvorebestrela.h"

int main (int argc, const char *argv[]) {

    int metodo = atoi(argv[1]);
    long int quantidade = atoi (argv[2]);
    int situ = atoi (argv[3]);
    int chave = atoi (argv[4]);
    int argOpc = 0;

    int contComp = 0; 
    int contTrans = 0; 
    double tPreProce = 0.0; 
    double tPesquisa = 0.0; 
    double tTotal = 0.0;

    clock_t tempo_pesquisa;
    clock_t tempo_procesasmento;

    char nome[6];

    if (quantidade <= 0){
        printf ("ERRO: o arquivo deve ter no minimo 1 registro\n");
        exit(1);

    }

    if (argc < 5){
        printf("ERRO: Poucos comandos digitados...\n");
        printf("Os argumentos sao: pesquisa <metodo> <quantidade> <situacao> <chave> [-P] \n");
        printf ("OBS: [-P] é opcional\n");
        exit(1);
    }

    if (argc > 6){
        printf("ERRO: Muitos comandos digitados...\n");
        printf("O formato de execucao é: pesquisa <metodo> <quantidade> <situacao> <chave> [-P]\n");
        printf ("OBS: [-P] é opcional\n");
        exit(1);
    }

    if (metodo < 1 || metodo > 4){

        printf ("ERRO: Argumento (método) inválido!\n");
        printf ("Metodo deve ser digitado como '1' para acesso sequencial indexado, '2' para arvore binaria, '3' para arvore B e '4' para arvore B*\n");
        exit(1);
    }

    if (situ < 1 || situ > 3){
        printf("ERRO: Argumento (situação) inválido!\n");
        printf("Situação deve ser digitada como '1' para arquivo arquivo ordenado ascendentemente , '2' para arquivo ordenado descendentemente e '3' para arquivo desordenado aleatoriamente\n");
        exit(1);

    }

     /*vemos se foi ou nao digitado o argumento opcional. Se sim, ele passa a ser 1 (verdadeiro), para mais na frente
    realizarmos a impressao de todas as chaves do arquivo*/
    if(argc == 6){
        if(strcmp(argv[5],"[-P]") == 0)
            argOpc = 1;
        else{
            printf("ERRO: argumento opcional digitado errado!\n.");
            printf("Maneira correta é [-P]\n");
            exit(1);
        }
    }

    FILE *arqReg = NULL;

    //vê qual arquivo iremos pegar
    switch (situ) {
        case 1:
            if(quantidade != 1000000){

                strcpy(nome,"cre_a");
            }else{
                quantidade = 250000;
                if(chave <= 250000){
                    strcpy(nome,"cre_a");
                }else if((chave > 250000) && (chave <= 500000)){
                    strcpy(nome,"cre_b");
                }else if((chave > 500000) && (chave <= 750000)){
                    strcpy(nome,"cre_c");
                }else{
                    strcpy(nome,"cre_d");
                }
            }

            if((arqReg = fopen(nome, "rb")) == NULL){
                printf ("ERRO na abertura do arquivo \n");
                return 0;
            }
            break;

        case 2: 
            if(quantidade != 1000000){
                strcpy(nome,"dec_a");
            }else{
                quantidade = 250000;
                if(chave <= 250000){
                    strcpy(nome,"dec_d");
                }else if((chave > 250000) && (chave <= 500000)){
                    strcpy(nome,"dec_c");
                }else if((chave > 500000) && (chave <= 750000)){
                    strcpy(nome,"dec_b");
                }else{
                    strcpy(nome,"dec_a");
                }
            }

            if((arqReg = fopen(nome, "rb")) == NULL){
                printf ("ERRO na abertura do arquivo \n");
                return 0;

            }
            break;

        case 3: 
            if(quantidade != 1000000){
                strcpy(nome,"ale_a");
            }else{
                quantidade = 250000;
                if(chave <= 250000){
                    strcpy(nome,"ale_a");
                }else if((chave > 250000) && (chave <= 500000)){
                    strcpy(nome,"ale_b");
                }else if((chave > 500000) && (chave <= 750000)){
                    strcpy(nome,"ale_c");
                }else{
                    strcpy(nome,"ale_d");
                }
            }

            if((arqReg = fopen(nome, "rb")) == NULL){
                printf ("ERRO na abertura do arquivo \n");
                return 0;
            }
            break;
    }

    TipoRegistro r, b;

    r.chave = chave;
    b.chave = chave;

    Registro temp;

    TipoApontador ap = NULL;

    TipoApontadorB apb = NULL;

    int flag = 0;

    //Identifica qual método de pesquisa será utilizado
    switch (metodo){
        case 1: //Acesso sequencial indexado

            tempo_procesasmento = clock();

            r = pesquisaSequencialIndexada(&b, quantidade, arqReg, situ, &contComp, &contTrans, &flag);

            tempo_procesasmento = clock() - tempo_procesasmento;

            tempo_pesquisa = clock();

            if(flag){
                printf("Registro encontrado \n");
                imprimeRegistro(r);
            }else{
                printf("Não há registro com essa chave...\n");
            }

            tempo_pesquisa = clock() - tempo_pesquisa;
                
            break;

        case 2: //Arvore binaria  
             //1º construção da arvore Binaria 
            //CONTAR TEMPO DE PRE PROCESSAMENTO

            tempo_procesasmento = clock();

            arvoreBinaria(nome, quantidade, &contComp, &contTrans);

            tempo_procesasmento = clock() - tempo_procesasmento;
            
            //2º pesquisa da chave desejada na arvore Binaria
            //CONTAR TEMPO DE PESQUISA 

            tempo_pesquisa = clock();

            temp = pesquisaArvoreBinaria("arvore_binaria", chave, nome, &contComp, &contTrans);

            if (temp.chave != -1){
                //printf("Registro encontrado!\n");

                printf ("DADOS:\n");
                printf ("Chave:  %d\n", temp.chave);
                printf ("Dado 1: %ld\n", temp.dado1);
                printf ("Dado 2: %s\n", temp.dado2);
                printf ("Dado 3: %s\n", temp.dado3);

            }else {
                printf("Não há registro com essa chave...\n");
            } 

            tempo_pesquisa = clock() - tempo_pesquisa;
            break;

        case 3: //Árvore B
             //1º construção da arvore B 
            //CONTAR TEMPO DE PRE PROCESSAMENTO

            tempo_procesasmento = clock();

            criaArvoreB(arqReg, &ap, quantidade, &contComp, &contTrans);

            tempo_procesasmento = clock() - tempo_procesasmento;
            
            
            //2º pesquisa da chave desejada na arvore B
            //CONTAR TEMPO DE PESQUISA 

            tempo_pesquisa = clock();

            if (pesquisaArvoreB(&r, ap, &contComp, &contTrans)){
                //printf("Registro encontrado!\n");
                imprimeRegistro(r);

            }  

            else {
                //printf("Não há registro com essa chave...\n");
            }
            tempo_pesquisa = clock() - tempo_pesquisa;
            break;
        case 4: //Arvore B*
            //1º construção da arvore B* 
            //CONTAR TEMPO DE PRE PROCESSAMENTO
            //iniciarTempoPreProcessamento(&InicioPreProcessamento);

            tempo_procesasmento = clock();

            criaArvoreBEstrela(arqReg, &apb, quantidade, &contComp, &contTrans);

            tempo_procesasmento = clock() - tempo_procesasmento;
            
            //2º pesquisa da chave desejada na arvore B*
            //CONTAR TEMPO DE PESQUISA 
            //iniciarTempoPesquisa(&InicioPesquisa);

            tempo_pesquisa = clock();

            if (pesquisaArvoreBEstrela(&r, &apb, &contComp, &contTrans)){
                //printf("Registro encontrado!\n");
                imprimeRegistro(r);

            }  

            else {
                printf("Não há registro com essa chave...\n");
            }
            tempo_pesquisa = clock() - tempo_pesquisa;
            break;
            
    } 

    if(argOpc == 1){
        imprimeChaves(arqReg);
    }

    tPreProce = ((double)tempo_procesasmento)/1000.0;
    //printf("%.2lf", tPreProce/1000.0);

    tPesquisa = (((double)tempo_pesquisa)/1000.0);
    //printf("%.2lf", tPesquisa/1000.0);

    tTotal = (tPesquisa + tPreProce)/1000.0;

    imprimirExperimento (contComp, contTrans, tPreProce, tPesquisa, tTotal);

    fclose(arqReg);
    
    return 0;
}



