# ifndef arrays_h
# define arrays_h

#define inicio 0
#define MAXTAM 10

typedef struct{
	int key;
}TADItem;

typedef struct{
	TADItem item[MAXTAM];
	int first, last;
}TADLista;


# endif
