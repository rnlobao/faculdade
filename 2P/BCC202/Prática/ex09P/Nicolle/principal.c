#include "prioridade.h"
#include <stdio.h>

int main ()
{
	int n, m, c, aux=0;

	TipoCaixa *heap = NULL;

	int timeMax = 0; 

	scanf("%d %d", &n, &m);
	heap = alocaVetor(heap, n);
	leitor(heap, n);
	

	while(m--){
		scanf("%d", &c);
		if(aux < n){
			heap[aux].timeused = heap[aux].timeused + (c * heap[aux].time);
			//printf("colocando o funcionario %d ocupado. o tempo dele eh %d e a cesta tem %d itens... == %d\n",aux, heap[aux].time, c, heap[aux].timeused);
			if(heap[aux].timeused > timeMax){
				timeMax = heap[aux].timeused;
			}
		}else{
			Heap_Constroi(heap, n);	

			

			//imprime(heap, n);
	
			//printf("o 1st a acabar durou %d min. \n",heap[0].timeused);
			heap[0].timeused = heap[0].timeused + (c * heap[0].time);
			//printf("ocupando. o tempo dele eh %d e a cesta tem %d itens... == %d\n",heap[0].time, c, heap[0].timeused);

			//printf("LINHA 40\n");
			if(heap[0].timeused > timeMax){
				timeMax = heap[0].timeused;
			}
		}
	aux = aux +1;
	}

	heap = desalocaVetor(heap);
	
	printf("%d\n",timeMax);
	return 0;
}
