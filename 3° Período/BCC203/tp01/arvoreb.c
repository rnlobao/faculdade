#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arvoreb.h"


void inicializaArvoreB (TipoApontador arvore){
    arvore = NULL;

}

void criaArvoreB(FILE* arqReg, TipoApontador *ap, int quantidade, int *contComp, int *contTrans){
    TipoRegistro reg;

    rewind(arqReg);
    inicializaArvoreB(*ap);

    for(int i = 0; i < quantidade; i++){

        fread(&reg, sizeof(TipoRegistro), 1, arqReg);
        
        (*contTrans) += 1;

        insereArvoreB(reg, ap, contComp, contTrans);
    }
}

int pesquisaArvoreB (TipoRegistro *x, TipoApontador ap, int *contComp, int *contTrans){

    long i = 1;

    if (ap == NULL){

        return 0; // caso retorne 0, o registro que queremos nao esta presente na arvore
    }

    (*contComp) += 1;
    while ((i < ap->n) && (x->chave > ap->r[i - 1].chave)) {/*Irei pesquisar dentro de uma pagina para encontrar o intervalo
                                                          onde se encontra o item desejado*/
        (*contComp) += 1;                                                 
        i++;
    }

    (*contComp) += 1;
    if (x->chave == ap->r[i - 1].chave){   /*Se o item desejado ja estiver nessa pagina, 
                                          retornamos que a pesquisa foi realizada com sucesso (return 1)*/                                 
        *x = ap->r[i - 1]; //veja que retornamos todo o registro e nao apenas a chave
        return 1;
    }

    //Caso contrario iremos pesquisar o item na subarvore à esquerda ou na subarvore à direita: 
    (*contComp) += 1;
    if(x->chave < ap->r[i - 1].chave) 
        return pesquisaArvoreB(x, ap->p[i - 1], contComp, contTrans); //Chamo recursivamente para esquerda se a chave desejada for menor que a chave da arvore

    else 
        return pesquisaArvoreB(x, ap->p[i], contComp, contTrans); //Chamo recursivamente para direita se a chave desejada for maior que a chave da arvore

    return 0;   
}

//Vamos encontrar onde inserir o registro na arvore para monta-la
void insereArvoreB(TipoRegistro Reg, TipoApontador *ap, int *contComp, int *contTrans) {

    short cresceu;

    TipoRegistro regRetorno;
    TipoPagina *apRetorno;
    TipoPagina *apTemp;
    
    
    InsRecu(Reg, *ap, &cresceu, &regRetorno, &apRetorno, contComp, contTrans); // metodo recursivo que controla todo o processo de inserção

    /*Se entramos nesse if, quer dizer que a arvore vai precisar crescer para cima da raiz,
    já que a raiz ficou cheia e assim criaremos uma nova raiz*/
    if(cresceu){  
        apTemp = (TipoPagina*) malloc (sizeof(TipoPagina));
        apTemp->n = 1;
        apTemp->r[0] = regRetorno;
        apTemp->p[1] = apRetorno;
        apTemp->p[0] = *ap; 
        *ap = apTemp;
    }
}

// metodo recursivo que controla todo o processo de inserção
void InsRecu (TipoRegistro Reg, TipoApontador ap, short *cresceu, TipoRegistro *regRetorno, TipoApontador *apRetorno, int *contComp, int *contTrans){

    long i = 1;  // Veremo que esse i será importante pra nos dizer onde iremos inserir o item
    long j;

    TipoApontador apTemp;

    /*Quando chegamos em um ponteiro NULL é porque chegamos em uma pagina folha ou se a arvore é vazia. Portanto,
    iremos inserir o item naquela posição ou criar uma pagina raiz, respectivamente*/
    if (ap == NULL){

        *cresceu = 1;

        (*regRetorno) = Reg;

        (*apRetorno) = NULL;

        return;
    }

    (*contComp) += 1;
    //Aqui iremos fazer uma pesquisa dentro da nossa arvore para saber se o item ja se encontra na arvore
    while ((i < ap->n) && (Reg.chave > ap->r[i - 1].chave)){
        (*contComp) += 1;
        i++;

    }

    (*contComp) += 1;
    /*Na nossa arvore B não possui registros com chaves repetidas. Portanto, se é encontrada uma chave repetida,
    não inserimos e paramos a inserção*/
    if (Reg.chave == ap->r[i - 1].chave){
        
        *cresceu = 0;

        return;
    }
    
    (*contComp) += 1;
    //Entro nesse if caso meu item esteja na subarvore a esquerda
    if(Reg.chave < ap->r[i - 1].chave){
        i--;
    }

    InsRecu(Reg, ap->p[i], cresceu, regRetorno, apRetorno, contComp, contTrans); /*chamamos recursivamente o InsRecu ate encontrarmos a posiçao 
                                                            onde iremos inserir o registro na arvore*/

    if(!*cresceu){  /*Se cresceu for verdadeiro, iremos retornar falso por conta do '!'. Logo, 
                    isso quer dizer que o nosso procedimento de inserção nao finalizou ainda*/
        return;
    }
    
    // Caso entremos nesse if, a pagina que queremos inserir o registro TEM ESPAÇO e inserimos nosso item la
    // Caso contrario, sigo no meu codigo
    if (ap->n < MM){  
        InsereNaPagina(ap, *regRetorno, *apRetorno, contComp, contTrans);

        *cresceu = 0;
        return;
    }
    
    /*Nesse caso, fazemos isso para caso quando a pagina que queremos inserir está CHEIA. 
    Quando a arvore esta cheia, temos que dividi-la em duas, ou seja, iremos criar 
    uma nova pagina*/
    apTemp = (TipoApontador) malloc(sizeof(TipoPagina)); //Criação de uma nova pagina
    apTemp->n = 0;
    apTemp->p[0] = NULL;

    //Esse if-else serve para determinar o que devemos fazer com o item que será inserido, ou seja,
    //se ele sera inserido na pagina ja existente ou na nova pagina e isso é determinado pelo i

    //O if libera um espaço na pagina anterior e coloca esse elemento retirado na nova pagina.
    //Em seguida, eu pego o elemento a ser inserido e o insiro na pagina ja existente
    if (i < (M + 1)){
        InsereNaPagina (apTemp, ap->r[MM - 1], ap->p[MM], contComp, contTrans);
        ap->n--;
        InsereNaPagina (ap, *regRetorno, *apRetorno, contComp, contTrans);
    }
    
    //Enquanto o else coloca direto o valor a ser inserido na nova pagina
    else 
        InsereNaPagina (apTemp, *regRetorno, *apRetorno, contComp, contTrans);


    /*Esse for é usado para subir o item do "meio" da pagina antiga para pagina pai e fazer 
    ele apontar para a pagina nova*/
    //Além disso, manda o maior item da pagina antiga para pagina nova 
    for (j = M + 2; j <= MM; j++){
        InsereNaPagina(apTemp, ap->r[j - 1], ap->p[j], contComp, contTrans);
    }

        ap->n = M; //ja faz a pagina ter 2 itens apenas sem mesmo precisar excluir o itens dela 

        apTemp->p[0] = ap->p[M + 1];

        *regRetorno = ap->r[M];

        *apRetorno = apTemp;
    
}

// Vamo encontrar onde iremos inserir o registro na pagina que foi passada
void InsereNaPagina (TipoApontador ap, TipoRegistro Reg, TipoApontador apDir, int *contComp, int *contTrans){

    short NaoAchouPosi = 0;
    int k;
    
    k = ap->n;

    if (k > 0){
        NaoAchouPosi = 1;
    }

    while (NaoAchouPosi){
        (*contComp) += 1;
        if (Reg.chave >= ap->r[k - 1].chave){
            NaoAchouPosi = 0;
            break;
        }
        ap->r[k] = ap->r[k - 1];
        ap->p[k + 1] = ap->p[k];
        k--;

        if (k < 1){
            NaoAchouPosi = 0;
        }
    }

    //essa ultimas 3 linhas "empurram" um elemento pra frente para desocupar uma posiçao para um elemento que irá entrar
    ap->r[k] = Reg;

    ap->p[k + 1] = apDir;

    ap->n++;
}