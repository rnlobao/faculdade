//Ex 7
#include <stdio.h> 

int main() {
    float numerador = 1;
    float denominador = 1;
    float s = 0;
    for (int i = 0; i < 50; i++) {
        s += numerador / denominador;
        numerador += 2.0;
        denominador += 1.0;
    }
    printf("Valor de s: %f\n", s);
    return 0;
}