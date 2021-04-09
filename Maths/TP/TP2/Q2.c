#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int h, c;
} sCarte;

void afficherCarte(sCarte c){
    switch (c.h) {
        case 9 :    printf("(valet, ");
                    break;
        case 10 :   printf("(dame, ");
                    break;
        case 11 :   printf("(roi, ");
                    break;
        case 12 :   printf("(as, ");
                    break;
        default :   printf("(%d, ", (c.h) + 2);
                    break;
    }
    switch (c.c) {
        case 0 :    printf("coeur)\n");
                    break;
        case 1 :    printf("carreau)\n");
                    break;
        case 2 :    printf("pique)\n");
                    break;
        case 3 :    printf("trèfle)\n");
                    break;
    }
}

void afficherMain(int hand[5], sCarte jeu[]){
    int i;
    for(i = 0; i < 5; i++){
        afficherCarte(jeu[hand[i]]);
    }
}

int mainSuivant(int hand[]){
    int i, retour;
    retour = 0;
  for(i = 0; i < 5; i++){
        //printf("%d \n", i);
        //printf("%d\n", hand[i]);
    if(hand[i] + 1 <= (51 - i)){ 
      hand[i]++;
      retour = 1;
      break;
    }
  }
  for(i--; i >= 0 ; i--){
      hand[i] = hand[i + 1] + 1;
  }
  return retour;
}

int main(){
    int i, y, compteur, nbMain, x;
    int hand[5] = {4, 3, 2, 1, 0};
    sCarte jeu[52];
    nbMain = 0;
    for(i = 0, compteur = 0; i < 4; i++){
        for(y = 0; y < 13 ; y++){
            jeu[compteur].c = i;
            jeu[compteur].h = y;
            compteur++;
        }
    }
    for(x = 0; mainSuivant(hand); x++);
    printf("%d \n", x + 1);
    return 0;
}