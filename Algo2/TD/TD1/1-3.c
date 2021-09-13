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

int main(void){
    diviseurs div;
    int i;
    int nombre;

   printf("Saisir un nombre strictement positif : ");
    scanf("%i", &nombre);
    div.taille = 0;
    for(i = 1; i <= nombre; i++){
        if(estDiviseur(nombre, i) == 1) {
            div.liste_div[div.taille] = i;
            div.taille++;
        }
    }

}