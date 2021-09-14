#include <stdio.h>


void creer_fichier(void){
    //Fonction qui lit une suite de chiffres et l'enregistre dan le fichier donnees.txt
    FILE *fichier;
    int nombre;
    
    fichier = fopen("donnees.txt", "w");
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

    f = fopen("donnees.txt", "r");
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