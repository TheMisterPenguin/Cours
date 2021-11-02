#include "liste.h"

void trier(t_liste *list){
    t_liste inter;
    int elem;

    init_liste(&inter);
    en_queue(list);
    while(liste_vide(list)){
        valeur_elt(list,&elem);
        oter_elt(list);
        inserer(&inter,elem);
    }
    detruire_liste(list);
    *list = inter;
}