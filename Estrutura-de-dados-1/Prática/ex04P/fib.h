# ifndef fib_h
# define fib_h

typedef struct{
  int i;
  long int resultado;
  long int chamadas;
} TADfib;

long int fibonacci(int n, TADfib *f);

# endif
