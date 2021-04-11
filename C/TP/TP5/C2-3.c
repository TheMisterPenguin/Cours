// DESPERT Ange
// Le Mans Université
// Github : https://github.com/TheMisterPenguin/Cours

#include <stdio.h>

enum {NORD, EST, SUD, OUEST};

typedef struct {
    int x; // Coordonnées
    int y;
    int dir; // Direction : NORD EST SUD OUEST
} tortue;

int conv_nombre(char *chaine){
    int i, nb = 0;
    for(i = 0; chaine[i] != '\0'; i++){
        nb *= 10; // Décalage vers la gauche
        nb += chaine[i] - '0';
    }
    return nb;
}

void placer(FILE *f, tortue* tor, int x, int y, int dir){
    fprintf(f, "%d %d moveto\n", x, y); // Placement fichier
    tor->x = x; // Placement programme
    tor->y = y;
    tor->dir = dir;
}

void tourner_droite(tortue* tor){
    if(tor->dir == OUEST) // Prise en compte du cas OUEST -> NORD
        tor->dir = NORD;
    else    
        (tor->dir)++;
}

void tourner_gauche(tortue* tor){
    if(tor->dir == NORD) // Prise en compte du cas NORD -> OUEST
        tor->dir = OUEST;
    else    
        (tor->dir)--;
}

void avancer (FILE *f, tortue *tor, int deplact){
    switch(tor->dir) {
        case NORD   : tor->y += deplact; break;	// En fonction de la direction
        case EST    : tor->x += deplact; break;
        case SUD    : tor->y -= deplact; break;
        case OUEST  : tor->x -= deplact; break;      
    }
    fprintf(f, "%d %d lineto", tor->x, tor->y); // Avancement fichier
}

int main(int argc, char* argv[]){
    FILE *f = fopen(argv[1], "w"); // Création et ouverture du fichier passé en argument
    tortue t;
    int i;
    int fwd = 10;
    int input = conv_nombre(argv[2]); // On récupère le second argument converti en nombre
    fprintf(f,"%% !postscript\n"); // Début du fichier postscript
    placer(f, &t, 100, 100, OUEST); // Position de base de la tortue
    for(i = 0; i < input; i++){ // Création de l'objet
        avancer(f, &t, fwd);
        tourner_droite(&t);
        fwd += 5;
    }
    fprintf(f,"stroke\nshowpage\n"); // Fin du fichier postscript
    fclose(f); // Fermeture du fichier
    return 0;
}