all: matrice

matrice: matrice.o main.o
	gcc -o matrice matrice.o main.o

matrice.o: matrice.c
	gcc -o matrice.o -c matrice.c -W -Wall

main.o: main.c matrice.h
	gcc -o main.o -c main.c -W -Wall

clean:
	rm -rf *.o