#include <stdio.h>

int main(void){
    FILE *fichier = NULL;
    int sco_Leia;
    int sco_Luke;
    int fsco_Leia;
    int fsco_Luke;

    printf("Donner les points marqués par Leia : ");
    scanf("%i", &sco_Leia);
    printf("Donner les points marqués par Luke : ");
    scanf("%i", &sco_Luke);

    fichier = fopen("scores.txt", "r");

    if(fichier != NULL){
        fichier = fopen("scores.txt", "r");
        fscanf(fichier,"%i %i", &fsco_Leia, &fsco_Luke);
        sco_Leia += fsco_Leia;
        sco_Luke += fsco_Luke;
        printf("Les anciens scores sont : %i pour Leia, %i pour Luke. \n", fsco_Leia, fsco_Luke);
        fclose(fichier);
    }

    printf("Les nouveaaux scores sont : %i pour Leia, %i pour Luke. \n", sco_Leia, sco_Luke);
    fichier = fopen("scores.txt", "w");
    fprintf(fichier,"%i %i", sco_Leia, sco_Luke);
    printf("Le fichier des scores est mis à jour.\n");
    fclose(fichier);

    return 0;

}