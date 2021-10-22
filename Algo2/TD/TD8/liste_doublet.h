typedef struct{
    int nb_occ;
    int valeur;
}t_doublet;

void init_liste();
int liste_vide();
int hors_liste();
void en_tete();
void en_queue();
void suivant();
void precedent();
void valeur_elt(t_doublet *v);
void modif_elt(t_doublet v);
void oter_elt();
void ajout_droit(t_doublet v);
void ajout_gauche(t_doublet v);
