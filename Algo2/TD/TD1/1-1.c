#include <stdio.h>

int estPair(int nb){
    //Fonction qui renvoie vrai si le nombre nb est estPair

    return (nb % 2);
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
    int test_val;
    int resultat = 0 ;

    f = fopen("nombres.txt", "r");
    fscanf(f,"%i", &test_val);

    while(! feof(f)){
        resultat += estPair(test_val);
        fscanf(f,"%i", &test_val);
    }

    printf("Le fichier contient %i entiers pairs\n", resultat);
    fclose(f);
    
    return 0;
}