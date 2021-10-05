#include <stdlib.h>
#include <stdio.h>




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
    t_element *p;

    if(!deque_vide()){
        
        *v = tete ->nombre;
        p = tete;
        if(!(tete->suivant == NULL)){
            tete = p ->suivant;
            tete -> precedent = NULL;
        }
        else{
            tete = NULL;
            queue = NULL;
        }
        free(p);
    }
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
    queue= temp;

}

void oter_queue(int *v){
    //Fonction qui retire une valeur de la deque 
    t_element *p;

    if(!deque_vide()){
        *v = queue ->nombre;
        p = queue;
        if(!(queue->precedent == NULL)){
            queue = p ->precedent;
            queue -> suivant = NULL;
        }
        else{
            tete = NULL;
            queue = NULL;
        }
        free(p);
    }
}

int main(void){
    int x,y;

    init_deque();
    printf("%i\n", deque_vide());
    ajouter_queue(5);
    ajouter_queue(4);
    oter_queue(&x);
    oter_queue(&y);
    printf("%i %i\n", x, y);


    return 0;
}

