#include "arvore.h"
#include <stdio.h>

int main ()
{
	int n, no;
	TArvore *arvore;

    TArvore_Inicia(arvore);

	scanf("%d", &n);
	scanf("%d", &no);
	
	TItem x;
	
	x.num = no;

	TArvore_Insere_Raiz(arvore, x);

	for(int i = 1; i < n; i++) {
			scanf("%d", &no);
			x.num = no;
			if (TArvore_Insere(*arvore, x)) {
			    continue;
			}
	}
    
    printf("PREFIXA: ");
	Prefixa(*arvore);
	printf("\n");
	printf("INFIXA: ");
	Infixa(*arvore);
    printf("\n");
	printf("POSFIXA: ");
	Posfixa(*arvore);
    printf("\n");

	return 0;
}
