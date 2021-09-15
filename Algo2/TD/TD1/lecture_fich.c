#include <stdio.h>
#include <stdlib.h>
#include <synchapi.h>

#define N 50

void afficherf(FILE *f){
    //Fonction qui affiche l'entièreté d'un fichier;
    char tampon;

    fscanf(f,"%c", &tampon);
    while(! feof(f)){
        printf("%c", tampon);
        fscanf(f,"%c", &tampon);
    }
}

int main(void){
    FILE *f1;
    FILE *f2;
    int i;

    
//srand() % (b_sup-b_inf +1)
    for(i = 0; i < N; i++){
        f1 = fopen("lapin1.txt", "r");
        f2 = fopen("lapin2.txt", "r");
        system("cls");
        afficherf(f1);
        Sleep(1000);
        system("cls");
        afficherf(f2);
        Sleep(1000);
        fclose(f1);
        fclose(f2);
    }

    
    return 0;
}
