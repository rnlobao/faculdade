#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "arvorebestrela.h"

//O metodo de pesquisa ira retornar 0 caso nao encontre o item, e 1 caso encontre
int pesquisaArvoreBEstrela(TipoRegistro *x, TipoApontadorB *ap, int *contComp, int *contTrans){
    int i;

    TipoApontadorB pag;
    pag = *ap;

    if((*ap)->Pt == Interna){
        i = 1;
        while((i < pag->UU.U0.ni) && (x->chave > pag->UU.U0.ri[i-1])){
            i++;
        }

        if(x->chave < pag->UU.U0.ri[i-1]){
            pesquisaArvoreBEstrela(x, &(pag->UU.U0.pi[i-1]), contComp, contTrans);
        }else{
            pesquisaArvoreBEstrela(x, &(pag->UU.U0.pi[i]), contComp, contTrans);
        }

        return 1;
    }

    i = 1;

    while((i < pag->UU.U1.ne) && (x->chave > pag->UU.U1.re[i-1].chave)){
        i++;
    }

    if(x->chave == pag->UU.U1.re[i-1].chave){
        *x = pag->UU.U1.re[i-1];

        printf("Achado\n");
        return 1;
    }else{
        return 0;
    }
}

void inicializaArvoreBEstrela(TipoApontadorB arvore){

    arvore = NULL;
}

//O metodo criaArvoreBEstrela eh responsavel por criar a arvore B* em memoria principal, tendo Ap como o ponteiro 
//para a raiz dessa arvore B*
void criaArvoreBEstrela(FILE *arqReg, TipoApontadorB *ap, int quantidade, int *contComp, int *contTrans){
    TipoRegistro reg;

    rewind(arqReg);
    inicializaArvoreBEstrela(*ap);

    for(int i = 0; i < quantidade; i++){

        fread(&reg, sizeof(TipoRegistro), 1, arqReg);
        
        (*contTrans) += 1;

        insereArvoreBEstrela(reg, ap, contComp, contTrans);
    }
}

void insereArvoreBEstrela(TipoRegistro Reg, TipoApontadorB *ap, int *contComp, int *contTrans){
    short cresceu;
    TipoRegistro RegRetorno;
    TipoPaginaB *ApRetorno;
    TipoPaginaB *ApTemp;
    
    //Insercao do primeiro item em uma arvore B* vazia
    //A primeira inserção é direto em um árvore externa e não é necessario inicialmente das chaves para pesquisa
    if(*ap == NULL){
        ApTemp = (TipoPaginaB*) malloc(sizeof(TipoPaginaB));
        ApTemp->Pt = Externa;
        ApTemp->UU.U1.ne = 1;
        ApTemp->UU.U1.re[0] = Reg;
        *ap = ApTemp;
        return;
    }

    //Insercao dos demais itens
    //A partir daqui ja é necessário a incesçao
    else{
        insrecuBEstrela(Reg, *ap, &cresceu, &RegRetorno, &ApRetorno, contComp, contTrans);
        //Se cresceu retorna verdadeiro, é porque a pagina raiz (que é uma pagina externa) esta cheia,
        //e criamos uma nova raiz com o valor do meio que ira subir, como na arvore B
        if (cresceu){
            ApTemp = (TipoPaginaB*) malloc(sizeof(TipoPaginaB));
            ApTemp->Pt = Interna;
            ApTemp->UU.U0.ni = 1; //elemento que subiu
            ApTemp->UU.U0.ri[0] = RegRetorno.chave; //Insiro apenas a chave, ja que é uma pagina interna
            ApTemp->UU.U0.pi[1] = ApRetorno; //Nova pagina criada junto com a antiga raiz
            ApTemp->UU.U0.pi[0] = *ap; // Antiga pagina raiz
            *ap = ApTemp;
        }
    }
}

void insrecuBEstrela(TipoRegistro Reg, TipoApontadorB ap, short *cresceu, TipoRegistro *RegRetorno, TipoApontadorB *ApRetorno, int *contComp, int *contTrans){
    long i = 1;
    long j;

    TipoApontadorB ApTemp;

    //Na pagina externa que esta apontada pelo ponteiro, eu vou apenas buscar sequencialmente a 
    //posição certa para assim inserir o registro COMPLETO 
    if(ap->Pt == Externa){
        (*contComp) += 1;

        //Aqui faço a pesquisa sequencial para encontrar a posição correta
        while(i < ap->UU.U1.ne && Reg.chave > ap->UU.U1.re[i-1].chave) {
            (*contComp) += 1;
            i++;
        }

        (*contComp) += 1;
        //Não podem ter registros repetidos. Por isso, caso o registro ja existir na pagina, retorno e finalizo o metodo
        if(Reg.chave == ap->UU.U1.re[i-1].chave){
            
            *cresceu = 0;
            return;
        }

        (*contComp) += 1;
        /*Aqui volto uma posição do i para inserirmos o elemento na posiçao exata caso a chave procurada seja menor 
        que a chave apontada para antes do i. Caso contrario apenas inserimos a o registro na posição que o i está */
        if(Reg.chave < ap->UU.U1.re[i-1].chave){
            i--;
        }

        //Se a pagina externa em que meu ponteiro esta apontando estiver cheia
        //terei que dividir a pagina em duas, onde os menores valores ficam na pagina antiga e 
        //os maiores valores ficam na nova pagina

        //Caso contrario apenas insiro diretamente

        //OBS: No caso da pagina folha da B*, não é necessário levar o filho do meio para pagina pai
        //Apenas coloco ele direto na primeira posiçao da nova pagina como um "emprestimo" 
        if(ap->UU.U1.ne < (2 * MM)) {
            *RegRetorno = Reg;

            /*inserção direta na pagina que o ponteiro principal aponta onde vou empurrando os outros elementos da pagina de 
            lugar para frente e coloco o elemento na posiçao correta*/
            insereNapaginaEstrela(ap, *RegRetorno, *ApRetorno, contComp, contTrans);
                                                                                
            *cresceu = 0;
            return;
        }

        //Criaçao de uma nova página
        ApTemp = (TipoPaginaB*) malloc(sizeof(TipoPaginaB));
        ApTemp->Pt = Externa;
        ApTemp->UU.U1.ne = 0;

        *RegRetorno = Reg; //RegRetorno recebe o item a ser inserido
        *ApRetorno = NULL; 

        //Aqui vejo se irei inserir o elemento na pagina antiga ou na pagina nova
        //Se i for menor que M + 1, coloco na pagina antiga e caso contrario coloco diretamente na pagina nova
        if(i < (M + 1)) {
            //Inserindo o registro com maior chave da pagina antiga na nova pagina para liberar espaço na pagina antiga
            insereNapaginaEstrela(ApTemp, ap->UU.U1.re[(2 * MM) - 1], *ApRetorno, contComp, contTrans);

            //Retiro da pagina antiga um dos elementos. Logo, reduzo o seu tamanho para liberar um espaço
            ap->UU.U1.ne--; 

            //Inserindo o registro (que queremos inserir) na pagina antiga na posiçao certa e mandando os 
            //os outro elementos para frente se ele estiver sendo inserido antes de algum registro
            insereNapaginaEstrela(ap, *RegRetorno, *ApRetorno, contComp, contTrans);
        }

        else {
            //Apenas insiro o registro (que estamos inserindo) na nova página na primeira posição
            insereNapaginaEstrela(ApTemp, *RegRetorno, *ApRetorno, contComp, contTrans);
        }

        //Inserindo o resto dos maiores registros da antiga pagina na nova pagina
        for (j = 1; j <= M; j++) {
            insereNapaginaEstrela(ApTemp, ap->UU.U1.re[(2 * MM) - j], *ApRetorno, contComp, contTrans);
        }
        
        ap->UU.U1.ne = M;
        *RegRetorno = ap->UU.U1.re[M];
        *ApRetorno = ApTemp;
        *cresceu = 1;
        return;
    }

    //Caso a pagina seja INTERNA
    //Aqui temos o mesmo processo de implementação de que uma arvore B padrão 
    else{
        (*contComp) += 1;
        //Aqui iremos fazer uma pesquisa dentro da nossa arvore para saber se o item ja se encontra na arvore
        while(i < ap->UU.U0.ni && Reg.chave > ap->UU.U0.ri[i-1]){
            (*contComp) += 1;
            i++;
        }

        (*contComp) += 1;
        /*Na nossa arvore B* não possui registros com chaves repetidas. Portanto, se é encontrada uma chave repetida,
        não inserimos e paramos a inserção*/
        if(Reg.chave == ap->UU.U0.ri[i-1]){
            *cresceu = 0;
            return;
        }

        (*contComp) += 1;
        //Entro nesse if caso meu item esteja na subarvore a esquerda
        if(Reg.chave < ap->UU.U0.ri[i-1]){
            i--;
        }
        
        /*Chamamos recursivamente o InsRecu ate encontrarmos a pagina folha onde iremos inserir o registro na arvore*/                
        insrecuBEstrela(Reg, ap->UU.U0.pi[i], cresceu, RegRetorno, ApRetorno, contComp, contTrans);

        /*Se cresceu for verdadeiro, iremos retornar falso por conta do '!'. Logo, 
        isso quer dizer que o nosso procedimento de inserção nao finalizou ainda*/
        if(!*cresceu)  
            return;

        //Caso entremos nesse if, a pagina que queremos inserir TEM ESPAÇO e inserimos nossa chave(apenas a chave) la
        //Caso contrario, sigo no meu codigo
        if(ap->UU.U0.ni < MM){
            //Entrando aqui, eu faço uma inserção em uma pagina interna, mandando os elementos dessa pagina para frente
            //e inserindo o elemento na posiçao exata
            insereNapaginaEstrela (ap, *RegRetorno, *ApRetorno, contComp, contTrans);

            *cresceu = 0;

            return;
        }
        
        /*Nesse caso, fazemos isso para caso quando a pagina que queremos inserir está CHEIA. 
        Quando a arvore esta cheia, temos que dividi-la em duas, ou seja, iremos criar 
        uma nova pagina*/
        ApTemp = (TipoPaginaB*) malloc(sizeof(TipoPaginaB));
        ApTemp->Pt = Interna;
        ApTemp->UU.U0.ni = 0;
        ApTemp->UU.U0.pi[0] = NULL;

        TipoRegistro Aux;

        //Esse if-else serve para determinar o que devemos fazer com o item que será inserido, ou seja,
        //se ele sera inserido na pagina ja existente ou na nova pagina e isso é determinado pelo i

        //O if libera um espaço na pagina anterior e coloca esse elemento retirado na nova pagina.
        //Em seguida, eu pego o elemento a ser inserido e o insiro na pagina ja existente
        if(i < M + 1){
            Aux.chave = ap->UU.U0.ri[MM-1];
            insereNapaginaEstrela(ApTemp, Aux, ap->UU.U0.pi[MM], contComp, contTrans);
            ap->UU.U0.ni--;
            insereNapaginaEstrela(ap, *RegRetorno, *ApRetorno, contComp, contTrans);
        }
        
        //Enquanto o else coloca direto o valor a ser inserido na nova pagina
        else{
            insereNapaginaEstrela(ApTemp, *RegRetorno, *ApRetorno, contComp, contTrans);
        }

        /*Esse for é usado para subir o item do "meio" da pagina antiga para pagina pai e fazer 
        ele apontar para a pagina nova*/
        //Além disso, manda o maior item da pagina antiga para pagina nova 
        for (j = (M + 2); j <= MM; j++) {
            Aux.chave = ap->UU.U0.ri[j - 1];
            insereNapaginaEstrela(ApTemp, Aux, ap->UU.U0.pi[j], contComp, contTrans);
        }

        ap->UU.U0.ni = M; //ja faz a pagina ter 4 itens apenas sem mesmo precisar excluir o itens dela 

        ApTemp->UU.U0.pi[0] = ap->UU.U0.pi[M+1];

        RegRetorno->chave = ap->UU.U0.ri[M];

        *ApRetorno = ApTemp;

        return;
    }
}

//Vamo encontrar onde iremos inserir o registro na pagina que foi passada empurrando os outros elementos para frente, 
//(sendo essa pagina ou uma pagina externa, ou uma pagina interna)
//OBS: Dependendo do que a pagina for, a inserção é diferente :
//     - Pagina interna insere apenas a chave do registro
//     - Pagina externa insere o registro completo
void insereNapaginaEstrela(TipoApontadorB ap, TipoRegistro Reg, TipoApontadorB apDir, int *contComp, int *contTrans){
    short naoAchouPosicao = 0;
    int k;

    //Caso a pagina seja externa (folha)
    if(ap->Pt == Externa){
        k = ap->UU.U1.ne;

        if(k > 0)
            naoAchouPosicao = 1;

        while(naoAchouPosicao){
            (*contComp) += 1;
            if (Reg.chave >= ap->UU.U1.re[k-1].chave){
                naoAchouPosicao = 0;
                break;
            }
            ap->UU.U1.re[k] = ap->UU.U1.re[k-1];

            k--;

            if(k < 1)
                naoAchouPosicao = 0;
        }
        ap->UU.U1.re[k] = Reg;
        ap->UU.U1.ne++;
    }

    //Caso a pagina seja interna
    else{
        k = ap->UU.U0.ni;

        if(k > 0){
            naoAchouPosicao = 1;
        }

        while(naoAchouPosicao){
            (*contComp) += 1;
            if (Reg.chave >= ap->UU.U0.ri[k - 1]){
                naoAchouPosicao = 0;
                break;
            }
            ap->UU.U0.ri[k] = ap->UU.U0.ri[k - 1];

            ap->UU.U0.pi[k + 1] = ap->UU.U0.pi[k];

            k--;

            if(k < 1)
                naoAchouPosicao = 0;
        }

        ap->UU.U0.ri[k] = Reg.chave;

        ap->UU.U0.pi[k + 1] = apDir;

        ap->UU.U0.ni++;
    }

    return;
}