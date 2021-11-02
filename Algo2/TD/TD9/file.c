#include <stdlib.h>
#include <stdbool.h>

typedef struct element{
    int valeur;
    struct element *succ;
}t_element;

typedef struct {
    t_element *tete;
    t_element *queue;
}t_file;


void init_file(t_file *l){
    l->tete = NULL;
    l->queue = NULL;
}

bool filevide(t_file *t){
    return (t->queue == NULL && t->tete == NULL);
}

void ajouter(t_file *f, int n){
    t_element *nouv;

    nouv = malloc(sizeof(t_element));
    nouv->valeur = n;
    nouv->succ = NULL;
    if(filevide(f)){
        f->tete = nouv;
    }
    else
        f->queue->succ = nouv;
    f->queue = nouv;
    
}

void retirer(t_file *l, int *v){
    t_element *t;

    if(!filevide(l)){
        t = l->tete;
        *v = t->valeur;
        if(l->queue == l->tete)
            l->queue = NULL;
        l->tete = l->tete->succ;
        free(t);
    }

}

