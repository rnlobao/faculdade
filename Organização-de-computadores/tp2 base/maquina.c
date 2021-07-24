#include "maquina.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void iniciarMemoria(blocoMemoria *Memoria, int tam_Memoria, int boolean_Cache)
{
    srand(time(NULL));

    for (int i = 0; i < tam_Memoria; i++)
    {
        Memoria[i].data = rand() % RAND_MEMORIA;
        if (boolean_Cache == 1)
            Memoria[i].data = -1;
        else
            Memoria[i].data = i;
    }
}

void iniciarInstrucoes(unidade_Instrucao *Instrucoes)
{
    srand(time(NULL));

    for (int i = 0; i < NRO_INSTRUCOES; i++)
    {
        Instrucoes[i].opCode = rand() % NRO_OPERACOES;
        Instrucoes[i].addressOne = rand() % TAM_RAM;
        Instrucoes[i].addressTwo = rand() % TAM_RAM;
        Instrucoes[i].addressThree = rand() % TAM_RAM;
    }

    Instrucoes[NRO_INSTRUCOES - 1].opCode = -1;
}

blocoMemoria buscarMemoria(blocoMemoria *cacheL1, blocoMemoria *cacheL2, blocoMemoria *cacheL3, blocoMemoria *RAM, int memory_Adress, int *cacheHit, int *cacheMiss, int *LRU_L1, int *LRU_L2, int *LRU_L3, int *custoTotal)
{
    for (int i = 0; i < TAM_CACHEL1; i++)
    {
        if (cacheL1[i].data == memory_Adress)
        {
            *cacheHit = *cacheHit + 1;
            *custoTotal += 10;
            return cacheL1[i];
        }
    }

    for (int i = 0; i < TAM_CACHEL2; i++)
    {
        if (cacheL2[i].data == memory_Adress)
        {
            cacheL1[*LRU_L1] = cacheL2[i];
            *LRU_L1 = *LRU_L1 + 1;
            *cacheHit = *cacheHit + 1;
            *custoTotal += 20;
            return cacheL1[*LRU_L1 - 1];
        }
    }

    for (int i = 0; i < TAM_CACHEL3; i++)
    {
        if (cacheL3[i].data == memory_Adress)
        {
            cacheL2[*LRU_L2] = cacheL3[i];
            cacheL1[*LRU_L1] = cacheL2[*LRU_L2];
            *LRU_L1 = *LRU_L1 + 1;
            *LRU_L2 = *LRU_L2 + 1;
            *cacheHit = *cacheHit + 1;
            *custoTotal += 30;
            return cacheL1[*LRU_L1 - 1];
        }
    }

    cacheL3[*LRU_L3] = RAM[memory_Adress];
    cacheL2[*LRU_L2] = cacheL3[*LRU_L3];
    cacheL1[*LRU_L1] = cacheL2[*LRU_L2];
    *LRU_L1 = *LRU_L1 + 1;
    *LRU_L2 = *LRU_L2 + 1;
    *LRU_L3 = *LRU_L3 + 1;
    *cacheMiss = *cacheMiss + 1;
    *custoTotal += 1000;
    return cacheL1[*LRU_L1 - 1];
}

void atualizar_LRU(int *LRU_L1, int *LRU_L2, int *LRU_L3)
{
    if (*LRU_L1 > TAM_CACHEL1)
        *LRU_L1 = 0;
    if (*LRU_L2 > TAM_CACHEL2)
        *LRU_L2 = 0;
    if (*LRU_L3 > TAM_CACHEL3)
        *LRU_L3 = 0;
}

void levarMemoria(blocoMemoria addressThree, int memory_Address, blocoMemoria *RAM)
{
    RAM[memory_Address] = addressThree;
}

void maquinaInterpretada(blocoMemoria *cacheL1, blocoMemoria *cacheL2, blocoMemoria *cacheL3, blocoMemoria *RAM, unidade_Instrucao *vetorInstrucao, int *cacheHit, int *cacheMiss, int *LRU_L1, int *LRU_L2, int *LRU_L3, int *custoTotal)
{
    blocoMemoria addressOne, addressTwo, addressThree;
    for (int i = 0; i < NRO_INSTRUCOES; i++)
    {
        switch (vetorInstrucao[i].opCode)
        {
        case -1:
            //Halt.
            return;
        case 0:
            // Soma.
            addressOne = buscarMemoria(cacheL1, cacheL2, cacheL3, RAM, vetorInstrucao[i].addressOne, cacheHit, cacheMiss, LRU_L1, LRU_L2, LRU_L3, custoTotal);
            addressTwo = buscarMemoria(cacheL1, cacheL2, cacheL3, RAM, vetorInstrucao[i].addressTwo, cacheHit, cacheMiss, LRU_L1, LRU_L2, LRU_L3, custoTotal);
            addressThree.data = somarInteiros(addressOne.data, addressTwo.data);
            addressThree.data = vetorInstrucao[i].addressThree;
            atualizar_LRU(LRU_L1, LRU_L2, LRU_L3);
            levarMemoria(addressThree, vetorInstrucao[i].addressThree, RAM);
            break;

        case 1:
            // Subtração.
            addressOne = buscarMemoria(cacheL1, cacheL2, cacheL3, RAM, vetorInstrucao[i].addressOne, cacheHit, cacheMiss, LRU_L1, LRU_L2, LRU_L3, custoTotal);
            addressTwo = buscarMemoria(cacheL1, cacheL2, cacheL3, RAM, vetorInstrucao[i].addressTwo, cacheHit, cacheMiss, LRU_L1, LRU_L2, LRU_L3, custoTotal);
            addressThree.data = subtrairInteiros(addressOne.data, addressTwo.data);
            addressThree.data = vetorInstrucao[i].addressThree;
            atualizar_LRU(LRU_L1, LRU_L2, LRU_L3);
            levarMemoria(addressThree, vetorInstrucao[i].addressThree, RAM);
            break;
        }
    }
}

void imprimirRelatorio(int *cacheHit, int *cacheMiss, int *custoTotal)
{
    int int_Size = floor(log10(abs(*custoTotal))) + floor(log10(abs(*cacheHit))) + floor(log10(abs(*custoTotal))) + 3;
    printf("\n - Relatorio - \n\n");
    printf("Cache Hit: %d | Cache Miss: %d | Custo Total: %d\n", *cacheHit, *cacheMiss, *custoTotal);
}

void imprimirMemoria(blocoMemoria *Memoria, int tam_Memoria)
{
    printf("\n");
    for (int i = 0; i < tam_Memoria; i++)
    {
        printf("%3d - %3d       ", Memoria[i].data, Memoria[i].data);
        if (i != 0 && (i + 1) % 10 == 0)
            printf("\n");
    }
    printf("\n");
}

int somarInteiros(int contentOne, int contentTwo)
{
    printf("Soma: %d + %d = %d\n", contentOne, contentTwo, contentOne + contentTwo);

    return contentOne + contentTwo;
}

int subtrairInteiros(int contentOne, int contentTwo)
{
    printf("Subtracao: %d - %d = %d\n", contentOne, contentTwo, contentOne - contentTwo);

    return contentOne - contentTwo;
}