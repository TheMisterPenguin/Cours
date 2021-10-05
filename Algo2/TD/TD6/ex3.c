#include <stdio.h>
#include <stdbool.h>

#define N 8
#define M 12

#define tmax 500
int file[tmax];
int tete, queue, nb_valeurs;

void init_pile(void){

    nb_valeurs =0;
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

    return (nb_valeurs == 0);
}

bool est_valide(int x, int y){

    if((x >= 0 && x < N) && (y >= 0 && y < M))
        return true;
    else
        return false;
}

bool est_vide(char mat[N][M], int x, int y){

    if(est_valide(x,y) == true){
        if(mat[x][y] == ' ')
            return true;
        else    
            return false;
    }
    else
        return false;
}

void remplissage(char mat[N][M], int x, int y){

    if(est_vide(mat, x, y) == true){
        ajouter(x);
        ajouter(y);
    }
    int i,j;

    while(!filevide()){
        retirer(&i);
        retirer(&j);

        if(est_valide(mat, i - 1, j) == true){
            mat[i - 1][j] = '*';
            ajouter(j-1);
            ajouter(i);
        }
    }
}
