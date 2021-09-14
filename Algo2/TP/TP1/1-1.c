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

int main(void){
    creer_fichier();
    return 0;
}