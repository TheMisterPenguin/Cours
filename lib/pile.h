#include <stdbool.h>

#ifndef TYPE_P
    #define TYPE_P int
#endif



typedef struct element {
    TYPE_P val;
    struct element *suiv;
}p_element;

typedef struct {
    p_element *sommet;
    int nb_element;
}pile;

void init_pile(pile *p);

bool pile_vide(pile *p);

void empiler(pile *p, TYPE_P val);

void depiler(pile *p, TYPE_P *val);

void val_sommet(pile *p, TYPE_P *val);

int nb_element(pile *p);
