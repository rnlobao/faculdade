#include "maquina.h"

int main()
{
    blocoMemoria RAM[TAM_RAM];
    blocoMemoria cacheL1[TAM_CACHEL1];
    blocoMemoria cacheL2[TAM_CACHEL2];
    blocoMemoria cacheL3[TAM_CACHEL3];
    unidade_Instrucao vetorInstrucao[NRO_INSTRUCOES];
    int LRU_L1 = 0, LRU_L2 = 0, LRU_L3 = 0, cacheHit = 0, cacheMiss = 0, custoTotal = 0;

    iniciarMemoria(RAM, TAM_RAM, 0);
    iniciarMemoria(cacheL1, TAM_CACHEL1, 1);
    iniciarMemoria(cacheL2, TAM_CACHEL2, 1);
    iniciarMemoria(cacheL3, TAM_CACHEL3, 1);
    iniciarInstrucoes(vetorInstrucao);

    maquinaInterpretada(cacheL1, cacheL2, cacheL3, RAM, vetorInstrucao, &cacheHit, &cacheMiss, &LRU_L1, &LRU_L2, &LRU_L3, &custoTotal);
    imprimirRelatorio(&cacheHit, &cacheMiss, &custoTotal);

    return 0;
}