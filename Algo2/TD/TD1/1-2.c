#include <stdio.h>
#include <stdlib.h>

int estPair(int nb){
    //Fonction qui renvoie vrai si le nombre nb est estPair

    return (nb % 2);
}

char* nomFichier(void){
    //Fonction qui récupère la ne nom du fichier saisi au clavier
    char* nom;

    nom = malloc(sizeof (char) * 200);
    printf("Saisir le nom du fichier : ");
    scanf("%s", nom);
    nom = realloc(nom, sizeof (char) * (strlen(nom) + 1));

    return nom;
}


int chargerFich(FILE* fich){
    //Fonction qui charge ouvre le fichier fich

    fich = fopen("nombres.txt", "r");
    return (fich == NULL);
}

void affResultat(int nb_pair, FILE* fich){
    //Fonction qui affiche le résultat du programme et qui ferme le fichier

    printf("Le fichier contient %i entiers pairs\n", nb_pair);
    fclose(fich);
}

int lecture(FILE* fich){
    //Fonction qui lit le fichier et qui revoie le nombre d'entiers pairs
    int test_val;
    int resultat = 0;
    
    fscanf(fich,"%i", &test_val);
    while(! feof(fich)){
        resultat += estPair(test_val);
        fscanf(fich,"%i", &test_val);
    }

    return resultat;
}

int main(void){
    FILE* f;
    char* nom_f;
    int test_val;
    int resultat = 0 ;

    while(1){
        nom_f = nomFichier();
        f = fopen(nom_f, "r");
        if(f != NULL)
            break;
        printf("Ce fichier n'existe pas.\n");
    }
    
    fscanf(f,"%i", &test_val);

    while(! feof(f)){
        resultat += estPair(test_val);
        fscanf(f,"%i", &test_val);
    }

    printf("Le fichier contient %i entiers pairs\n", resultat);
    fclose(f);
    
    return 0;
}