#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifdef _WIN32
#include <windows.h>
#define system("clear") system("cls")
#else
#include <unistd.h>
#endif
    

#define N 80
#define M 50

typedef enum{morte, vivante} t_cellule;

void init_automate(t_cellule automate[M][N]){
    //Fontion qui initialise l'automate cellulaire
    int i, j;

    for(i = 0; i < M; i++)
        for(j = 0; j < N; j++)
            automate[i][j] = morte;
}

void init_mcalcul(int nb_voisins[M][N]){
    //Fontion qui initialise la matrice de calcul
    int i, j;

    for(i = 0; i < M; i++)
        for(j = 0; j < N; j++)
            nb_voisins[i][j] = 0;
}

void lire_fichier(FILE *f, t_cellule automate[M][N]){
    //Fonction qui lit le fichier et charge les cellules vivantes
    int x, y;

    printf("Début de la lecture\n");
    while(! feof(f)){
        fscanf(f, "%i %i", &x, &y);
        printf("La celule %i %i est vivante\n", x ,y);
        automate[y][x] = vivante;
    }
}

int coord_existe(int x, int y){
    //Fonction qui renvoie 1 si les coordonées existent

    return((x >= 0 && x <= N) && (y >= 0 && y <= M));
}

void afficher_automate(t_cellule automate[M][N]){
    //Fonction qui affiche l'automate
    int i,j;

    for(i = 0; i < M; i++){
        for(j = 0; j < N; j++){
            switch (automate[i][j])
            {
            case vivante    : printf(" o"); break;
            case morte      : printf("  "); break;
            }
        }
        putchar('\n');
    }
}

void debug(int mat[M][N]){
    int i, j;

    for(i = 0; i < M; i++){
        for(j = 0; j < N; j++)
            printf("%i", mat[i][j]);
    putchar('\n');
    }
}

void calculer_voisins(t_cellule automate[M][N], int nb_voisins[N][N]){
    //Fonction qui calcule le nombre de voisins de cellules vivantes et l'inscrit
    //dans la matrice de calcul
    int i, j;
    int nb_calcule;

    //Parcours de l'automate
    for(i = 0; i < M; i++){
        for(j = 0; j < N; j++){
                //Tests des cellules voisines

                //En haut à gauche
                if(coord_existe(j - 1, i - 1) == 1 && automate[i - 1][j - 1] == vivante)
                    nb_voisins[i][j] = nb_voisins[i][j] + 1;
                
                //En haut au milieu
                if(coord_existe(j, i - 1) == 1 && automate[i - 1][j] == vivante)
                    nb_voisins[i][j] = nb_voisins[i][j] + 1;

                //En haut à droite
                if(coord_existe(j + 1, i - 1) == 1 && automate[i - 1][j + 1] == vivante)
                    nb_voisins[i][j] = nb_voisins[i][j] + 1;

                //Centre gauche
                if(coord_existe(j - 1, i) == 1 && automate[i][j - 1] == vivante)
                    nb_voisins[i][j] = nb_voisins[i][j] + 1;

                //Centre droit
                if(coord_existe(j + 1, i) == 1 && automate[i][j + 1] == vivante)
                    nb_voisins[i][j] = nb_voisins[i][j] + 1;

                //En bas à gauche
                if(coord_existe(j - 1, i + 1) == 1 && automate[i + 1][j - 1] == vivante)
                    nb_voisins[i][j] = nb_voisins[i][j] + 1;
                
                //En bas au milieu
                if(coord_existe(j, i + 1) == 1 && automate[i + 1][j] == vivante)
                    nb_voisins[i][j] = nb_voisins[i][j] + 1;

                //En bas à droite
                if(coord_existe(j + 1, i + 1) == 1 && automate[i + 1][j + 1] == vivante)
                    nb_voisins[i][j] = nb_voisins[i][j] + 1;


        }
    }
}

void passer_nextgen(t_cellule automate[N][N], int nb_voisins[N][N]){
    //Fonction qui fait passer l'automate à la prochaine génération
    int i,j;

    for(i = 0; i < M; i++){
        for(j = 0; j < N;j++){

            if(automate[i][j] == morte){
                if(nb_voisins[i][j] == 3)
                    automate[i][j] = vivante;
            }
            if(automate[i][j] == vivante)
                if(nb_voisins[i][j] < 2 || nb_voisins[i][j] > 3)
                    automate[i][j] = morte;
        }
    }
}

int main(){
    FILE* f;
    t_cellule automate[M][N];
    int nb_voisins[M][N];
    char *nom_fich = malloc(sizeof(char) * 200);
    int nb_gen;
    int i;

    system("clear");

    //Chargement fichier
    printf("Jeu de la vie\n");
    do{
        printf("Saisir le nom du fichier à ouvrir : ");
        scanf("%s", nom_fich); 
        f = fopen(nom_fich,"r");
        if(f == NULL)
            printf("Ce fichier n'existe pas !\n");    
    }while(f == NULL);
    nom_fich = realloc(nom_fich, sizeof(char) * (strlen(nom_fich) + 1));

//Nombre de générations
     do{
        printf("Saisir le nombre de générations : ");
        scanf("%i", &nb_gen); 
        if(nb_gen < 1)
            printf("Le nombre de générations doit être supérieur ou égal à 1 !\n");
    }while(nb_gen < 1);

    init_automate(automate);
    lire_fichier(f, automate);
    afficher_automate(automate);
    scanf("%*c");
    for(i = 0; i < nb_gen; i++){
        system("clear");
        afficher_automate(automate);
        init_mcalcul(nb_voisins);
        calculer_voisins(automate, nb_voisins);
        passer_nextgen(automate, nb_voisins);
        usleep(10000);
    }

    fclose(f);

    return 0;
}