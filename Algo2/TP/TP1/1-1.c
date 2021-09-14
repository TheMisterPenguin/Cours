#include <stdio.h>


void creer_fichier(void){
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