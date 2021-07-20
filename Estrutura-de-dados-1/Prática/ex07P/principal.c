#include "ordenacao.h"
#include <stdio.h>

int main ()
{
	int i;
	int n, k;
  	TipoAluno *alunos;

	scanf("%d", &n);
	scanf("%d", &k);
	alunos = alocaAlunos(alunos, n);
	for (i = 0; i < n; i++) {
		scanf(" %s", alunos[i].nome);
	}
	ordena(alunos, n);
	printf("%s", alunos[k-1].nome);
	alunos = desalocaAlunos(alunos);
  return 0;
}
