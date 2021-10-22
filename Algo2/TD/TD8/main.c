#include <stdio.h>
#include "liste_doublet.h"

void afficher_liste(){
    //Foncton qui affiche l'entierté d'une liste
    t_doublet x;
    int i;

    if(!liste_vide()){
    en_tete();
    while(!hors_liste()){
        valeur_elt(&x);
        for(i = 0; i < x.nb_occ; i++)
            printf("| %i |", x.valeur);
        suivant();
    }
    putchar('\n');
    }
}

void ajout(int x){
    t_doublet t;

    if(liste_vide()){
        t.valeur = x;
        t.nb_occ = 1;
        ajout_gauche(t);
    }
    else {
        en_queue();
        valeur_elt(&t);
        if(x > t.valeur){
            t.valeur = x;
            t.nb_occ = 1;
            ajout_droit(t);
        }
        else if(x == t.valeur){
            t.nb_occ++;
            modif_elt(t);
        }
        else{
            en_tete();
            do{
                valeur_elt(&t);
                suivant(); 
            }while(t.valeur < x);
            precedent();
            if(t.valeur == x){
                t.nb_occ++;
                modif_elt(t);
            }
            else{
                 t.valeur = x;
                t.nb_occ = 1;
                ajout_droit(t);
            }
        }
    }

}

void suppression(int x){
   t_doublet t;
    if(!liste_vide()){
        en_queue();
        do{
            valeur_elt(&t);
            if(t.nb_occ == 1 && t.valeur == x){
                oter_elt();
                break;
            }
            if(t.nb_occ > 1 && t.valeur == x){
                t.nb_occ--;
                modif_elt(t);
                break;
            }
            precedent(); 
        }while(!hors_liste());
    } 
}

float moyenne(){
    int nb_val = 0;
    float moy = 0;
    t_doublet t;

    en_tete();
    do{
        valeur_elt(&t);
        moy += (float)t.valeur;
        nb_val++;
        suivant();
    }while(!hors_liste());

    moy /= (float)nb_val;

    return moy;
}

int main(){
    int i;
    init_liste();


    for(i = 0; i < 10; i++)
        ajout(i);
    for(i = 0; i < 10; i++)
        ajout(i);
    afficher_liste();
    suppression(0);
    afficher_liste();
    printf("Moyenne : %.2f \n", moyenne());
    return 0;
}