fourmis.exe: listesF.o fourmis.o
	gcc fourmis.o listesF.o -o fourmis.exe
fourmis.o: fourmis.c listesF.h
	gcc -c fourmis.c
listesF.o: listesF.c listesF.h
	gcc -c listesF.c

