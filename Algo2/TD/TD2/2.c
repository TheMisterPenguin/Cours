#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


#define NB_CARTES 52
#define TAILLE_MAIN 13

typedef enum{deux, trois, quatre, cinq, six , sept, huit, neuf, dix, valet, dame, roi, as} hauteur;
typedef enum{pique, trefle, coeur, carreau} couleur;

typedef struct {
    hauteur h;
    couleur c;
} t_carte;

void afficher_carte(t_carte c){
    //Fonction qui affiche le nom réel de la carte passée en paramètre
    char *couleur[4] = {"pique", "trèfle", "coeur", "carreau"};
    char *hauteur[13] = {"Deux", "Trois", "Quatre", "Cinq", "Six", "Sept", "Huit", "Neuf", "Dix", "Valet", "Dame", "Roi", "As"};

    printf("%s de %s\n", hauteur[c.h], couleur[c.c]);

}

void initialiser(t_carte table[]){
    //Fonction qui initialise le jeu de cartes
    int i;
    int y;
    int compteur = 0;

    for(i = pique; i <= carreau; i++){
        for(y = deux; y <= as; y++){
            table[compteur].h = y;
            table[compteur].c = i;
            compteur++;
        }
    }
}

void melanger(t_carte table[]){
    //Fonction qui mélange toutes les cartes
    t_carte carte_selec;
    int i;
    int indice;

    for (i = 0; i < NB_CARTES; i++){
        carte_selec = table[i];
        indice = rand() % (NB_CARTES - 1);
        table[i] = table[indice];
        table[indice] = carte_selec;
    }
}

void distribuer(t_carte jeu_carte[], t_carte j1[], t_carte j2[], t_carte j3[], t_carte j4[]){
    //Fonction qui distribue le paquet de carte aux quatres joueurs
    int nb_carte = 0;
    int nb_carte_j1 = 0;
    int nb_carte_j2 = 0;
    int nb_carte_j3 = 0;
    int nb_carte_j4 = 0;

    while(nb_carte < NB_CARTES){
        j1[nb_carte_j1].c = jeu_carte[nb_carte].c;
        j1[nb_carte_j1].h = jeu_carte[nb_carte].h;
        nb_carte++;
        nb_carte_j1++;
        j2[nb_carte_j2].c = jeu_carte[nb_carte].c;
        j2[nb_carte_j2].h = jeu_carte[nb_carte].h;
        nb_carte++;
        nb_carte_j2++;
        j3[nb_carte_j3].c = jeu_carte[nb_carte].c;
        j3[nb_carte_j3].h = jeu_carte[nb_carte].h;
        nb_carte++;
        nb_carte_j3++;
            if(nb_carte >= NB_CARTES)
                break;
        j4[nb_carte_j4].c = jeu_carte[nb_carte].c;
        j4[nb_carte_j4].h = jeu_carte[nb_carte].h;
        nb_carte++;
        nb_carte_j4++;
    }
}

int est_inferieur(t_carte c1, t_carte c2){
    //Fonction qui renvoie 1 si la carte 1 est inférieure a la carte 2

    if(c1.c < c2.c)
        return 1;
    else{
        if(c1.h < c2.h)
            return 1;
    }

    return 0;
}

void trier(t_carte t[]){
    //Fonction qui trie la main du joueur à l'aide d'un trie bulle
    int i;
    int j;
    t_carte x;

    for(i = 0; i < TAILLE_MAIN; i++){
        for(j = TAILLE_MAIN - 1; j > i; j--){
            if(est_inferieur(t[j], t[j - 1])){
                x = t[j];
                t[j] = t[j - 1];
                t[j - 1] = x;
            }
        }
    }

}
int main(void){
    srand(time(0));
    t_carte j1[TAILLE_MAIN];
    t_carte j2[TAILLE_MAIN];
    t_carte j3[TAILLE_MAIN];
    t_carte j4[TAILLE_MAIN];
    t_carte jeu[NB_CARTES];

    SetConsoleOutputCP(65001);
    system("cls");
    initialiser(jeu);
    t_carte c = {as, pique};
    int i;
   /* for(i = 0; i < NB_CARTES; i++){
        afficher_carte(jeu[i]);
    }
    scanf("%*c");
    system("cls");*/
    melanger(jeu);
    /*for(i = 0; i < NB_CARTES; i++){
        afficher_carte(jeu[i]);
    }*/

    distribuer(jeu, j1, j2, j3, j4);

    printf("\n \n");

        printf("\n Joueur Suivant\n");
        for(i = 0; i < TAILLE_MAIN; i++){
            afficher_carte(j1[i]);
        }
        printf("\n Joueur Suivant\n");
        for(i = 0; i < TAILLE_MAIN; i++){
            afficher_carte(j2[i]);
        }
        printf("\n Joueur Suivant\n");
        for(i = 0; i < TAILLE_MAIN; i++){
            afficher_carte(j3[i]);
        }
        printf("\n Joueur Suivant\n");
        for(i = 0; i < TAILLE_MAIN; i++){
            afficher_carte(j4[i]);
        }
        


    
}