gcc memoria.c -c -Wall
gcc endereco.c -c -Wall
gcc mmu.c -c -Wall 
gcc maquina.c -c -Wall 
gcc programa.c -c -Wall
gcc memoria.o endereco.o mmu.o maquina.o programa.o -Wall -o programa
./programa