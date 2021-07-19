//Robson Novato Lobao 20.1.4018
#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include<stdio.h>
#include<stdlib.h>

#define T 100

typedef struct memoria Memoria;

//Montagem da maquina
Memoria* montarMemoriaDados(void);
void maquina(Memoria *ram);

//Funcoes de retorno de memoria
int* retornaRAM(Memoria* ram);
void liberaRam(Memoria* ram);

//Equacoes fundamentais
void programaSoma(Memoria* ram, int parcela1, int parcela2);
void programaSubtracao(Memoria* ram, int minuendo, int subtraendo);

//Demais equacoes
void programaMultiplicacao(Memoria *ram, int multiplicando, int multiplicador);
void programaDivisao(Memoria *ram, int dividendo, int divisor);
void programaPotenciacao(Memoria* ram, int base, int expoente);
void raizquadrada(Memoria *ram, int num1);

#endif
