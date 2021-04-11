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
    FILE *f = fopen(argv[1], "w"); // Création du fichier passé en argument
    tortue t;
    fprintf(f,"%% !postscript\n"); // Début du fichier postscript
    placer(f, &t, 100, 100, EST);
    tourner_droite(&t); // 4 traits avec des angles de 90°
    avancer(f, &t, 50);
    tourner_droite(&t);
    avancer(f, &t, 50);
    tourner_droite(&t);
    avancer(f, &t, 50);
    tourner_droite(&t);
    avancer(f, &t, 50);
    fprintf(f,"stroke\nshowpage\n"); // Fin du fichier postscript
    fclose(f); // Fermeture du fichier
    return 0;
}