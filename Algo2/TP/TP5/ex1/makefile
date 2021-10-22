.PHONY : statique dyn exe liste_statique liste_dyn tp5 

statique : tp5 liste_statique exe

dyn : tp5 liste_dyn exe

exe : tp5.o liste.o
	gcc tp5.o liste.o -o tp5.exe
liste_statique : liste.c
	gcc -c liste.c
liste_dyn : liste.c
	gcc -c liste_ptr.c -o liste.o
tp5 : tp5.c
	gcc -c tp5.c