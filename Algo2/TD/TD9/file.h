#include <stdbool.h>

typedef struct element{
    int valeur;
    struct element *succ;
}t_element;

typedef struct {
    t_element *tete;
    t_element *queue;
}t_file;


void init_file(t_file *l);

bool filevide(t_file *t);

void ajouter(t_file *f, int n);

void retirer(t_file *l, int *v);

