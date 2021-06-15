all: Instructions.o Menu.o main.c
	gcc -o main main.c Instructions.o Menu.o

Instructions.o: Instructions.c
	gcc -o Instructions.o -c Instructions.c

Menu.o: Menu.c
	gcc -o Menu.o -c Menu.c

clean:
	rm -f *.o main

run:
	./main < input.txt > output.txt
