#include "hash.h"
#include <stdio.h>

int main(){
	//criar variavel para tabela hash
	THash *hash;
	int n, c;

	//ler tamanho da tabela hash e a quantidade de chaves
	scanf("%d %d", &n, &c);
	//printf("LIDOS N == %d e C == %d\n", n, c);

	//inicializar a tabela hash
	THash_Inicia(hash, n);
	
	//para cada chave da entrada, ler e inserir na tabela hash
	Leitor(hash, &n, &c);

	//imprimir a tabela hash de acordo com a especificacao da saida
	Imprime(hash, n);
	printf("\n");

   return 0;
}
