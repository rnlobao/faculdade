# ifndef ordenacao_h
# define ordenacao_h

typedef struct{
	char nome[20];
} TipoAluno;

//Manter como especificado
void ordena(TipoAluno *alunos, int n);
//Manter como especificado
TipoAluno *alocaAlunos(TipoAluno *alunos, int n);
//Manter como especificado
TipoAluno *desalocaAlunos(TipoAluno *alunos);
# endif
