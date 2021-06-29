//Robson Novato Lobao 20.1.4018
#include <stdio.h>
#include <stdlib.h>

#include"Menu.h"
#include"Instructions.h"

//basicamente chama as funçoes na main
int main() {
	Memoria *ram;
	ram=montarMemoriaDados();
	menu(ram);
	liberaRam(ram);

	return 0;
}
