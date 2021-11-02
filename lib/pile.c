#include "pile.h"
#include <stdlib.h>
#include <stdbool.h>

void init_pile(pile *p){
    p->nb_element = 0;
    p->sommet = NULL;
}

bool pile_vide(pile *p){
    return (p->sommet == NULL);
}

void empiler(pile *p, TYPE_P val){
    p_element *temp;

    p->nb_element += 1;
    temp = malloc(sizeof(TYPE_P));
    temp->val = val;
    if(pile_vide(p))
        temp->suiv = NULL;
    else    
        temp->suiv = p->sommet;
    p->sommet = temp;
}

void depiler(pile *p, TYPE_P *val){
    p_element *temp;

    if(!pile_vide(p)){
        p->nb_element -= 1;
        temp = p->sommet;
        *val = temp->val;
        if(p->sommet->suiv == NULL)
            init_pile(p);
        else
            p->sommet = temp->suiv;
        free(temp);
    }
}

void val_sommet(pile *p, TYPE_P *val){

    if(!pile_vide(p)){
        *val = p->sommet->val;
    }
}

int nb_element(pile *p){

    return p->nb_element;
}
