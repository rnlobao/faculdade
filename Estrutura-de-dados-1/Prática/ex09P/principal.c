#include "prioridade.h"
#include <stdio.h>

int main ()
{
	int n, m;
	TipoCaixa *heap;
	
	scanf("%d", &n);
	scanf("%d", &m);
	heap = alocaVetor(heap, n);
	for (int i = 0; i < n; i++) {
		scanf("%d", heap[i].tempolevado);
		heap[i].disponivel = 0;
	}
	Heap_Constroi(heap, n);
	int qtdprodutos[200];
	int cont = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d", qtdprodutos[i]);
		cont++;
	}
	TipoCaixa aux;
	int resposta = 1;
	while (m--) {
		if (heap[m].disponivel == 0) {
			resposta += (qtdprodutos[cont] * heap[m].tempolevado);
		}		
		aux = heap[m-1];
		heap[m-1] = heap[0];
		heap[0] = aux;
		m = m-1;
		Heap_Refaz(heap, 0, m-1);
		heap[m].disponivel = 1;
		cont--;
	}

	heap = desalocaVetor(heap);
	printf("%d", resposta);
	return 0;
}
