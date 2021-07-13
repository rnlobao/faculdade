# ifndef ordenacao_h
# define ordenacao_h

//TAD dos países
typedef struct paises TADpaises;
//Ler quantos países tem
void lerTam(int *tam);
//ALocar os paises dinamicamente
TADpaises *alocaPaises(TADpaises *p, int tam);
//Desalocar os paises
TADpaises *desalocaPaises(TADpaises *p);
//Ler os dados para colocar na struct
void lerPaises(TADpaises *p, int tam);
//Pontuar as medalhas de acordo com o seu peso
TADpaises *pontuar(TADpaises *p, int tam);
//Ordenar a pontuação
TADpaises *organizascore(TADpaises *p, int tam);
//Conferir por ordem alfabética
TADpaises *confererepetido(TADpaises *p, int tam);



//Printar a tad
void printatad(TADpaises *p, int tam);




# endif