// DESPERT Ange
// Le Mans Université
// Github : https://github.com/TheMisterPenguin/Cours

#include <stdio.h>
#include <string.h>

int conversion(char c){
    switch (c) {	// Conversion des lettres en fonction de leur valeur
        case 'M' : return 1000;
        case 'D' : return  500;
        case 'C' : return  100;
        case 'L' : return   50;
        case 'X' : return   10;
        case 'V' : return    5;
        case 'I' : return    1;
        default  : return   -1;
    }
}

int nombre(char *nb){;
    int nombre, i, temp;
    for(i = strlen(nb) - 2, nombre = conversion(nb[strlen(nb) - 1]); i >= 0; i--){ // On parcourt la chaine
        if((temp = conversion(nb[i])) < conversion(nb[i+1])) // Si nb(gauche) < nb(droit) <=> I < V
            nombre -= temp;
        else
            nombre += temp;
    }
    return nombre;
}

int main(int argc,char *argv[]){
    int i, somme, nb; 
    nb = nombre(argv[1]); // On commence avec le 1er argument
    somme = nb;
    printf("%d", nb);
    for(i = 2; i < argc; i++){ // Arguments suivants
        nb = nombre(argv[i]);
        printf(" + %d", nb);
        somme += nb;
    }
    printf(" = %d\n", somme);
    return 0;
}