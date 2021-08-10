#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define repeticao 75
#define tamanhoram 1000
#define tamcache1 64
#define tamcache2 128
#define tamcache3 256
#define tamdasinstrucoes 20000
#define nro_palavras 4

typedef struct
{
    int opcode;
    int end1;
    int end2;
    int end3;
    int palavras[3];
} instrucao;

typedef struct
{
    int palavras[nro_palavras];
    int endereco;
    int uso;
    int atualizado;
} blocodememoria;

void iniciaram(blocodememoria *ram);
void iniciacache1(blocodememoria *cache1);
void iniciacache2(blocodememoria *cache2);
void iniciacache3(blocodememoria *cache3);
void inicialerinstrucoes(instrucao *instrucao);
void maquinainterpretada(instrucao *instrucoes, blocodememoria *cache1, blocodememoria *cache2, blocodememoria *cache3, blocodememoria *ram, int *cache1_Hit, int *cache2_Hit, int *cache3_Hit, int *cache1_Miss, int *cache2_Miss, int *cache3_Miss);
int definir_piorBloco(blocodememoria *cache, int tam);
void apagar_BlocoDuplicado(blocodememoria *cache, int endereco_Bloco);
blocodememoria buscar_Caches(blocodememoria *cache1, blocodememoria *cache2, blocodememoria *cache3, blocodememoria *ram, int endereco_Bloco, int *cache1_Hit, int *cache2_Hit, int *cache3_Hit, int *cache1_Miss, int *cache2_Miss, int *cache3_Miss, int *posicaor_Cache1);
void terminar_Caches(blocodememoria *cache1, blocodememoria *cache2, blocodememoria *cache3, blocodememoria *ram);

int main()
{
    blocodememoria ram[tamanhoram];
    blocodememoria cache1[tamcache1];
    blocodememoria cache2[tamcache2];
    blocodememoria cache3[tamcache3];
    instrucao instrucoes[tamdasinstrucoes];
    int cache1_Hit = 0, cache2_Hit = 0, cache3_Hit = 0, cache1_Miss = 0, cache2_Miss = 0, cache3_Miss = 0, custo_Total;

    srand(time(NULL));
    iniciaram(ram);
    iniciacache1(cache1);
    iniciacache2(cache2);
    iniciacache3(cache3);
    inicialerinstrucoes(instrucoes);
    maquinainterpretada(instrucoes, cache1, cache2, cache3, ram, &cache1_Hit, &cache2_Hit, &cache3_Hit, &cache1_Miss, &cache2_Miss, &cache3_Miss);

    custo_Total = (cache1_Hit * 10) + (cache2_Hit * 20) + (cache3_Hit * 30) + (cache3_Miss * 1000);

    printf("\n\nCache Hit : Final %d | %d + %d + %d\n", cache1_Hit + cache2_Hit + cache3_Hit, cache1_Hit, cache2_Hit, cache3_Hit);
    printf("Cache Miss : Final %d | %d + %d + %d\n", cache1_Miss + cache2_Miss + cache3_Miss, cache1_Miss, cache2_Miss, cache3_Miss);
    printf("Custo : %d\n", custo_Total);

    return 0;
}

void iniciaram(blocodememoria *ram)
{
    for (int i = 0; i < tamanhoram; i++)
    {
        ram[i].endereco = i;
        for (int j = 0; j < nro_palavras; j++)
            ram[i].palavras[j] = rand() % 1000;
        ram[i].atualizado = 0;
        ram[i].uso = 0;
    }
}

void iniciacache1(blocodememoria *cache1)
{
    for (int i = 0; i < tamcache1; i++)
    {
        cache1[i].endereco = -1;
        for (int j = 0; j < nro_palavras; j++)
            cache1[i].palavras[j] = rand() % 1000;
        cache1[i].atualizado = 0;
        cache1[i].uso = 0;
    }
}

void iniciacache2(blocodememoria *cache2)
{
    for (int i = 0; i < tamcache2; i++)
    {
        cache2[i].endereco = -1;
        for (int j = 0; j < nro_palavras; j++)
            cache2[i].palavras[j] = rand() % 1000;
        cache2[i].atualizado = 0;
        cache2[i].uso = 0;
    }
}

void iniciacache3(blocodememoria *cache3)
{
    for (int i = 0; i < tamcache3; i++)
    {
        cache3[i].endereco = -1;
        for (int j = 0; j < nro_palavras; j++)
            cache3[i].palavras[j] = rand() % 1000;
        cache3[i].atualizado = 0;
        cache3[i].uso = 0;
    }
}

void inicialerinstrucoes(instrucao *instrucao)
{
    for (int i = 0; i < 20; i++)
    {
        instrucao[i].opcode = rand() % 2;
        instrucao[i].end1 = rand() % (tamanhoram - 1);
        instrucao[i].end2 = rand() % (tamanhoram - 1);
        instrucao[i].end3 = rand() % (tamanhoram - 1);
        for (int j = 0; j < 3; j++)
            instrucao[i].palavras[j] = rand() % 3;
    }

    for (int i = 20; i < tamdasinstrucoes; i++)
    {
        if (rand() % 100 < repeticao)
        {
            instrucao[i] = instrucao[i - (1 + rand() % 1)];
        }
        else
        {
            instrucao[i].opcode = rand() % 2;
            instrucao[i].end1 = rand() % (tamanhoram - 1);
            instrucao[i].end2 = rand() % (tamanhoram - 1);
            instrucao[i].end3 = rand() % (tamanhoram - 1);
            for (int j = 0; j < 3; j++)
                instrucao[i].palavras[j] = rand() % 3;
        }
    }

    instrucao[tamdasinstrucoes - 1].opcode = -1; //Halt.
}

int definir_piorBloco(blocodememoria *cache, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        if (cache[i].endereco == -1)
            return i;
    }

    int reff = 1000000;
    int aux;

    for (int i = 0; i < tam; i++)
    {
        if (cache[i].uso < reff)
        {
            reff = cache[i].uso;
            aux = i;
        }
    }

    return aux;
}

void apagar_BlocoDuplicado(blocodememoria *cache, int endereco_Bloco)
{
    cache[endereco_Bloco].endereco = -1;
}

blocodememoria buscar_Caches(blocodememoria *cache1, blocodememoria *cache2, blocodememoria *cache3, blocodememoria *ram, int endereco_Bloco, int *cache1_Hit, int *cache2_Hit, int *cache3_Hit, int *cache1_Miss, int *cache2_Miss, int *cache3_Miss, int *posicaor_Cache1)
{
    int pior_Cache1, pior_Cache2, pior_Cache3;

    for (int i = 0; i < tamcache1; i++)
    {
        if (cache1[i].endereco == endereco_Bloco)
        {
            cache1[i].uso += 100;
            *cache1_Hit += 1;
            *posicaor_Cache1 = i;

            return cache1[i];
        }
    }

    for (int i = 0; i < tamcache2; i++)
    {
        if (cache2[i].endereco == endereco_Bloco)
        {
            *cache1_Miss += 1;
            *cache2_Hit += 1;

            pior_Cache1 = definir_piorBloco(cache1, tamcache1);
            pior_Cache2 = definir_piorBloco(cache2, tamcache2);
            pior_Cache3 = definir_piorBloco(cache3, tamcache3);

            if (cache3[pior_Cache3].atualizado)
                ram[cache3[pior_Cache3].endereco] = cache3[pior_Cache3];
            cache3[pior_Cache3] = cache2[pior_Cache2];
            cache2[pior_Cache2] = cache1[pior_Cache1];
            cache1[pior_Cache1] = cache2[i];

            apagar_BlocoDuplicado(cache2, i);

            *posicaor_Cache1 = pior_Cache1;
            cache1[pior_Cache1].uso += 100;

            return cache1[pior_Cache1];
        }
    }

    for (int i = 0; i < tamcache3; i++)
    {
        if (cache3[i].endereco == endereco_Bloco)
        {
            *cache1_Miss += 1;
            *cache2_Miss += 1;
            *cache3_Hit += 1;

            pior_Cache1 = definir_piorBloco(cache1, tamcache1);
            pior_Cache2 = definir_piorBloco(cache2, tamcache2);
            pior_Cache3 = definir_piorBloco(cache3, tamcache3);

            if (cache3[pior_Cache3].atualizado)
                ram[cache3[pior_Cache3].endereco] = cache3[pior_Cache3];
            cache3[pior_Cache3] = cache2[pior_Cache2];
            cache2[pior_Cache2] = cache1[pior_Cache1];

            pior_Cache2 = definir_piorBloco(cache2, tamcache2);
            pior_Cache3 = definir_piorBloco(cache3, tamcache3);

            if (cache3[pior_Cache3].atualizado)
                ram[cache3[pior_Cache3].endereco] = cache3[pior_Cache3];
            cache3[pior_Cache3] = cache2[pior_Cache2];
            cache2[pior_Cache2] = cache3[i];
            cache1[pior_Cache1] = cache2[pior_Cache2];

            apagar_BlocoDuplicado(cache3, i);
            apagar_BlocoDuplicado(cache2, pior_Cache2);

            *posicaor_Cache1 = pior_Cache1;
            cache1[pior_Cache1].uso += 100;

            return cache1[pior_Cache1];
        }
    }

    *cache1_Miss += 1;
    *cache2_Miss += 1;
    *cache3_Miss += 1;

    pior_Cache1 = definir_piorBloco(cache1, tamcache1);
    pior_Cache2 = definir_piorBloco(cache2, tamcache2);
    pior_Cache3 = definir_piorBloco(cache3, tamcache3);

    if (cache3[pior_Cache3].atualizado)
        ram[cache3[pior_Cache3].endereco] = cache3[pior_Cache3];
    cache3[pior_Cache3] = cache2[pior_Cache2];
    cache2[pior_Cache2] = cache1[pior_Cache1];

    pior_Cache2 = definir_piorBloco(cache2, tamcache2);
    pior_Cache3 = definir_piorBloco(cache3, tamcache3);

    if (cache3[pior_Cache3].atualizado)
        ram[cache3[pior_Cache3].endereco] = cache3[pior_Cache3];
    cache3[pior_Cache3] = cache2[pior_Cache2];

    pior_Cache3 = definir_piorBloco(cache3, tamcache3);

    if (cache3[pior_Cache3].atualizado)
        ram[cache3[pior_Cache3].endereco] = cache3[pior_Cache3];
    cache3[pior_Cache3] = ram[endereco_Bloco];
    cache2[pior_Cache2] = cache3[pior_Cache3];
    cache1[pior_Cache1] = cache2[pior_Cache2];

    apagar_BlocoDuplicado(cache3, pior_Cache3);
    apagar_BlocoDuplicado(cache2, pior_Cache2);

    *posicaor_Cache1 = pior_Cache1;

    cache1[pior_Cache1].uso += 100;
    return cache1[pior_Cache1];
}

void terminar_Caches(blocodememoria *cache1, blocodememoria *cache2, blocodememoria *cache3, blocodememoria *ram)
{
    for (int i = 0; i < tamcache1; i++)
    {
        if (cache1[i].atualizado)
            ram[cache1[i].endereco] = cache1[i];
    }

    for (int i = 0; i < tamcache2; i++)
    {
        if (cache2[i].atualizado)
            ram[cache2[i].endereco] = cache2[i];
    }

    for (int i = 0; i < tamcache3; i++)
    {
        if (cache3[i].atualizado)
            ram[cache3[i].endereco] = cache3[i];
    }
}

void diminuir_Uso(blocodememoria *cache1, blocodememoria *cache2, blocodememoria *cache3)
{
    for (int i = 0; i < tamcache1; i++)
        cache1[i].uso--;
    for (int i = 0; i < tamcache2; i++)
        cache2[i].uso--;
    for (int i = 0; i < tamcache3; i++)
        cache3[i].uso--;
}

void maquinainterpretada(instrucao *instrucoes, blocodememoria *cache1, blocodememoria *cache2, blocodememoria *cache3, blocodememoria *ram, int *cache1_Hit, int *cache2_Hit, int *cache3_Hit, int *cache1_Miss, int *cache2_Miss, int *cache3_Miss)
{
    blocodememoria bloco1, bloco2, bloco3;
    int posicaor_Cache1;

    for (int i = 0; i < tamdasinstrucoes; i++)
    {
        switch (instrucoes[i].opcode)
        {
        case -1:
            terminar_Caches(cache1, cache2, cache3, ram);
            return;
        case 0:
            bloco1 = buscar_Caches(cache1, cache2, cache3, ram, instrucoes[i].end1, cache1_Hit, cache2_Hit, cache3_Hit, cache1_Miss, cache2_Miss, cache3_Miss, &posicaor_Cache1);
            diminuir_Uso(cache1, cache2, cache3);
            bloco2 = buscar_Caches(cache1, cache2, cache3, ram, instrucoes[i].end2, cache1_Hit, cache2_Hit, cache3_Hit, cache1_Miss, cache2_Miss, cache3_Miss, &posicaor_Cache1);
            diminuir_Uso(cache1, cache2, cache3);
            bloco3 = buscar_Caches(cache1, cache2, cache3, ram, instrucoes[i].end3, cache1_Hit, cache2_Hit, cache3_Hit, cache1_Miss, cache2_Miss, cache3_Miss, &posicaor_Cache1);
            diminuir_Uso(cache1, cache2, cache3);
            bloco3.palavras[instrucoes[i].palavras[2]] = bloco1.palavras[instrucoes[i].palavras[0]] + bloco2.palavras[instrucoes[i].palavras[1]];
            bloco3.atualizado = 1;
            printf("Somando %d + %d = %d\n", bloco1.palavras[instrucoes[i].palavras[0]], bloco2.palavras[instrucoes[i].palavras[1]], bloco3.palavras[instrucoes[i].palavras[2]]);
            cache1[posicaor_Cache1] = bloco3;
            break;
        case 1:
            bloco1 = buscar_Caches(cache1, cache2, cache3, ram, instrucoes[i].end1, cache1_Hit, cache2_Hit, cache3_Hit, cache1_Miss, cache2_Miss, cache3_Miss, &posicaor_Cache1);
            diminuir_Uso(cache1, cache2, cache3);
            bloco2 = buscar_Caches(cache1, cache2, cache3, ram, instrucoes[i].end2, cache1_Hit, cache2_Hit, cache3_Hit, cache1_Miss, cache2_Miss, cache3_Miss, &posicaor_Cache1);
            diminuir_Uso(cache1, cache2, cache3);
            bloco3 = buscar_Caches(cache1, cache2, cache3, ram, instrucoes[i].end3, cache1_Hit, cache2_Hit, cache3_Hit, cache1_Miss, cache2_Miss, cache3_Miss, &posicaor_Cache1);
            diminuir_Uso(cache1, cache2, cache3);
            bloco3.palavras[instrucoes[i].palavras[2]] = bloco1.palavras[instrucoes[i].palavras[0]] - bloco2.palavras[instrucoes[i].palavras[1]];
            bloco3.atualizado = 1;
            printf("Subtraindo %d - %d = %d\n", bloco1.palavras[instrucoes[i].palavras[0]], bloco2.palavras[instrucoes[i].palavras[1]], bloco3.palavras[instrucoes[i].palavras[2]]);
            cache1[posicaor_Cache1] = bloco3;
            break;
        }
    }
}