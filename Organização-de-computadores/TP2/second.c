#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tamanhoram 1000
#define tamcache1 16
#define tamcache2 32
#define tamcache3 64
#define tamdasinstrucoes 1


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
int mudancaDeValor (blocodememoria *cache1, blocodememoria *cache2, blocodememoria *cache3, int endereco, blocodememoria *ram, int *cacheHit , int *cacheMiss , int *custoTotal, int rec);
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

    for (int i = 0; i < tamcache1; i++) {
        printf("ENDERECO NA CACHE1: %d---- ", cache1[i].endereco);
        printf("CONTEUDO NA CACHE1: %d -----", cache1[i].conteudo);
        printf("ESSE EH O USO NA CACHE1: %d\n", cache1[i].uso);
    }

    for (int i = 0; i < tamcache2; i++) {
        printf("ENDERECO NA CACHE2: %d---- ", cache2[i].endereco);
        printf("CONTEUDO NA CACHE2: %d\n", cache2[i].conteudo);
    }

    

    



    instrucao lerinstrucoes[tamdasinstrucoes];

    inicialerinstrucoes(lerinstrucoes);

    maquinainterpretada (cache1, cache2, cache3, lerinstrucoes, ram , &cacheHit , &cacheMiss , &custoTotal);

    imprimirRelatorio(cacheHit,cacheMiss,custoTotal);


    for (int i = 0; i < tamcache1; i++) {
        printf("ENDERECO NA CACHE1: %d---- ", cache1[i].endereco);
        printf("CONTEUDO NA CACHE1: %d -----", cache1[i].conteudo);
        printf("ESSE EH O USO NA CACHE1: %d\n", cache1[i].uso);
    }

    for (int i = 0; i < tamcache2; i++) {
        printf("ENDERECO NA CACHE2: %d---- ", cache2[i].endereco);
        printf("CONTEUDO NA CACHE2: %d\n", cache2[i].conteudo);
    }



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
        instrucao[i].end1 = 1020;
        instrucao[i].end2 = 1008;
        instrucao[i].end3 = rand() % 1112;
    }
}

void maquinainterpretada (blocodememoria *cache1, blocodememoria *cache2, blocodememoria *cache3, instrucao *instrucao, blocodememoria *ram ,int *cacheHit , int *cacheMiss, int *custoTotal) {
    int n , k ;
    for (int i = 0; i < tamdasinstrucoes; i++) {
        if (instrucao[i].opcode == 0) { //soma
            printf("%d ----- ESSE AQUI E O ENDERECO QUE A GENTE TA BUSCANDO PRA SOMA 1\n", instrucao[i].end1);
            printf("%d ----- ESSE AQUI E O ENDERECO QUE A GENTE TA BUSCANDO PRA SOMA 2\n", instrucao[i].end2);
            n = mudancaDeValor(cache1, cache2, cache3, instrucao[i].end1, ram , cacheHit , cacheMiss , custoTotal, 0);
            k = mudancaDeValor(cache1, cache2, cache3, instrucao[i].end2, ram, cacheHit , cacheMiss , custoTotal, 0); 
            cache1[eh_trocado(cache1, 1)].conteudo = n + k;
            printf("Soma: %d + %d = %d\n\n",n , k , cache1[eh_trocado(cache1, 1)].conteudo);
        }
        if (instrucao[i].opcode == 1) { //subtracao
            printf("%d ----- ESSE AQUI E O ENDERECO QUE A GENTE TA BUSCANDO PRA SOMA 1\n", instrucao[i].end1);
            printf("%d ----- ESSE AQUI E O ENDERECO QUE A GENTE TA BUSCANDO PRA SOMA 2\n", instrucao[i].end2);
            
            n = mudancaDeValor(cache1, cache2, cache3, instrucao[i].end1, ram , cacheHit , cacheMiss , custoTotal, 0);
            printf("\n\n\n\n OUTRO VALOR\n\n");
            k = mudancaDeValor(cache1, cache2, cache3, instrucao[i].end2, ram, cacheHit , cacheMiss , custoTotal, 0); 
            cache1[eh_trocado(cache1, 1)].conteudo = n - k;
            printf("Subtracao: %d - %d = %d\n\n",n , k , cache1[eh_trocado(cache1, 1)].conteudo); 

        }
    }
    
    
}



int mudancaDeValor (blocodememoria *cache1, blocodememoria *cache2, blocodememoria *cache3, int endereco, blocodememoria *ram, int *cacheHit , int *cacheMiss, int *custoTotal, int rec) { 
    if((endereco >= 1000 && endereco < 1016) || rec == 1)
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

   else if((endereco >= 1016 && endereco < 1048) || rec == 2)
   {
       for(int j = 0 ; j < tamcache2 ; j++)
       {
           if(cache2[j].endereco == endereco)
           {
               cache2[j].uso++;
               blocodememoria aux;
               for (int i = 0; i < 16; i++) {
                   if (eh_trocado(cache1, 1) == cache1[i].endereco) {
                       aux = cache1[i];
                       cache1[i] = cache2[j];
                       cache2[j] = aux;
                   }
               }
               *custoTotal = *custoTotal + 20; 
               return mudancaDeValor(cache1,cache2,cache3, eh_trocado(cache1, 1),ram , cacheHit , cacheMiss , custoTotal, 1);
           }
       }
   }


   else if(endereco >= 1048 && endereco < 1112)
   {
       for(int k = 0 ; k < tamcache3 ; k++)
       {
           if(cache3[k].endereco == endereco)
           {
                blocodememoria aux;
                aux = cache2[eh_trocado(cache2, 2)];
                cache2[eh_trocado(cache2, 2)] = cache3[k];
                cache3[k] = aux;
                
                *custoTotal = *custoTotal + 30;
                return mudancaDeValor(cache1,cache2,cache3, eh_trocado(cache2, 2),ram, cacheHit , cacheMiss , custoTotal, 2);
           }
       }
   }

   else if (endereco >= 0 && endereco < 1000)
   {
       for(int l = tamcache1 + tamcache2 + tamcache3 ; l < tamanhoram ; l++)          
       {
           if(ram[l].endereco == endereco)
           {
                blocodememoria aux;
                aux = cache3[eh_trocado(cache3, 3)];
                cache3[eh_trocado(cache3, 3)] = ram[l];
                ram[l] = aux;

               
               *cacheMiss = *cacheMiss + 1;
               *custoTotal = *custoTotal + 1000;
               *cacheHit = *cacheHit - 1;
               mudancaDeValor(cache1,cache2,cache3,eh_trocado(cache3, 3),ram , cacheHit , cacheMiss , custoTotal, 0);   
           }
       }
   }

   return 0;


}


int eh_trocado (blocodememoria *blocogenerico, int qualbloco) {
    int menor = 2000;
    int temcomuso0 = 0;
    if (qualbloco == 1) {
        for (int i = 0; i < 16; i++) {
            if (blocogenerico[i].uso == 0) {
                temcomuso0++;
                return blocogenerico[i].endereco;
            }
        }  
        if (temcomuso0 == 0) {
            for (int i = 0; i < 16; i++) {
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

void imprimirRelatorio (int cacheHit , int cacheMiss , int custoTotal)
{
    printf("\n|Cache Hit:   %d|   ", cacheHit);
    printf("|Cache Miss:  %d|   ", cacheMiss);
    printf("|Custo Total: %d|\n\n", custoTotal);
}