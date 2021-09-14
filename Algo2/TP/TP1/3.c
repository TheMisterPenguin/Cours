// L2 info - TP 1 - Base de donnees sur des personnages
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50

// Definition du type categorie
typedef enum {elfe, dragon, nain, titan} t_categ;

// Definition du type position (ligne, colonne)
typedef struct {int x, y; } t_posit;

// Definition du type personnagee (nom, categorie, coordonnnees, points de vie)
typedef struct {char nom[20] ; t_categ categ ; t_posit posit ; int pdv;} t_pers ;

	
void afficher_base(t_pers* pers, int nb_pers){
}

void afficher_nombre(t_pers* pers, int nb_pers){	
}

void afficher_max(t_pers* pers, int nb_pers){
}

void sauvegarder(t_pers* pers, int nb_pers){
}

void charger(t_pers* pers, int* nb_pers){
}

void ajouter(t_pers* pers, int* nb_pers){	
}

void supprimer(t_pers* pers, int* nb_pers){	
}

// Programme principal
int main(void){
	int choix;	// Choix de l'utilisateur

// Declaration de la base de donnees, 
// de taille maximale 50 et de taille utile nb_pers

	t_pers pers[N] = { { "Elwing", elfe, {15, 17}, 20} , { "Drogon", dragon, {20, 4}, 5} , { "Narvi", nain, {2, 6}, 18} , { "Theia", titan, {20, 11}, 8 }, { "Erestor", elfe, {12, 5}, 14}, { "Draka", dragon, {5, 10}, 6}  } ;

	int nb_pers = 6 ;

	do
	{	// Affichage du menu
		printf("\nMenu :\n");
		printf(" 1 - Afficher tous les personnages\n");
		printf(" 2 - Afficher le nombre de personnages par categorie\n");
		printf(" 3 - Afficher le nom du personnage qui a le plus de points de vie\n");
		printf(" 4 - Sauvegarder la base\n");
		printf(" 5 - Charger la base depuis le fichier\n");
		printf(" 6 - Quitter\n");
		printf("Votre choix : ");
		scanf("%i",&choix);

		// Traitement du choix de l'utilisateur
		switch(choix)
		{	case 1 : afficher_base(pers,nb_pers); break;
			case 2:  afficher_nombre(pers,nb_pers); break;
			case 3:  afficher_max(pers,nb_pers); break;
			case 4:  sauvegarder(pers,nb_pers); break;
			case 5:  charger(pers,&nb_pers); break;
			case 6:  break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 6\n");
		}
	}
	while(choix!=6);
	printf("Au revoir !\n");
	return EXIT_SUCCESS;
}