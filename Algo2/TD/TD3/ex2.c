#include <stdio.h>

#define N 11
#define M 7

void afficher_matrice(int mat[M][N]){
    //Fonction qui affiche la matrice non formatée
    int i,j;

    for(i = 0; i < M; i++){
        for(j = 0; j < N; j++)
            printf("%+i", mat[i][j]);
        putchar('\n');
    }    
}

void afficher_matricef(int mat[M][N]){
    //Fonction qui affiche la matrice formatée
    int i,j;

    for(i = 0; i < M; i++){
        for(j = 0; j < N; j++){
            switch(mat[i][j]){
                case -1 : printf("|*"); break;
                case -2 : printf("|."); break;
                default : printf("| "); break;
            } 
        }
        printf("|\n");
    }    
    putchar('\n');
}

int valides(int x, int y){
    //Fonction qui revoie vrai si les coordonées désignent une case valide

    return ((x >= 0 && x <= N) && (y >= 0 && y <= M));
}

int est_vide(int mat[M][N], int x, int y){
    //Fonction qui renvoie vrai si les coordonées sont valides et désignent un couloir

    if(valides(x,y))
        return(mat[y][x] == 0);
        
    return 0;
}

void chercher_chemin(int mat[M][N], int xd, int yd, int xa, int ya){
    //Fonction qui cherche la fin du labyrinthe
    int i, j;
    int cptr = 0;

    mat[yd][xd] = 1;
    while(mat[ya][xa] == 0){
        cptr++;
        for(i = 0; i < M; i++){
            for(j = 0; j < N; j++){
                if(mat[i][j] == cptr){

                    //Ligne dessus
                    if(est_vide(mat, j, i - 1) == 1 && mat[i - 1][j] < cptr + 1) // - o -
                        mat[i - 1][j] = cptr + 1;

                    //Ligne milieu
                    if(est_vide(mat, j - 1, i) == 1 && mat[i][j - 1] < cptr + 1) // o - -
                        mat[i][j - 1] = cptr + 1;
                    if(est_vide(mat, j + 1, i) == 1 && mat[i][j + 1] < cptr + 1) // - - o
                        mat[i][j + 1] = cptr + 1;

                    //Ligne dessous
                    if(est_vide(mat, j, i + 1) == 1 && mat[i + 1][j] < cptr + 1) // - o -
                        mat[i + 1][j] = cptr + 1;
                }
            }
        }
    }
}

void marquer_chemin(int mat[M][N],int xa,int ya){
    //Fonction qui cherche le chemin le plus court de l'arrivée au départ
    int i, arret;
    int px = xa, py = ya;

    for(i = mat[ya][xa]; i >0; i--){
        //Ligne dessus
        if(valides(px, py - 1) == 1 && mat[py - 1][px] == i - 1) // - o -
            mat[--py][px] = -2;
        else{
            //Ligne milieu
            if(valides(px - 1, py) == 1 && mat[py][px - 1] == i - 1) // o - -
                mat[py][--px] = -2;
            else{
                if(valides(px + 1, py) == 1 && mat[py][px + 1] == i - 1) // - - o
                    mat[py][++px] = -2;
                else{
                    //Ligne dessous
                    if(valides(px, py + 1) == 1 && mat[py + 1][px] == i - 1) // - o -
                        mat[++py][px] = -2;
                }
            }
        }
        printf("Coordonées : %i/%i\n", px + 1, py + 1);
    }
}

void nettoyer(int mat[M][N]){
    //Fonction qui parcourt la matrice et remplace toutes les valeurs positives par des zéros
    int i,j;

    for(i = 0; i < M; i++)
        for(j = 0; j < N; j++){
            if(mat[i][j] >= 0)
                mat[i][j] = 0;
        }
}

int main(){
    int mat[M][N] = {{ 0,-1, 0, 0, 0,-1, 0, 0, 0, 0, 0},
                     { 0,-1,-1,-1, 0,-1, 0,-1,-1,-1, 0},
                     { 0, 0, 0, 0, 0,-1, 0, 0, 0,-1, 0},
                     {-1,-1,-1,-1, 0,-1,-1,-1, 0,-1, 0},
                     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     { 0,-1, 0,-1,-1,-1,-1,-1, 0,-1, 0},
                     { 0,-1, 0, 0, 0, 0, 0, 0, 0,-1, 0}};
    afficher_matricef(mat);
    chercher_chemin(mat, 0, 0, 10, 7);
    afficher_matricef(mat);
    marquer_chemin(mat, 10, 7);
    nettoyer(mat);
    afficher_matrice(mat);
    afficher_matricef(mat);
    return 0;
}