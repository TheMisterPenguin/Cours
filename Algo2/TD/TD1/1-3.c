#include <stdio.h>

#define N 50

typedef struct{
    int liste_div[N];
    int taille;
}diviseurs;

int estDiviseur(int nb, int test){
    //Fonction qui renvoie 1 si test est un diviseur de nb

    return (nb % test);
}

void afficherTable(diviseurs d, FILE* f){
    //Fonction qui affiche le tableau de diviseurs
    int i;

    f = fopen("diviseurs.txt","w");
    for(i = 0; i < d.taille; i++)
        fprintf(f," %i ", d.liste_div[i]);
    fprintf(f," \n");
    fclose(f);
    
}

int main(void){
    FILE* f = NULL;
    diviseurs div;
    int i;
    int nombre;

   printf("Saisir un nombre strictement positif : ");
    scanf("%i", &nombre);
    div.taille = 0;
    for(i = 1; i <= nombre; i++){
        if(estDiviseur(nombre, i) == 0) {
            div.liste_div[div.taille] = i;
            div.taille++;
        }
    }
    afficherTable(div, f);

    return 0;
}