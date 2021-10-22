#include <stdio.h>
#include <stdbool.h>
//#define DEBUG
#define N 4

bool estNul(double x){

    return (x > -1e-6 && x < 1e-6);
}

void afficherMatrice(double A[N][N]){
    //Affiche la matrice
    int i,j;

    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++)
            printf(" %- 9.3f ", A[i][j]);
        putchar('\n');
    }


}

void somme2Matrices(double A[N][N], double B[N][N], double resultat[N][N]){
    //Effectue la somme de deux matrices
    int i,j;

    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            resultat[i][j] = A[i][j] + B[i][j];

}

void produitReelMatrice(double r, double A[N][N], double resultat[N][N]){
    //Réalise le porduit de la matrice par un réel;
    int i,j;

    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            resultat[i][j] = A[i][j] * r;   

}

void produit2Matrices(double A[N][N], double B[N][N], double resultat[N][N]){
    //Réalise le produit de deux matrices
    int i,j, k;


    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++){
            resultat[i][j] = 0;
            for(k = 0; k < N; k++){
                resultat[i][j] += A[i][k] * B[k][j];

                #ifdef DEBUG
                printf("\nk : %i, i: %i, j: %i\n", k,i,j);
                printf("A :%f/B : %f\n", A[j][k], B[k][i]);
                #endif

            }

            #ifdef DEBUG 
            printf("\n--------------\n");
            #endif

        } 
}

void copieMatrice(double A[N][N], double copie[N][N]){
      int i,j;

    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            copie[i][j] = A[i][j];   

}

void creerIdentite(double id[N][N]){
    int i,j;

    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++){
            if(i == j)
                id[i][j] = 1;
            else  
                id[i][j] = 0;
        }     
}

void permuterLignes(double A[N][N], int l1, int l2){
    int i,j;
    double ligne[N];

        for(j = 0; j < N; j++){
            ligne[j] = A[l1][j];
            A[l1][j] = A[l2][j];
            A[l2][j] = ligne[j];
        }     

}

bool chercher_ligne(double ligne[N]){
    int i;

    for(i = 0; i < N; i++)
        if(estNul(ligne[N]))
            return false;
    
    return true;
}

void soustraire_lignes(double L1[N], double L2[N]){
    int i;

    for(i = 0; i < N; i++)
        L1[i] -= L2[i];
}

void diviserLigneMatrice(double A[N][N], int ligne, double a){
    int i;

    if(!estNul(a)){
        for(i = 0; i < N; i++)
            A[ligne][i] /= a;
    }
}

void produitLigne(double L[N], int r){
    int i;

    for(i = 0; i < N; i++)
        L[i] *= r;
}

void inversionPivotGauss(double AOriginal[N][N], double resultat[N][N]){
    double A[N][N];
    int r,i,j;
    bool ligne_existe = false;

    copieMatrice(AOriginal, A);
    afficherMatrice(A);
    creerIdentite(resultat);

    printf("Initialisation du pivot\n");
    i = -1;
    r = -1;
    for(j = 0; j < N; j++){
        printf("r = %i, i = %i, j = %i\n", r,i,j);
        //Recherche de la ligne
        printf("Recherche de la ligne\n");
        for(i = r + 1; i < N && estNul(A[i][j]); i++); //Première ligne ou A[i][j] != 0
        printf("Ligne %i trouvée\n", i);
        if(i < N){
            r += 1;

            permuterLignes(A,r,i);
            //permuterLignes(resultat,r,i);

            diviserLigneMatrice(A,r,A[r][j]); //Normalisation du pivot
            //diviserLigneMatrice(resultat,r,resultat[r][j]);

            for(i = 0; i < N; i++){ //Elimination dans les autres lignes
                if(i != r){ //On annule A[i][j]

                    //Forme échelonnée réduite
                    produitLigne(A[r], A[i]); 
                    soustraire_lignes(A[i], A[r]);

                    //resultat
                    //produitLigne(resultat[r], resultat[i]);
                    //soustraire_lignes(resultat[i], resultat[r]);

                }
            }
        }
    }
    printf("test\n");
    afficherMatrice(A);
}
