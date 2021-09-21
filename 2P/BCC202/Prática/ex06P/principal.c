#include "pilha.h"
#include <stdio.h>
#include <string.h>

int main()
{
        Pilha pilha;
        char ch;
        Item item;

        int contador1 = 0, contador2 = 0;
        Pilha_Inicia(&pilha);

        while (scanf("%c", &ch)!=EOF)
        {
          Pilha_Push(&pilha, ch);
          if (ch == '(') {
            contador1++;
          }
          else if (ch == ')') {
            contador2++;
          }
        }
        if (contador1 == contador2) {
          printf("correto");
        }
        else {
          printf("incorreto");
        }

        Pilha_Esvazia(&pilha);

        return 0;//nao remova
}
