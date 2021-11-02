
typedef union {
    int entier;
    char car;
}t_union;

typedef struct element{
    t_union val1, val2;
    struct element *prec;
    struct element *suiv;
}t_element;

typedef struct {
    t_element *drapeau;
    t_element *ec;
}t_liste;

void init_liste(t_liste *l);
void en_queue(t_liste *l);
void liste_vide(t_liste *l);
void valeur_elt(t_liste *l, t_union *val1, t_union *val2);
void oter_elt(t_liste *l);
void inserer(t_liste *l, t_union val1, t_union val2);
void detruire_liste(t_liste *l);