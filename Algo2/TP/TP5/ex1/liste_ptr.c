#include <stdlib.h>

typedef struct element {
    int valeur;
    struct element *pred;
    struct element *succ;
} t_element;

t_element *drapeau;
t_element *ec;

void init_liste(){
    drapeau = malloc(sizeof(t_element));
    drapeau->pred = drapeau;
    drapeau->succ = drapeau;
    ec = drapeau;
}

int liste_vide(){

    return (drapeau ->pred = drapeau);
}

int hors_liste(){

    return ec == drapeau;
}

void en_tete(){
    if(!liste_vide())
        ec = drapeau->succ;
}

void en_queue(){
    if(!liste_vide())
        ec = drapeau->pred;
}

void suivant(){
    if(!hors_liste())
        ec = ec->succ;
}

void precedent(){
    if(!hors_liste())
        ec = ec->pred;
}

void valeur_elt(int *v){
    if(!hors_liste())
        *v = ec->valeur;
}

void modif_elt(int v){
    if(!hors_liste())
        ec->valeur = v;
}

void oter_elt(){
    t_element *t;

    if (!hors_liste()){ 
        t = ec;
        precedent();
        ec->succ = t->succ;
        (t->succ)->pred = ec;
        free(t);
    } 
}

void ajout_droit(int v){
    t_element *t;

    t = malloc(sizeof(t_element));
    t->valeur = v;
    t->pred = ec;
    t->succ = ec->succ;
    (ec->succ)->pred = t;
    ec->succ = t;
    ec = t;
}

void ajout_gauche(int v){
    t_element *t;

    t = malloc(sizeof(t_element));
    t->valeur = v;
    t->succ = ec;
    t->pred = ec->pred;
    (ec->pred)->succ = t;
    ec->pred = t;
    ec = t;
}