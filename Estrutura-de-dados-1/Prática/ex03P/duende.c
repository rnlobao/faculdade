#include "duende.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct duende {
  char nome[20];
  int idade;
  int escalado;
};

struct time {
  char nomedolider[20];
  int idadedolider;

  char nomedoentregador[20];
  int idadedoentregador;

  char nomedopiloto[20];
  int idadedopiloto;
};

void lerQuantidade(int *qtd){
  scanf("%d", qtd);
}
//Manter como especificado
TADduende *alocaDuendes(TADduende *D, int qtd){
  D = (TADduende*) malloc (qtd * sizeof(TADduende)); //o sizeof vai ser sempre o ultimo do .h typedef
  if (D == NULL){

    printf ("Memoria insuficiente");
    exit(1);
  }
  return D;
}

//Manter como especificado
TADtime *alocaTimes(TADtime *T, int qtd){
  T = (TADtime*) malloc (qtd * sizeof(TADtime));
  if (T == NULL){

    printf ("Memoria insuficiente");
    exit(1);
  }
  return T;
}

//Manter como especificado
TADduende *desalocaDuendes(TADduende *D){
  free(D);
  return NULL;
}

//Manter como especificado
TADtime *desalocaTimes(TADtime *T){
  free(T);
  return NULL;
}

//Manter como especificado
void lerDuendes(TADduende *D, int qtd){
  int i;
  for (i = 0; i < qtd; i++) {
    fgets(D[i].nome, 20, stdin);
    int tam = strlen(D[i].nome) - 1;
    D[i].nome[tam] = '\0';
    scanf("%d", &D[i].idade);
    D[i].escalado = 0;
  }
  //ler nome e idade de cada duente
  //aproveitar para colocar o valor 0 no campo escalado
}

//Manter como especificado
void escalarTimes(TADduende *D, TADtime *T, int qtd){
  int i, indice;
  //completar o XXX
  int numerodetimes = qtd / 3;
  for (i=0; i < numerodetimes; i++)
  {
    indice = proximoMaisVelho(D, qtd);
    //marcar o duende do indice como escalado
    D[indice].escalado = 1;
    //a linha abaixo copia o nome do duende para a estrutura do time
    T[i].nomedolider = D[indice].nome;
    //copiar a idade
    T[i].idadedolider = D[indice].idade;
  }

  //repetir o laco acima, mas para o entregador
  for (i=0; i < numerodetimes; i++)
  {
    indice = proximoMaisVelho(D, qtd);
    //marcar o duende do indice como escalado
    D[indice].escalado = 1;
    //a linha abaixo copia o nome do duende para a estrutura do time
    T[i].nomedoentregador = D[indice].nome;
    //copiar a idade
    T[i].idadedoentregador = D[indice].idade;
  }

  //repetir o laco acima, mara para o piloto
  for (i=0; i < numerodetimes; i++)
  {
    indice = proximoMaisVelho(D, qtd);
    //marcar o duende do indice como escalado
    D[indice].escalado = 1;
    //a linha abaixo copia o nome do duende para a estrutura do time
    T[i].nomedopiloto = D[indice].nome;
    //copiar a idade
    T[i].idadedopiloto = D[indice].idade;
  }
}

int proximoMaisVelho(TADduende *D, int qtd){
  int indice;
  int maior = 0;
  //determinar o indice do duende mais velho nao escalado ainda
  for (int i = 0; i < qtd; i++) {
    if (D[i].idade > maior && D[i].escalado == 0) {
      indice = i;
    }
  }
  //variaveis adicionais podem ser criadas
  return indice;
}

//Manter como especificado
void printTimes(TADtime *T, int qtd){
  for (int i = 0; i < qtd/3; i++) {
    printf("Time %d", i+1);
    printf("%s %d\n", T[i].nomedolider, T[i].idadedolider);
    printf("%s %d\n", T[i].nomedoentregador, T[i].idadedoentregador);
    printf("%s %d\n", T[i].nomedopiloto, T[i].idadedopiloto);
  }
  
}
