all: sort
	make clean

sort: main.o sortCollection.o
	gcc sortCollection.o main.o -o sort -Wall

main.o: main.c sortCollection.h
	gcc main.c -c -Wall

sortCollection.o: sortCollection.c sortCollection.h
	gcc sortCollection.c -c -Wall

clean:
	rm -f *.o *~ 