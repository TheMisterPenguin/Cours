
typedef struct element{
    int val;
    struct element *prec;
    struct element *suiv;
}t_element;

typedef struct {
    t_element *drapeau;
    t_element *ec;
}t_liste;

init_liste(t_liste *l);
en_queue(t_liste *l);
liste_vide(t_liste *l);
valeur_elt(t_liste *l, int *n);
oter_elt(t_liste *l);
inserer(t_liste *l, int n);
detruire_liste(t_liste *l);