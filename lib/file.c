#include "file.h"
#include <stdlib.h>

void init_file(file *p){
    p->nb_element = 0;
    p->tete = NULL;
    p->queue = NULL;
}

bool file_vide(file *p){
    return (p->tete == NULL && p-> queue == NULL);
}

void ajouter(file *f, TYPE_F val){
    f_element *temp;

    f->nb_element += 1;
    temp = malloc(sizeof(TYPE_F));
    temp->val = val;
    temp->suiv = NULL;
    if(file_vide(f)){
        temp->prec = NULL; 
        f->tete = temp;
    }
    else {   
        temp->prec = f->queue;
        f->queue->suiv = temp;
    }
    f->queue = temp;
}

void retirer(file *f, TYPE_F *val){
    f_element *temp;

    if(!file_vide(f)){
        f->nb_element -= 1;
        temp = f->tete;
        *val = temp->val;
        if(f->tete->suiv == NULL)
            init_file(f);
        else
            f->tete = temp->suiv;
        free(temp);
    }
}

void val_tete(file *f, TYPE_F *val){

    if(!file_vide(f)){
        *val = f->tete->val;
    }
}

int nb_element_f(file *f){

    return f->nb_element;
}
