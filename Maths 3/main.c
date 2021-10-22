#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"

int main()
{
    double A[N][N]= {{0,2,1,0.5},{1,3,0,1.5},{0.5,-2,1,-.5},{-.5,0,-2,0.5}};
    double B[N][N]= {{1,-2,.11,-0.57},{2,2.37,1,0},{0,-5.12,1.6,-.25},{1.5,8,6548,0.7}};
    double R[N][N];

    //printf("Matrice A :\n");
    //afficherMatrice(A);
    /*printf("\nMatrice B : \n");
    afficherMatrice(B);
    somme2Matrices(A, B, R);
    produitReelMatrice(-1,A,R);
    produit2Matrices(A,B,R);*/
    //copieMatrice(A,R);
    /*printf("\nResultat :\n");
    afficherMatrice(R);
    creerIdentite(R);
    printf("\nIndentité :\n");
    afficherMatrice(R);*/
    //permuterLignes(R,0,3);
    //diviserLigneMatrice(R,0,2);
    inversionPivotGauss(B,R);
    printf("\nResultat :\n");
    //afficherMatrice(R);

    return 0;
}
