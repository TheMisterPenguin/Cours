#include <stdio.h>

#define N 7
#define M 11

#define tmax 50

int file[tmax];
int nb_valeurs;
int tete;
int queue;

void afficher_matrice(int mat[N][M]){
    //Fonction qui affiche la matrice non formatée
    int i,j;

    for(i = 0; i < N; i++){
        for(j = 0; j < M; j++)
            printf("%+i", mat[i][j]);
        putchar('\n');
    }    
}

void initfile(void){

    nb_valeurs = 0;
    tete = 0;
    queue = tmax - 1;
}

void ajouter(int v){


    if(nb_valeurs < tmax){
        if(queue == tmax - 1)
            queue = 0;
        else
            queue++;
        file[queue] = v;
        nb_valeurs++;
    }
}

void retirer(int *v){

    if(nb_valeurs > 0){
        *v = file[tete];
        nb_valeurs--;
        if(tete == tmax - 1)
            tete = 0;
        else    
            tete++;
    }
}

int filevide(void){
    return(nb_valeurs == 0);
}

int valides(int y, int x){

    return ((x >= 0 &&  x < N) && (y >= 0 && y < M));
}

int est_vide(int val, int comp){
    return ((val > comp - 1) ||(val == 0));
}

void marquer_chemin(int mat[N][M],int py,int px, int comp){
    //Fonction qui cherche le chemin le plus court de l'arrivée au départ
    printf("traitement\n");
    //Haut
    if(valides(px, py - 1) && est_vide(mat[py - 1][px], comp)){ // - o -
        mat[--py][px] = comp;
        ajouter(py);
        ajouter(px);
    }

    //Gauche
    if(valides(px - 1, py) && est_vide(mat[py][px - 1], comp)){ // o - -
        mat[py][--px] = -2;
        ajouter(py);
        ajouter(px);
    }

    //Droite
    if(valides(px + 1, py) && est_vide(mat[py][px + 1], comp)){ // - - o
        mat[py][++px] = -2;
        ajouter(py);
        ajouter(px);
    }

    //Bas
    if(valides(px, py + 1) && est_vide(mat[py + 1][px], comp)){ // - o -
        mat[++py][px] = -2;
        ajouter(py);
        ajouter(px);
    }
            

    
}

int chercher_chemin(int mat[N][M],int xd, int yd, int xa, int ya){
    initfile();
    int compteur = 0;
    int x,y;
    mat[xd][yd] = compteur;
    ajouter(xd);
    ajouter(yd);
    while (! filevide()){
        if(filevide())
            return 0;
        retirer(&x);
        retirer(&y);
        if(x == xa && y == ya)
            break;
        marquer_chemin(mat, x, y, ++compteur);
    }
    
    return 1;
}

int WinMain(){
    int mat[N][M] = {{ 0,-1, 0, 0, 0,-1, 0, 0, 0, 0, 0},
                     { 0,-1,-1,-1, 0,-1, 0,-1,-1,-1, 0},
                     { 0, 0, 0, 0, 0,-1, 0, 0, 0,-1, 0},
                     {-1,-1,-1,-1, 0,-1,-1,-1, 0,-1, 0},
                     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     { 0,-1, 0,-1,-1,-1,-1,-1, 0,-1, 0},
                     { 0,-1, 0, 0, 0, 0, 0, 0, 0,-1, 0}};

    afficher_matrice(mat);
    printf("\n--------------------------\n\n");
    printf("%i\n",chercher_chemin(mat, 0, 0, 6, 10));
    afficher_matrice(mat);
    return 0;
}
