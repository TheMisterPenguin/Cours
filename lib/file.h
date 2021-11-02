#include <stdbool.h>

#ifndef TYPE_F
    #define TYPE_F int
#endif



typedef struct element_f {
    TYPE_F val;
    struct element_f *suiv;
    struct element_f *prec; 
}f_element;

typedef struct {
    f_element *tete;
    f_element *queue;
    int nb_element;
}file;

void init_file(file *p);

bool file_vide(file *p);

void ajouter(file *p, TYPE_F val);

void retirer(file *p, TYPE_F *val);

void val_tete(file *p, TYPE_F *val);

int nb_element_f(file *p);
