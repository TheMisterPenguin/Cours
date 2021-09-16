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
    //Fonction qui affiche le contenu de la base
    int i;
    const char *categorie[4] = {"Elfe", "Dragon", "Nain", "Titan"};

    for(i = 0; i < nb_pers; i++){
        printf("%-20s | %-6s | %-+4i ; %-+4i | %-2i PV\n", pers->nom, categorie[pers->categ], pers->posit.x, pers->posit.y, pers->pdv);
        pers++;
    }
}

void afficher_nombre(t_pers* pers, int nb_pers){	
    //Fonction qui affiche le nombre de personnages de chaque catégorie
    int i;
    int nb_elfe = 0, nb_dragon = 0, nb_nain = 0, nb_titan = 0;

    for(i = 0; i < nb_pers; i++){
        switch (pers->categ){
            case elfe   : nb_elfe++;
                break;
            case dragon : nb_dragon++;
                break;
            case nain : nb_nain++;
                break;
            case titan : nb_titan++;
        }
        pers++;
    }

    printf("Il y a %i Elfe(s), %i Dragon(s), %i Nain(s) et %i Titan(s)", nb_elfe, nb_dragon, nb_nain, nb_titan);
}

void afficher_max(t_pers pers[], int nb_pers){
    //Fonction qui affiche le nom du personnage avec le plus de points de vie
    int i;
    int indice = 0;

    for(i = 1; i < nb_pers; i++){
        if(pers[i].pdv > pers[indice].pdv)
            indice = i;
    }

    printf("Le joueur qui a le plus de vie est %s avec %i PV", pers[indice].nom, pers[indice].pdv);
}

void sauv_perso(FILE *f, t_pers *pers){
    //Fonction qui sauvegarde un personnage dans le fichier fichier
    fprintf(f,"%s\n%i\n%i %i\n%i\n", pers->nom, pers->categ, pers->posit.x, pers->posit.y, pers->pdv);
}

void sauvegarder(t_pers* pers, int nb_pers){
    //Fonction qui sauvegarde la base dans le fichier base.txt
    int i;
    FILE *f;

    f = fopen("base.txt", "w");

    for(i = 0; i < nb_pers; i++){
        sauv_perso(f,pers);
        printf("Sauvegarde du profil de %s\n", pers->nom);
        pers++;
    }
    fclose(f);
    printf("Sauvegarde effectuée !");
}

int charger_perso(FILE *f, t_pers *pers, int *nb_pers){
    //Fonction qui sauvegarde un personnage dans le fichier fichier
    if(fscanf(f,"%s\n%i\n%i %i\n%i\n", pers->nom, &pers->categ, &pers->posit.x, &pers->posit.y, &pers->pdv) == 0){
        printf("La base est vie !\n");
        return 1;
    }
    (*nb_pers)++;  
    return 0;
}

void charger(t_pers* pers, int* nb_pers){
    //Fonction qui charge la base de donnée
    FILE *f;

    f = fopen("base.txt", "r");
    
    if(charger_perso(f,pers,nb_pers) == 1)
            exit(1);
        pers++;
    while(! feof(f)){
        charger_perso(f,pers,nb_pers);
        pers++;
    }
    printf("Base chargée avec succès !");


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

	//t_pers pers[N] = { { "Elwing", elfe, {15, 17}, 20} , { "Drogon", dragon, {20, 4}, 5} , { "Narvi", nain, {2, 6}, 18} , { "Theia", titan, {20, 11}, 8 }, { "Erestor", elfe, {12, 5}, 14}, { "Draka", dragon, {5, 10}, 6}  } ;

	//int nb_pers = 6 ;
    int nb_pers = 0 ;
    t_pers pers[N];

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