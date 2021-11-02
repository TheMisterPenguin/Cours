#include <stdbool.h>

#ifndef TYPE_L
    #define TYPE_L int
#endif



typedef struct element_f {
    TYPE_L val;
    struct element_l *suiv;
    struct element_l *prec; 
}l_element;

typedef struct {
    l_element *ec;
    l_element *drapeau;
    int nb_element;
}liste;