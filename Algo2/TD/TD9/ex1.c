#include <stdio.h>
#include "file.h"

void afficher_file(t_file *f){
    int entier;

    while(!filevide(f)){
        retirer(f, &entier);
        printf("%i ", entier);
    }
    
}

void parite(t_file *f, t_file *pair, t_file *impair){
    int valeur;

    while(!filevide(f)){
        retirer(f, &valeur);
        if(valeur % 2 == 0)
            ajouter(pair, valeur);
        else
            ajouter(impair,valeur);
    }
}

void saisie(t_file *f){
    int nb;

    do{
        printf("Saisir un entier (-1 pour arreter) : ");
        scanf("%i", &nb);
        if(nb >= 0)
            ajouter(f, nb);
    }while(nb != -1);

}

int main(){
    t_file f;
    t_file p;
    t_file i;

    init_file(&f);
    init_file(&p);
    init_file(&i);

    saisie(&f);

    parite(&f,&p,&i);

    printf("Les eniters pairs sont : ");
    afficher_file(&p);
    printf("et les entiers impairs sont : ");
    afficher_file(&i);
    putchar('\n');

    return 0;
}