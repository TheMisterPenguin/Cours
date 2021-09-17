// L2 info - TP 1 - Base de donnees sur des personnages
//Despert Ange
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define N 50

// Definition du type categorie
typedef enum {elfe, dragon, nain, titan} t_categ;

const char *categorie[4] = {"Elfe", "Dragon", "Nain", "Titan"};

// Definition du type position (ligne, colonne)
typedef struct {int x, y; } t_posit;

// Definition du type personnagee (nom, categorie, coordonnnees, points de vie)
typedef struct {char nom[20] ; t_categ categ ; t_posit posit ; int pdv;} t_pers ;

	
void afficher_base(t_pers* pers, int nb_pers){
    //Fonction qui affiche le contenu de la base
    int i;
    
	if(nb_pers > 0){
    	for(i = 0; i < nb_pers; i++){
        	printf("%-20s | %-6s | %-+4i ; %-+4i | %-2i PV\n", pers->nom, categorie[pers->categ], pers->posit.x, pers->posit.y, pers->pdv);
        	pers++;
    	}
    }
    else
    	printf("La base de donnée est vide !\n");
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
    if(nb_pers == 0)
    	printf(" car la base de donnée est vide !");
}

void afficher_max(t_pers pers[], int nb_pers){
    //Fonction qui affiche le nom du personnage avec le plus de points de vie
    int i;
    int indice = 0;

	if(nb_pers > 0){
    		for(i = 1; i < nb_pers; i++){
        		if(pers[i].pdv > pers[indice].pdv)
        	   	 indice = i;
   		 }

    		printf("Le joueur qui a le plus de vie est %s avec %i PV", pers[indice].nom, pers[indice].pdv);
    	}
    	else
    		printf("La base de donnée est vide ! Traitement impossible !");
}

void sauv_perso(FILE *f, t_pers *pers){
    //Fonction qui sauvegarde un personnage dans le fichier fichier
    fprintf(f,"%s\n%i\n%i %i\n%i\n", pers->nom, pers->categ, pers->posit.x, pers->posit.y, pers->pdv);
}

void sauvegarder(t_pers* pers, int nb_pers){
    //Fonction qui sauvegarde la base dans le fichier base.txt
    int i;
    FILE *f;

	if(nb_pers > 0){
    	f = fopen("base.txt", "w");

    	for(i = 0; i < nb_pers; i++){
     	   sauv_perso(f,pers);
      	  printf("Sauvegarde du profil de %s\n", pers->nom);
      	  pers++;
   	 	}
    	fclose(f);
    	printf("Sauvegarde effectuée !");
	}
	else	
		printf("Base vide, sauvegarde du fichier annulé");
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

void ajouter_nom(char nom[20]){
	//Fonction qui récupère le nom du personnage à ajouter saisi
	
	printf("Saisir le nom du personnage à ajouter (20 caractères max) : \n");
    	scanf("%s", nom);
}

t_categ ajouter_categorie(void){
	//Fonction qui récupère la catégorie du personnage à ajouter saisi
	t_categ saisie;
	
	do{
	
	//Affichage
    		printf("Catégories disponibles : %s %i\n                         ", categorie[elfe], elfe);
    		printf("Catégories disponibles : %s %i\n                         ", categorie[dragon], dragon);
    		printf("Catégories disponibles : %s %i\n                         ", categorie[nain], nain);
    		printf("Catégories disponibles : %s %i\n", categorie[titan], titan);
    		
    	//Saisie
    		printf("\nSaisir la catégorie du personnage (entre %i et %i) : ", elfe, titan);
    		scanf("%i", &saisie);
    	
    	//Vérification
    		if(saisie >= elfe && saisie <= titan)
    		break;
  		printf("Valeur saisie incorrecte !\n");
  	
    }while(saisie < elfe || saisie > titan);
    
    printf("Catégorie %s sélectionée\n", categorie[saisie]);
    
    return saisie;

}

t_posit ajouter_position(void){
	//Fonction qui récupère la postion du personnage à ajouter saisi
	t_posit coord;
	
	printf("Indiquer la position du personnage (x;y) : ");
    	scanf("%i;%i", &coord.x, &coord.y);
    	
    	return coord;
}

int ajouter_pv(void){
	//Fonction qui récupère le nombre de points de vie du personnage à ajouter
	int pv;
	
	printf("Saisir le nombre de points de vie du personnage : ");
    	scanf("%i", &pv);
	
	return pv;
}

void ajouter(t_pers* pers, int* nb_pers){
    //Fonction qui ajoute un personnage à la base de donnée
    //Données
    t_categ categ;
    int pv;
    char nom[20];
    t_posit coord;
    
    char choix;
    
    //Nom
    ajouter_nom(nom);
    
    //Catégorie 
    categ = ajouter_categorie();
    
    //Position
    coord = ajouter_position();
    
    //PV
    pv = ajouter_pv();
    
    
    printf("\nAppuyer sur une touche pour continuer ...");
    scanf("%*c%*c");
    system("clear");
    
    printf("Résumé du personnage : \n");
    printf("Nom : %s\nCatégorie : %s\nCoordonnées : %i/%i\nPoints de vie : %i\n", nom, categorie[categ], coord.x, coord.y, pv);
    do{
    	printf("\nCe choix vous convient t'il ? (o/n) : ");
    	scanf("%c%*c", &choix);
    }while(choix != 'o' && choix != 'n');
    
    printf("Choix enregistré\n");
    
    //Enregistrement dans la base
    if(choix == 'o'){
    	strcpy(pers[*nb_pers].nom, nom);
    	pers[*nb_pers].categ = categ;
    	pers[*nb_pers].posit = coord;
    	pers[*nb_pers].pdv = pv;
    	(*nb_pers)++;
    	
    	printf("Le joueur %s à été ajouté à la base de donnée !\n");
    }
    printf("\nAppuyer sur une touche pour continuer ...\n");
    scanf("%*c");
    system("clear");
    printf("Retour au menu principal ...\n");
    fflush(stdin);
    
    sleep(1);
    system("clear");
}

int confirmer_suppr(void){
	//Fonction qui renvoie 1 si le choix est positif et 0 si le choix est négatif
	char choix;
	
	fflush(stdin);
	printf("Êtes vous sur de vouloir supprimer ce personnage ? (o/n) : ");
	do{
		scanf("%c", &choix);
	}while(choix != 'o' && choix != 'n');
	
	return (choix == 'o');

}

int chercher_nom(char nom[20], t_pers* pers, int* nb_pers){
	//Fonction qui renvoie l'indice dans le tableau de la personne recherchée
	int i;
	
	for(i = 0; i < *nb_pers; i++){
		if(strcmp(nom, pers[i].nom) == 0)
			return i;
	}
	return -1;
}

void decaler(int indice, t_pers* pers, int* nb_pers){
	//Fonction qui décale le contenu du tableau vers la gauche à partir d'un indice donné
	int i;
	
	for(i = indice; i < (*nb_pers - 1); i++){
		pers[i] = pers[i+1];
	}
}

void supprimer(t_pers* pers, int* nb_pers){	
	//Fonction qui supprime un personnage de la base
	char nom[20];
	int indice;
	
	//Nom du personnage
	printf("Saisir le nom du personnage : ");
	scanf("%s", nom);
	
	indice = chercher_nom(nom, pers, nb_pers);
	if(indice == -1){
		printf("%s ne fait pas parti de la base de donnée\n", nom);
		if(*nb_pers == 0)
			printf("PS : aucun personnage n'est inscrit dans la base de donnée.\n");
	}
	else {
		if((indice + 1 )== *nb_pers){
			if(confirmer_suppr() == 1){
				(*nb_pers)--;
				printf("Le personnage %s à été retiré de la base de donnée.\n", nom);
			}
			else
				printf("Choix abbordé\n");
		}
		else{
			if(confirmer_suppr() == 1){
			decaler(indice, pers, nb_pers);
			(*nb_pers)--;
			printf("Le personnage %s à été retiré de la base de donnée.\n", nom);
			}
			else
				printf("Choix abbordé\n");
		}
			
	
	}
			

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
	
	system("clear");
	do
	{	// Affichage du menu
		printf("\nMenu :\n");
		printf(" 1 - Afficher tous les personnages\n");
		printf(" 2 - Afficher le nombre de personnages par categorie\n");
		printf(" 3 - Afficher le nom du personnage qui a le plus de points de vie\n");
		printf(" 4 - Sauvegarder la base\n");
		printf(" 5 - Charger la base depuis le fichier\n");
		printf(" 6 - Ajouter un personnage à la base de donnée\n");
		printf(" 7 - Supprimer un personnage de la base de donnée\n");
		printf(" 8 - Quitter\n");
		printf("Votre choix : ");
		scanf("%i",&choix);

		// Traitement du choix de l'utilisateur
		switch(choix)
		{	case 1 : afficher_base(pers,nb_pers); break;
			case 2:  afficher_nombre(pers,nb_pers); break;
			case 3:  afficher_max(pers,nb_pers); break;
			case 4:  sauvegarder(pers,nb_pers); break;
			case 5:  charger(pers,&nb_pers); break;
			case 6:  ajouter(pers,&nb_pers);break;
			case 7:  supprimer(pers,&nb_pers);break;
			case 8:  break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 6\n");
		}
	}
	while(choix!=8);
	printf("Au revoir !\n");
	return EXIT_SUCCESS;
}
