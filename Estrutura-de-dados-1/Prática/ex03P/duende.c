#include "duende.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct duende {
  //preencher
};

struct time {
  //preencher
};

void lerQuantidade(int *qtd){
}
//Manter como especificado
TADduende *alocaDuendes(TADduende *D, int qtd){
}

//Manter como especificado
TADtime *alocaTimes(TADtime *T, int qtd){
}

//Manter como especificado
TADduende *desalocaDuendes(TADduende *D){
}

//Manter como especificado
TADtime *desalocaTimes(TADtime *T){
}

//Manter como especificado
void lerDuendes(TADduende *D, int qtd){
  int i;
  //ler nome e idade de cada duente
  //aproveitar para colocar o valor 0 no campo escalado
}

//Manter como especificado
void escalarTimes(TADduende *D, TADtime *T, int qtd){
  int i, indice;
  //completar o XXX
  for (i=0; i<XXX; i++)
  {
    indice = proximoMaisVelho(D, qtd);
    //marcar o duende do indice como escalado
    //a linha abaixo copia o nome do duende para a estrutura do time
    strcpy(T[i].lider, D[indice].nome);
    //copiar a idade
  }

  //repetir o laco acima, mas para o entregador
  //repetir o laco acima, mara para o piloto
}

int proximoMaisVelho(TADduende *D, int qtd){
  int indice;
  //determinar o indice do duende mais velho nao escalado ainda
  //variaveis adicionais podem ser criadas
  return indice;
}

//Manter como especificado
void printTimes(TADtime *T, int qtd){
}
