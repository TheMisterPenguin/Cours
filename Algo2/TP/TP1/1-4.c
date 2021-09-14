#include <stdio.h>
#include <stdlib.h>


char *saisie_nom(){
    //Fonction qui revoie la chaine de caractère saisie
    char* nom;

    nom = malloc(sizeof(char) * 250);
    scanf("%s", nom);
    nom = realloc(nom, sizeof(char) * (strlen(nom) + 1));

    return nom;
}

void creer_fichier(void){
    //Fonction qui lit une suite de chiffres et l'enregistre dan le fichier donnees.txt
    FILE *fichier;
    int nombre;
    
    printf("Saisir le nom du fichier à créer : ");
    fichier = fopen(saisie_nom(), "w");
    printf("Saisir un nombre (-1 pour arreter) : ");
    scanf("%i", &nombre);
    while(nombre != -1){
        fprintf(fichier, " %i ", nombre);
        printf("Saisir un nombre (-1 pour arreter) : ");
        scanf("%i", &nombre);
    }
    
    fclose(fichier);
    
}

void afficher_fichier(void){
    //Fonction qui affiche le contenu du fichier donnees.txt à l'écran
    FILE *f;
    int tampon;

    printf("Saisir le nom du fichier à afficher : ");
    f = fopen(saisie_nom(), "r");
    fscanf(f, "%i", &tampon);
    printf("Voici ce qui se trouve dans le fichier donnees.txt\n");
    while(! feof(f)){
        printf(" %i ", tampon);
        fscanf(f, "%i", &tampon);
    }
    fclose(f);
}

int main(void){
    creer_fichier();
    afficher_fichier();
    return 0;
}