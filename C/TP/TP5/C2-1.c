#include <stdio.h>

enum {NORD, EST, SUD, OUEST};

typedef struct {
    int x;
    int y;
    int dir;
} tortue;

void placer(FILE *f, tortue* tor, int x, int y, int dir){
    fprintf(f, "%d %d moveto\n", x, y);
    tor->x = x;
    tor->y = y;
    tor->dir = dir;
}

void tourner_droite(tortue* tor){
    if(tor->dir == OUEST)
        tor->dir = NORD;
    else    
        (tor->dir)++;
}

void tourner_gauche(tortue* tor){
    if(tor->dir == NORD)
        tor->dir = OUEST;
    else    
        (tor->dir)--;
}

void avancer (FILE *f, tortue *tor, int deplact){
    switch(tor->dir) {
        case NORD   : tor->y += deplact;
        case EST    : tor->x += deplact;
        case SUD    : tor->y -= deplact;
        case OUEST  : tor->x -= deplact;       
    }
    fprintf(f, "%d %d lineto", tor->x, tor->y);
}