#include <stdio.h>
#include <stdlib.h>

int compter(FILE *fichier){
    //Fonction qui lit les entiers du fichier et renvoie la somme de ces entiers.
    int somme = 0;
    int lecture;

    fscanf(fichier,"%i", &lecture);
    while(! feof(fichier)){
        somme += lecture;
        fscanf(fichier,"%i", &lecture);
    }

    return somme;
}

int main(void){
    FILE *f = NULL;
    char* nom_fich;
    int somme;

    nom_fich = malloc(sizeof(char) * 250);
    while(1){
        printf("Saisir le nom du fichier à ouvrir : ");
        scanf("%s", nom_fich);
        if( (f = fopen(nom_fich, "r")) != NULL)
            break;
        printf("Ce fichier n'existe pas !\n");
    }
    nom_fich = realloc(nom_fich, sizeof(char) * (strlen(nom_fich) + 1));
    
    somme = compter(f);
    fclose(f);
    f = fopen(nom_fich, "a");
    fprintf(f," %i ", somme);
    fclose(f);

    return 0;
}