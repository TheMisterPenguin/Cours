#define tmax 50
int liste[tmax];
int queue, ec;

void init_liste(){
    queue = -1;
    ec = -1;
}

int liste_vide(){
    return (queue == -1);
}

int hors_liste(){
    return (ec < 0 || ec > queue);
}

void en_tete(){
    if(!liste_vide())
        ec = 0;
}

void en_queue(){
    if(!liste_vide())
        ec=queue;
}

void suivant(){
    if(!hors_liste())
        ec++;
}

void precedent(){
    if(!hors_liste())
        ec--;
}

void valeur_elt(int *v){
    if(!hors_liste())
        *v = liste[ec];
}

void modif_elt(int v){
    if(!hors_liste())
         liste[ec] = v;
}

void oter_elt(){
    int i;

    if ( ! hors_liste()){ 
        for (i = ec; i<queue; i++) 
            liste[i] = liste[i+1]; 
        ec-- ; // ici, ec est sur le précédent 
        queue-- ; 
 } 
}

void ajout_droit(int v){
    int i;

    if (liste_vide()){ 
        liste[ec+1] = v; 
        ec ++ ; 
        queue ++ ; 
    } 
    else if ( ! hors_liste()){ 
        for(i = queue ; i > ec ;i --) 
            liste[i+1] = liste[i]; 
        liste[ec+1] = v; 
        ec ++ ; 
        queue ++ ; 
 } 
}

void ajout_gauche(int v){
    int i;

    if (liste_vide()){ 
        liste[ec+1] = v; 
        ec ++ ; 
        queue ++ ; 
    } 
    else if ( ! hors_liste()){ 
        for(i = queue ; i >= ec ;i --) 
            liste[i+1] = liste[i]; 
        liste[ec] = v; 
        queue ++ ; 
 } 
}