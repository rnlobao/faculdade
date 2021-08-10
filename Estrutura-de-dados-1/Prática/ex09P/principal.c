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
	}
	Heap_Constroi(heap, n);
	//a principio, cada caixa esta disponivel no tempo zero
	int qtdprodutos[200];
	for (int i = 0; i < m; i++) {
		scanf("%d", qtdprodutos[i]);
	}
	TipoCaixa aux;
	int resposta = 0;
	while (m--) {		
		//verificar qual caixa estara disponivel primeiro
		aux.tempolevado = heap[m-1].tempolevado;
		heap[m-1].tempolevado = heap[0].tempolevado;
		heap[0].tempolevado = aux.tempolevado;
		m = m-1;
		Heap_Refaz(heap, 0, m-1);
		//alterar a disponibilidade do caixa selecionado
		heap[m].disponivel = 1;
		//armazenar qual o tempo maximo para atender todos clientes ate agora

	}

	heap = desalocaVetor(heap);
	printf("%d", resposta);
	return 0;
}
