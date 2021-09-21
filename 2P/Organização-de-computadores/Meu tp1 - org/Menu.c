//Robson Novato Lobao 20.1.4018
#include "Menu.h"

void menu(Memoria* ram){

  int* memory;
  int op;
  int valor1, valor2, valor3;

  printf("Calculadora.\n\n");
  printf("Use (0)  - soma.\n");
  printf("Use (1)  - subtracao.\n");
  printf("Use (2)  - multiplicacao.\n");
  printf("Use (3)  - divisao.\n");
  printf("Use (4)  - potenciacao.\n");
  printf("Use (5)  - PA (num, razao, contador).\n");
  printf("Use (6)  - PG (num, razao, contador).\n");
  printf("Use (7)  - Volume de solido geometrico(altura, largura, profundidade).\n");
  printf("Use (8)  - Raiz quadrada.\n");
  printf("Use (-1) - SAIR.\n\n");

  do {

  do {
    scanf("%d", &op);
  } while(op>8 || op<-1);

  switch (op) {

    case 0:
      scanf("%d", &valor1);
      scanf("%d", &valor2);
      programaSoma(ram,valor1,valor2);
      memory = retornaRAM(ram); //na memory colocamos a retornaRam com o intuito de dentro da TAD ram só retornar
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
      printf("\n\nO volume do solido = %d\n\n", memory[1]);
    break;

    case 8:
      scanf("%d", &valor1);
      raizquadrada(ram, valor1);
      memory = retornaRAM(ram);
      printf("Raiz quadrada eh = %d\n\n", memory[1]);
    break;

  }

  } while(op!=-1);

  if(op==-1){
    printf("\n---------ENCERRAMENTO---------\n\n");
  }
}
