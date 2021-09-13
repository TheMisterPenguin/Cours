#include <stdio.h>

//Sleep synchapi.h void sleep(DWORD dwMilliseconds)

int main(void){
    FILE *fichier = NULL;
    int nombre;
    char *nom_fichier;

    system("cls");
    printf("Saisir le nom du ficher à modifier : ");
    scanf("%s", nom_fichier);
    printf("Saisir le nombre à ajouter : ");
    scanf("%i", &nombre);
    fichier = fopen(nom_fichier, "a");
    fprintf(fichier, " %i \n", nombre);
    fclose(fichier);

    return 0;
}