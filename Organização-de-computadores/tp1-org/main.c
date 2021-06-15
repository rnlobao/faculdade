#include <stdio.h>
#include <stdlib.h>

#include"Menu.h"
#include"Instructions.h"

int main() {
	Memoria *ram;
	ram=montarMemoriaDados();
	menu(ram);
	liberaRam(ram);

	return 0;
}
