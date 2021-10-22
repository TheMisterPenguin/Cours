#include <stdio.h>
#include "liste.h"

void afficher_liste(){
    //Foncton qui affiche l'entierté d'une liste
    int x;

    if(!liste_vide()){
    en_tete();
    while(!hors_liste()){
        valeur_elt(&x);
        printf("| %i |", x);
        suivant();

    }
    putchar('\n');
    }
}

int somme(){
    //Fonction qui renvoie la somme des entiers de la liste
    int somme = 0;
    int x;

    if(!liste_vide()){
        en_tete();
        while(!hors_liste()){
            valeur_elt(&x);
            somme += x;
            suivant();
            }
        }

    return somme;
}

void elever_carre(){
    //Fonction qui élève au carré tousles entiers de la liste
    int x;

    if(!liste_vide()){
    en_tete();
    valeur_elt(&x);
    while(!hors_liste()){
        modif_elt(x * x);
        suivant();
        valeur_elt(&x);
    }
    }
}

void inserer(){
    int i, v;

    printf("Saisir un entier : ");
    scanf("%i", &i);

    if(liste_vide()){
        ajout_droit(i);
    }
    else{
        en_queue();
        valeur_elt(&v);
        if(i >= v)
            ajout_droit(i);
        else{
            en_tete();
            do{
                valeur_elt(&v);
                suivant(); 
            }while(v < i);
            precedent();
            ajout_gauche(i);
       }
    }  
}

void supprimer(int x){
    int v;

    if(!liste_vide()){
        en_queue();
        do{
            valeur_elt(&v);
            if(v == x)
                oter_elt();
            precedent();
        }while(!hors_liste());
    }
}

void vider_liste(){
    if(!liste_vide()){
        en_queue();
        do{
            oter_elt();
            precedent();
        }while(!hors_liste());
    }
}

int main(){
    int i;
    init_liste();

    for(i = 0; i < 10; i = i + 2)
        ajout_droit(i);
    afficher_liste();
    printf("Somme : %i\n", somme());
    //elever_carre();
    inserer();
    afficher_liste();
    return 0;
}