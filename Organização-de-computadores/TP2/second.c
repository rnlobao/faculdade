#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tamanhoram 1000
#define tamcache1 16
#define tamcache2 32
#define tamcache3 64
#define tamdasinstrucoes 200


typedef struct {
    int opcode;
    int end1; 
    int end2; 
    int end3; 
} instrucao;

typedef struct {
    int endereco;
    int conteudo;
    int refresh;
    int uso;
} blocodememoria;

void iniciaram (blocodememoria *ram);
void iniciacache1 (blocodememoria *cache1);
void iniciacache2 (blocodememoria *cache2);
void iniciacache3 (blocodememoria *cache3);
void inicialerinstrucoes (instrucao *instrucao);
void maquinainterpretada (blocodememoria *cache1, blocodememoria *cache2,blocodememoria *cache3, instrucao *instrucao, blocodememoria *ram, int *cacheHit , int *cacheMiss, int *custoTotal);
int mudancaDeValor (blocodememoria *cache1, blocodememoria *cache2, blocodememoria *cache3, int endereco, blocodememoria *ram, int *cacheHit , int *cacheMiss , int *custoTotal);
int definen (blocodememoria *cache1, blocodememoria *cache2, blocodememoria *cache3, int n);
void imprimirRelatorio(int cacheHit , int cacheMiss, int custoTotal);



int main() {
    blocodememoria ram [tamanhoram];
    blocodememoria cache1[tamcache1];
    blocodememoria cache2 [tamcache2];
    blocodememoria cache3 [tamcache3];
    int cacheHit = 0 , cacheMiss = 0 , custoTotal = 0 ;

    iniciaram(ram);
    iniciacache1(cache1);
    iniciacache2(cache2);
    iniciacache3(cache3);

    instrucao lerinstrucoes[tamdasinstrucoes];

    inicialerinstrucoes(lerinstrucoes);

    maquinainterpretada (cache1, cache2, cache3, lerinstrucoes, ram , &cacheHit , &cacheMiss , &custoTotal);

    imprimirRelatorio(cacheHit,cacheMiss,custoTotal);

    return 0;
}


void iniciaram (blocodememoria *ram) {
    srand(time(NULL));
    for (int i = 0; i < tamanhoram; i++) {
        ram[i].endereco = i; 
        ram[i].conteudo = rand() % 1000; 
        ram[i].refresh = 0;
        ram[i].uso = 0;
    }
    
}

void iniciacache1 (blocodememoria *cache1) {
    srand(time(NULL));
    for (int i = 0; i < tamcache1; i++) {
        cache1[i].endereco = 1000 + i;
        cache1[i].conteudo = rand() % 1000;
        cache1[i].refresh = 0;
        cache1[i].uso = 0; 
    }
}

void iniciacache2 (blocodememoria *cache2) {
    srand(time(NULL));
    for (int i = 0; i < tamcache2; i++) {
        cache2[i].endereco = 1016 + i;
        cache2[i].conteudo = rand() % 1000;
        cache2[i].refresh = 0;
        cache2[i].uso = 0; 
    }
}

void iniciacache3 (blocodememoria *cache3) {
    srand(time(NULL));
    for (int i = 0; i < tamcache3; i++) {
        cache3[i].endereco = i + 1048;
        cache3[i].conteudo = rand() % 1000;
        cache3[i].refresh = 0;
        cache3[i].uso = 0; 
    }
}

void inicialerinstrucoes (instrucao *instrucao) {
    srand(time(NULL));
    for (int i = 0; i < tamdasinstrucoes; i++) {
        instrucao[i].opcode = rand() % 2; 
        instrucao[i].end1 = rand() % 1112; 
        instrucao[i].end2 = rand() % 1112;
        instrucao[i].end3 = rand() % 1112;
    }
}

int eh_vazio (blocodememoria *blocogenerico, int qualbloco) {
        if (qualbloco == 2) {
            for (int i = 1016; i < 1048; i++) {
                blocogenerico[i].uso == 0;
                return i;
            }

        }
}

void maquinainterpretada (blocodememoria *cache1, blocodememoria *cache2, blocodememoria *cache3, instrucao *instrucao, blocodememoria *ram ,int *cacheHit , int *cacheMiss, int *custoTotal) {
    int n , k ;
    for (int i = 0; i < tamdasinstrucoes; i++) {
        if (instrucao[i].opcode == 0) { //soma
            mudancaDeValor(cache1, cache2, cache3, instrucao[i].end1, ram , cacheHit , cacheMiss , custoTotal);
            n = cache1[eh_vazio(cache1)].conteudo;
            printf("|Primeiro Valor na cache1 = %d|\n\n" , n);

            mudancaDeValor(cache1, cache2, cache3, instrucao[i].end2, ram, cacheHit , cacheMiss , custoTotal);
            k = cache1[cacheSup1].conteudo;
            printf("|Segundo Valor na cache1 = %d|\n\n" , k);

            ram[instrucao[i].end3].conteudo = n + k;
            printf("Soma: %d + %d = %d\n\n",n , k , ram[instrucao[i].end3].conteudo);

        }
        if (instrucao[i].opcode == 1) { //subtracao
            mudancaDeValor(cache1, cache2, cache3, instrucao[i].end1, ram , cacheHit , cacheMiss , custoTotal);
            n = cache1[cacheSup1].conteudo; printf("|Primeiro Valor na cache1 = %d|\n\n" , n);

            mudancaDeValor(cache1, cache2, cache3, instrucao[i].end2, ram , cacheHit , cacheMiss , custoTotal); 
            k = cache1[cacheSup1].conteudo; printf("|Segundo valor na cache1 = %d|\n\n" , k);
            
            ram[instrucao[i].end3].conteudo = n - k;
            printf("Subtração: %d - %d = %d\n\n",n , k , ram[instrucao[i].end3].conteudo);

        }
    }
}

int mudancaDeValor (blocodememoria *cache1, blocodememoria *cache2, blocodememoria *cache3, int endereco, blocodememoria *ram, int *cacheHit , int *cacheMiss, int *custoTotal) { //endereco que vamos buscar, ele esta

    if(endereco >= 0 && endereco < tamcache1)
    {
        for(int i = 0; i < tamcache1 ; i++)
        {
            if(cache1[i].endereco == endereco)
            {
                cache1[i].uso++;
                *cacheHit = *cacheHit + 1;
                *custoTotal = *custoTotal + 10;
                return cache1[i].conteudo;
            }
        }
    }

   else if(endereco >= tamcache1 && endereco < tamcache1 + tamcache2)
   {
       for(int j = tamcache1 ; j < tamcache1 + tamcache2 ; j++)
       {
           if(cache2[j].endereco == endereco)
           {
               cache2[j].uso++;
               blocodememoria aux;
               aux.conteudo = cache1[cacheSup1].conteudo;
               cache1[cacheSup1].conteudo = cache2[j].conteudo;
               cache2[j].conteudo = aux.conteudo;

               printf("|Valor na cache2|  |Movendo valor da cache2 para cache1|\n");
               *custoTotal = *custoTotal + 20; 
               mudancaDeValor(cache1,cache2,cache3,cacheSup1,ram , cacheHit , cacheMiss , custoTotal);
           }
       }
   }


   else if(endereco >= tamcache1 + tamcache2 && endereco < tamcache1 + tamcache2 + tamcache3)
   {
       for(int k = tamcache1 + tamcache2 ; k < tamcache1 + tamcache2 + tamcache3 ; k++)
       {
           if(cache3[k].endereco == endereco)
           {
                blocodememoria aux;
                aux.conteudo = cache2[cacheSup2].conteudo;
                cache2[cacheSup2].conteudo = cache3[k].conteudo;
                cache3[k].conteudo = aux.conteudo;
                
                printf("|Valor na cache3|  |Movendo valor da cache3 para cache2|\n");
                *custoTotal = *custoTotal + 30;
                mudancaDeValor(cache1,cache2,cache3,cacheSup2,ram, cacheHit , cacheMiss , custoTotal);
           }
       }
   }

   else if (endereco >= tamcache1 + tamcache2 + tamcache3 && endereco < tamanhoram)
   {
       for(int l = tamcache1 + tamcache2 + tamcache3 ; l < tamanhoram ; l++)          
       {
           if(ram[l].endereco == endereco)
           {
                blocodememoria aux;
                aux.conteudo = cache3[cacheSup3].conteudo;
                cache3[cacheSup3].conteudo = ram[l].conteudo;
                ram[l].conteudo = aux.conteudo;

               
               printf("|Valor na RAM|     |Movendo valor da RAM para cache3|\n");
               *cacheMiss = *cacheMiss + 1;
               *custoTotal = *custoTotal + 1000;
               *cacheHit = *cacheHit - 1;
               mudancaDeValor(cache1,cache2,cache3,cacheSup3,ram , cacheHit , cacheMiss , custoTotal);   
           }
       }
   }

   return 0;


}




void imprimirRelatorio(int cacheHit , int cacheMiss , int custoTotal)
{
    printf("\n|Cache Hit:   %d|   ", cacheHit);
    printf("|Cache Miss:  %d|   ", cacheMiss);
    printf("|Custo Total: %d|\n\n", custoTotal);
}