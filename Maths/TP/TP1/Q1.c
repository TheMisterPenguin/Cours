#include <stdio.h>
#include <stdlib.h>

#define lg 5
#define nbLettres 3

void afficherMots(int mot[lg]){
  for(int i = 0; i < lg; i++)
    printf("%c", mot[i] + 'A');
  putchar('\n');
}

int motSuivant(int mot[lg]){
  for(int i = 0; i < lg; i++){
    if(mot[i] + 1 < nbLettres){ 
      mot[i]++;
      return 1;
    }
      mot[i] = 0; 
  }
  return 0;
}

int main(){
  int i = 1;
  int tab[lg] = {0,0,0,0,0};
  printf("Compteur : %d\n", i);
  afficherMots(tab);
  for(i = 2; motSuivant(tab) == 1; i++){
    printf("Compteur : %d\n", i);
    afficherMots(tab);
  }
  printf("Compteur final : %d\n", i - 1);
  return 0;
}