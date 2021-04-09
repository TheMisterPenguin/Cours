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
        case NORD   : tor->y += deplact; break;
        case EST    : tor->x += deplact; break;
        case SUD    : tor->y -= deplact; break;
        case OUEST  : tor->x -= deplact; break;      
    }
    fprintf(f, "%d %d lineto\n", tor->x, tor->y);
}

int main(int argc, char* argv[]){
    FILE *f = fopen(argv[1], "w");
    tortue t;
    fprintf(f,"%% !postscript\n");
    placer(f, &t, 100, 100, EST);
    tourner_droite(&t);
    avancer(f, &t, 50);
    tourner_droite(&t);
    avancer(f, &t, 50);
    tourner_droite(&t);
    avancer(f, &t, 50);
    tourner_droite(&t);
    avancer(f, &t, 50);
    fprintf(f,"stroke\nshowpage\n");
    fclose(f);
}