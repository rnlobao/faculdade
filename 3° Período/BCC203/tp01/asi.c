#include <stdio.h>
#include <stdlib.h>

#include "asi.h"

int pesquisaSequencial(tipoIndice tab[] , int quantidade, TipoRegistro* item , FILE* arqReg , int situ,int *comp ,int *trans){
    TipoRegistro pagina[ITENSPAGINA];

    int i, quantitens;
    long desloc;

    // procura pela página onde o item pode se encontrar

    i = 0;

    // Para caso a ordenação seja aleatória

    if (situ == 1){
        while (i < quantidade && tab[i].chave <= item->chave){
            (*comp) += 1;
            i++;
        }
    }
    else if (situ == 2){
        while(i < quantidade && tab[i].chave >= item->chave){
            (*comp) += 1;
            i++;
        }
    }
    
    // se i = 0 , o arquivo pode estar desordenado ou caso a chave seja menor
    // que a primeira chave, o item não existe no arquivo

   if(i == 0){
       return 0;
    }
    else{
        if(i < quantidade){
            quantitens = ITENSPAGINA; // a ultima pagina pode não estar completa
        }
        else{
            fseek(arqReg , 0 , SEEK_END);
            quantitens = ( ftell(arqReg) / sizeof(TipoRegistro)) %ITENSPAGINA;

            //  TESTE caso a pagina esteja completa
            /*if(quantitens == 0){
                quantitens = ITENSPAGINA;
            }*/
        }
    }   

    // lê a página desejada do arquivo

    desloc = (tab[i-1].posicao-1)*ITENSPAGINA*sizeof(TipoRegistro);
    fseek(arqReg, desloc , SEEK_SET);
    fread(&pagina , sizeof(TipoRegistro) , quantitens , arqReg);
    (*trans) += 1;

    // Pesquisa sequencial na pagina lida

    for( i = 0 ; i < quantitens ; i++){
        (*comp) += 1;
        if(pagina[i].chave == item->chave){
            *item = pagina[i];
            return 1;
        }
    }

    return 0;
}

TipoRegistro pesquisaSequencialIndexada(TipoRegistro *r,int tam, FILE* arq , int situ,int *comp ,int *trans , int *flag ){

    tipoIndice tabela[MAXTABELA];
    TipoRegistro x; 
    int pos, cont, ind = 0;

    cont = 0; pos = 0;
    while (ind < tam){
        fread(&x, sizeof(x), 1, arq);
        (*trans) += 1;
        cont++;
        if (cont%ITENSPAGINA == 1) {
            tabela[pos].chave = x.chave;
            tabela[pos].posicao = pos+1;
            pos++;
        }
        ind++;
    } 

    rewind(arq);

    x.chave = r->chave;
    
    // ativa a função de pesquisa
    if (pesquisaSequencial(tabela, pos, &x, arq,situ, comp, trans)){
        (*flag) = 1;
    }else{
        (*flag) = 0;
    }
    return x;

}