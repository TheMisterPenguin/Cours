#include <stdio.h>

void compter(FILE *fichier, int *nb_caract, int *nb_lignes){
    //Fonction qui compte le nombre de caractères et de lignes du fichier passé en paramètre
    char lecture;

    fscanf(fichier,"%c", &lecture);
    while(! feof(fichier)){
        switch (lecture)
        {
        case ' ' :
            break;
        case '\n' : *nb_lignes = *nb_lignes + 1;
            break;
        default :  *nb_caract = *nb_caract + 1;
            break;
        }
        fscanf(fichier,"%c", &lecture);
    }
    (*nb_lignes)++;

}

int main(int argc, char** argv){
    FILE* fichier = NULL;
    int nb_caract = 0;
    int nb_lignes = 0;

    if(argc < 2){
        printf("Il manque un argument. Il en faut au moins 1.");
        return 1;
    }

    fichier = fopen(argv[1], "r");
    if(fichier == NULL){
        printf("Le fichier \"%s\" n'existe pas ! \n", argv[1]);
        return 2;
    }
    compter(fichier, &nb_caract, &nb_lignes);
    printf("IL y a %i caractères et %i lignes dans le fichier \"%s\"\n", nb_caract, nb_lignes, argv[1]);
    fclose(fichier);

    return 0;
}