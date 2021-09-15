
 typedef enum{as = 1, deux = 2, trois = 3, quatre = 4, cinq = 5, six = 6, sept = 7, huit = 8, neuf = 9, dix = 10, valet = 11, cavalier = 12, dame = 13, roi = 14} hauteur;
 typedef enum{carreau, coeur, trefle, pique} couleur;

 typedef struct{
     couleur c;
     hauteur h;
 } t_carte;

 typedef union {
    t_carte carte;
    int atout;
 } t_tarot;
 
int main(){
    t_tarot petit;
    t_tarot cavalierPique;

    petit.atout = 1;
    cavalierPique.carte.c = pique;
    cavalierPique.carte.h = cavalier;

    return 0;
}
 