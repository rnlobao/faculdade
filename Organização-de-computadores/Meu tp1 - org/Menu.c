//Robson Novato Lobao 20.1.4018
#include "Menu.h"

void menu(Memoria* ram){

  int* memory;
  int op;
  int valor1, valor2, valor3;

  printf("Calculadora.\n\n");
  printf("Pressione (0)  - soma.\n");
  printf("Pressione (1)  - subtracao.\n");
  printf("Pressione (2)  - multiplicacao.\n");
  printf("Pressione (3)  - divisao.\n");
  printf("Pressione (4)  - potenciacao.\n");
  printf("Pressione (5)  - PA.\n");
  printf("Pressione (6)  - PG.\n");
  printf("Pressione (7)  - Volume de paralelepipedo.\n");
  printf("Pressione (8)  - Realizar a soma de numeros elevados ao quadrado.\n");
  printf("Pressione (9)  - Realizar a soma de numeros elevados ao cubo.\n");
  printf("Pressione (-1) - Para sair.\n\n");

  do {

  do {
    scanf("%d", &op);
  } while(op>9 || op<-1);

  switch (op) {

    case 0:
      scanf("%d", &valor1);
      scanf("%d", &valor2);
      programaSoma(ram,valor1,valor2);
      memory = retornaRAM(ram);
      printf("O resultado da soma = %d\n\n", memory[1]);
    break;

    case 1:
      scanf("%d", &valor1);
      scanf("%d", &valor2);
      programaSubtracao(ram, valor1, valor2);
      memory = retornaRAM(ram);
      printf("O resultado da subtracao = %d\n\n", memory[1]);
    break;

    case 2:
      scanf("%d", &valor1);
      scanf("%d", &valor2);
      programaMultiplicacao(ram, valor1, valor2);
      memory = retornaRAM(ram);
      printf("O resultado da multiplicacao = %d\n\n", memory[1]);
    break;

    case 3:
      scanf("%d", &valor1);
      scanf("%d", &valor2);
      programaDivisao(ram, valor1, valor2);
      memory = retornaRAM(ram);
      printf("O resultado da divisao = %d\n\n", memory[0]);
    break;

    case 4:
      scanf("%d", &valor1);
      scanf("%d", &valor2);
      programaPotenciacao(ram, valor1, valor2);
      memory = retornaRAM(ram);
      printf("O resultado da potenciacao = %d\n\n", memory[1]);
    break;

    case 5:
      scanf("%d", &valor1);
      scanf("%d", &valor2);
      scanf("%d", &valor3);;
      printf("PA = ");
      programaPA(ram, valor1, valor2, valor3);
    break;

    case 6:
      scanf("%d", &valor1);
      scanf("%d", &valor2);
      scanf("%d", &valor3);
      printf("PG = ");
      programaPG(ram, valor1, valor2, valor3);
    break;

    case 7:
      scanf("%d", &valor1);
      scanf("%d", &valor2);
      scanf("%d", &valor3);
      volumeParalelepipedo(ram, valor1, valor2, valor3);
      memory = retornaRAM(ram);
      printf("\n\nO volume do paralelepipedo = %d\n\n", memory[1]);
    break;

    case 8:
      scanf("%d", &valor1);
      scanf("%d", &valor2);
      somadosquadrados(ram, valor1, valor2);
      memory = retornaRAM(ram);
      printf("A soma dos quadrados dos numeros = %d\n\n", memory[1]);
    break;

    case 9:
      scanf("%d", &valor1);
      scanf("%d", &valor2);
      somadoscubos(ram, valor1, valor2);
      memory = retornaRAM(ram);
      printf("A soma dos cubos dos numeros = %d\n\n", memory[1]);
    break;
  }

  } while(op!=-1);

  if(op==-1){
    printf("\nFim de programa.");
  }
}
