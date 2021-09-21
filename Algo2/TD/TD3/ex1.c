#include <stdio.h>

#define N 8

void init_matrice(char mat[N][N]){
    //Fonction qui initialise la matrice avec des '.'
    int i, j;

    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            mat[i][j] = '.';
    
}

int valides(int x1, int x2){
    //Fonction qui renvoie vrai si les coordonées sont valides

    return ((x1 >= 0 && x1 < N) && (x2 >= 0 && x2 < N));
}

void placer_cavalier(char mat[N][N],int x, int y){
    //Fonction qui place le cavalier dans la matrice
    
    if(valides(x - 1,y - 2))
        mat[y - 2][x - 1] = '*'; 
    if(valides(x - 2,y - 1))
        mat[y - 1][x - 2] = '*'; 
    if(valides(x + 1, y - 2))
        mat[y - 2][x + 1] = '*';  
    if(valides(x + 2,y - 1))
        mat[y - 1][x + 2] = '*'; 
    if(valides(x - 1,y + 2))
        mat[y + 2][x - 1] = '*'; 
    if(valides(x - 2,y + 1))
        mat[y + 1][x - 2] = '*'; 
    if(valides(x + 1, y + 2))
        mat[y + 2][x + 1] = '*';  
    if(valides(x + 2,y + 1))
        mat[y + 1][x + 2] = '*'; 
    mat[y][x] = 'c';
}

void afficher_mat(char mat[N][N]){
    //Fonction qui affiche la matrice
    int i,j;

    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++)
            printf("%c ", mat[i][j]);
        printf("\n");
    }
}

int main(){

    char echequier[N][N];
    int x,y;
    int i;

    init_matrice(echequier);
    printf("Saisir les coordonées (x;y) : ");
    scanf("%i;%i", &x, &y);
    x--;
    y--;

    /*for(i = 0; i < N; i++)
        echequier[i][x] = '*';
    for(i = 0; i < N; i++)
        echequier[y][i] = '*';
    echequier[y][x] = 't';*/
    placer_cavalier(echequier, x, y);
    afficher_mat(echequier);

    return 0;
}