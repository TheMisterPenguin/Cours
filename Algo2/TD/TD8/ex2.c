#include <stdio.h>
#include <stdbool.h>
#include "liste.h"

void creation(int e, int deb, int fin, int  p){
    int i;

    vider_liste(e);
    for(i = deb; i <= fin; i += p){
        ajout_droit(e,i);
    }

}

bool appartient(int e, int x){
    bool appartient = false;
    int y;

    if(!liste_vide(e)){
        en_tete(e);
        do{
            valeur_elt(e, &y);
            if(x == y) //Constions en plus car liste triée
                return true;
            suivant(e);
        }while(!hors_liste(e));

    }

    return false;
}

bool egaux(int l1, int l2){

    if(cardinal(l1) != cardinal(l2))
        return false;
    while(!hors_liste(l1)){
        
    }
}

