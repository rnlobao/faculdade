#include "hash.h"
#include <stdio.h>

int main(){
	THash *hash;
	int n, c;
	scanf("%d", &n);
	scanf("%d", &c);

	THash_Inicia(hash, n);
	Disponibiliza(hash, &n, &c);

	for (int i = 0; i<n; i++){
		printf("%d -> ", i);
		Imprime(&(hash->v[i]));
	}
   return 0;
}

