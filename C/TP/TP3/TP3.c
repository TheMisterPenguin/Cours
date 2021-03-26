/*
 * auteur : LeNomDeLEtudiant
 * version 0.1 : Date : Thu Mar 25 09:04:39 CET 2021
 *
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define MAX_LIGNES 200
#define MAX_ENTREES 2000

typedef struct{
    char *mot;
    int lignes[MAX_LIGNES];
    int nbLignes;
}Entree;

typedef struct{
    Entree entrees[MAX_ENTREES];
    int nbEntrees;
}Table;

char minuscules(char c){
	if(c >= 'A' && c <= 'Z')
		c = c + ('a' - 'A');
	return c;
}

void initTable(Table *t){
    t->nbEntrees = 0;
}

void initEntree(Entree *e, char *mot, int numLigne){
	//printf("J'initialise l'entrée \n");
	int i;
  int taille = strlen(mot);
  e->mot = malloc((taille + 1) * sizeof(char));
	for(i = 0; mot[i] != '\0'; i++){
		e->mot[i] = mot[i];
	}
	e->mot[i+1] = '\0';
	e->lignes[0] = numLigne;
	e->nbLignes = 1;
}

void ajouterLigne(Entree *e, int numLigne){
	e->lignes[e->nbLignes] = numLigne;
	e->nbLignes += 1;
}

int rechercherEntree(Table *t, char *mot){
	//printf("Je recherche une entrée \n");
  int i, y, indice;
  i = 0;
  indice = -1;
  while(i < (t->nbEntrees) || indice != -1){
  	//printf("while\n");
    for(y = 0; mot[y] != '\0'; y++){
		//printf("%c %c \n",mot[y],t->entrees[i].mot[y]);
      if(mot[y] != t->entrees[i].mot[y]){
        indice = -1;
        break;
      }
    	indice = i;
		//printf("Lettre égale\n");
    }
	if(indice != -1)
		return indice;
    i++;
  }
  //printf("%d\n", indice);
  return -1;
}

void traiterMot(Table *t, char *mot, int numLigne){
  int indice;
  //printf("Je traite le mot\n");
  if((indice = rechercherEntree(t, mot)) == -1){
    initEntree(&(t->entrees[t->nbEntrees++]), mot, numLigne);
    //t->nbEntrees += 1;
  }
  else {
	  ajouterLigne(&t->entrees[indice], numLigne);
    //t->entrees[indice].lignes[t->entrees[indice].nbLignes] = numLigne;
    //t->entrees[indice].nbLignes++;
  }
}

void afficherTable(Table *t){
	//char *tbl;
	//tbl = malloc(sizeof(char) * 50);
	//printf("J'affiche \n");
  for(int i = 0; i < t->nbEntrees; i++){
  	//tbl = realloc(tbl, sizeof(char) * (strlen(t->entrees[i].lignes[y]) + 1));
    printf("%d : %s -> ", i, t->entrees[i].mot);
    for(int y = 0; y < (t->entrees[i].nbLignes); y++){
      printf("%d, ", t->entrees[i].lignes[y]);
    }
    printf("\n");
  }
}

int main()
{
	int i;
    Table maTable;
	FILE* fichier = NULL;
	fichier = fopen("arlh.txt", "r");
    char c; // variable temporaire pour stocker le mot courant
    char mot[80];
	char mot1[80] = {"Ceux"}; // variable temporaire pour stocker le mot courant
    char mot2[80] = {"qui"};
	char mot3[80] = {"Ceux"};
    int imot=0; //
    int numLigne=1;
    initTable(&maTable);
	if(fichier != NULL){
    // Tant qu'il y a des caractères dans l'entrée standard
        do {
		    c=fgetc(fichier);
            // Si le caractère est une lettre, l'ajouter au mot
            if(isalpha(c)){
			    c = minuscules(c);
                mot[imot++]=c;
		    }
            else {    // Si le caractère n'est pas une lettre, fin du mot
                mot[imot]='\0';
                if(imot>0)  // Si le mot contient au moins une lettre
                    traiterMot(&maTable,mot,numLigne);
                imot=0;
            }
            if(c=='\n')
                numLigne++;
        }while(c != EOF);
	}
    afficherTable(&maTable);
    fclose(fichier);
    return 0;
}