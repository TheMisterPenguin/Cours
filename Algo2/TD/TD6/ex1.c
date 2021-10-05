#include <stdlib.h>
#include <stdbool.h>


typedef struct element {
    int nombre;
    struct element *precedent;
    struct element *suivant;
}t_element;

t_element *tete;
t_element *queue;

void init_deque(){
    //Fonction qui initialise la deque

    tete = NULL;
    queue = NULL;

}

int deque_vide(){
    //Renvoie vrai si la deque est vide

    return (tete == NULL);

}

void ajouter_tete(int v){
    //Fonction qui ajoute v à la tête de la deque
    t_element *temp;

    temp = malloc(sizeof(t_element));
    temp -> nombre = v;

    if(deque_vide()){
        temp -> suivant = NULL;
        queue = temp;
    }
    else{
        temp -> suivant = tete;
        tete ->precedent = temp;
    }
    temp -> precedent = NULL;
    tete = temp;

}

void oter_tete(int *v){
    //Fonction qui retire une valeur de la deque 
    int n;
    t_element *p;

    if(!deque_vide()){
        n = tete ->nombre;
        p = tete;
        tete = tete ->suivant;
        tete -> precedent = NULL;
        free(p);
    }

    *v = n;
}

void ajouter_queue(int v){
    //Fonction qui ajoute v à la queue de la deque
    t_element *temp;

    temp = malloc(sizeof(t_element));
    temp -> nombre = v;

    if(deque_vide()){
        temp -> precedent = NULL;
        tete = temp;
    }
    else{
        temp -> precedent = queue;
        queue ->suivant = temp;
    }
    temp -> suivant = NULL;
    tete = temp;

}

void oter_queue(int *v){
    //Fonction qui retire une valeur de la deque 
    int n;
    t_element *p;

    if(!deque_vide()){
        n = queue ->nombre;
        p = queue;
        queue = queue ->precedent;
        queue -> suivant = NULL;
        free(p);
    }

    *v = n;
}
