#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include<stdio.h>
#include<stdlib.h>

#define T 100

typedef struct memoria Memoria;

//Montagem da maquina
Memoria* montarMemoriaDados(void);
void montarPrograma(Memoria *ram);
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
void programaPotenciacao(Memoria* ram, int num, int pot);
void somadosquadrados(Memoria *ram, int num1, int num2);
void somadoscubos(Memoria *ram, int num1, int num2);
void programaPA(Memoria* ram, int numero, int razao, int count);
void programaPG(Memoria* ram,int numero,int razao,int count);
void volumeParalelepipedo(Memoria* ram, int altura, int largura, int comprimento);
void programaFatorial(Memoria* ram, int start);

#endif
