#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tamanhoram 1000
#define tamcache1 16
#define tamcache2 32
#define tamcache3 64
#define tamdasinstrucoes 20


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
int eh_trocado (blocodememoria *blocogenerico, int qualbloco);



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

void maquinainterpretada (blocodememoria *cache1, blocodememoria *cache2, blocodememoria *cache3, instrucao *instrucao, blocodememoria *ram ,int *cacheHit , int *cacheMiss, int *custoTotal) {
    int n , k ;
    for (int i = 0; i < tamdasinstrucoes; i++) {
        if (instrucao[i].opcode == 0) { //soma
            n = mudancaDeValor(cache1, cache2, cache3, instrucao[i].end1, ram , cacheHit , cacheMiss , custoTotal);
            printf("|Primeiro Valor na cache1 = %d|\n\n" , n);

            k = mudancaDeValor(cache1, cache2, cache3, instrucao[i].end2, ram, cacheHit , cacheMiss , custoTotal); 
            printf("|Segundo Valor na cache1 = %d|\n\n" , k);

            cache1[eh_trocado(cache1, 1)].conteudo = n + k;
            printf("Soma: %d + %d = %d\n\n",n , k , cache1[eh_trocado(cache1, 1)].conteudo);
        }
        if (instrucao[i].opcode == 1) { //subtracao
            n = mudancaDeValor(cache1, cache2, cache3, instrucao[i].end1, ram , cacheHit , cacheMiss , custoTotal);
            printf("|Primeiro Valor na cache1 = %d|\n\n" , n);

            k = mudancaDeValor(cache1, cache2, cache3, instrucao[i].end2, ram, cacheHit , cacheMiss , custoTotal); 
            printf("|Segundo Valor na cache1 = %d|\n\n" , k);

            cache1[eh_trocado(cache1, 1)].conteudo = n - k;
            printf("Subtracao: %d - %d = %d\n\n",n , k , cache1[eh_trocado(cache1, 1)].conteudo); 

        }
    }
}

int eh_trocado (blocodememoria *blocogenerico, int qualbloco) {
    int menor = 2000;
    if (qualbloco == 1) {
        for (int i = 0; i < 16; i++) {
            if (blocogenerico[i].uso == 0) {
                return blocogenerico[i].endereco;
            }
            else {
                if (blocogenerico[i].uso < menor) {
                    menor = blocogenerico[i].uso;
                }
                return menor;
            }
        }  
    }

    if (qualbloco == 2) {
        for (int i = 0; i < 32; i++) {
            if (blocogenerico[i].uso == 0) {
                return blocogenerico[i].endereco;
            }
            else {
                if (blocogenerico[i].uso < menor) {
                    menor = blocogenerico[i].uso;
                }
                return menor;
            }
        }  
    }

    if (qualbloco == 3) {
        for (int i = 0; i < 64; i++) {
            if (blocogenerico[i].uso == 0) {
                return blocogenerico[i].endereco;
            }
            else {
                if (blocogenerico[i].uso < menor) {
                    menor = blocogenerico[i].uso;
                }
                return menor;
            }
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
               aux = cache1[eh_trocado(cache1, 1)];
               cache1[eh_trocado(cache1, 1)] = cache2[j];
               cache2[j] = aux;

               printf("|Valor na cache2|  |Movendo valor da cache2 para cache1|\n");
               *custoTotal = *custoTotal + 20; 
               mudancaDeValor(cache1,cache2,cache3, eh_trocado(cache1, 1),ram , cacheHit , cacheMiss , custoTotal);
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
                aux = cache2[eh_trocado(cache2, 2)];
                cache2[eh_trocado(cache2, 2)] = cache3[k];
                cache3[k] = aux;
                
                printf("|Valor na cache3|  |Movendo valor da cache3 para cache2|\n");
                *custoTotal = *custoTotal + 30;
                mudancaDeValor(cache1,cache2,cache3, eh_trocado(cache2, 2),ram, cacheHit , cacheMiss , custoTotal);
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
                aux = cache3[eh_trocado(cache3, 3)];
                cache3[eh_trocado(cache3, 3)] = ram[l];
                ram[l] = aux;

               
               printf("|Valor na RAM|     |Movendo valor da RAM para cache3|\n");
               *cacheMiss = *cacheMiss + 1;
               *custoTotal = *custoTotal + 1000;
               *cacheHit = *cacheHit - 1;
               mudancaDeValor(cache1,cache2,cache3,eh_trocado(cache3, 3),ram , cacheHit , cacheMiss , custoTotal);   
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