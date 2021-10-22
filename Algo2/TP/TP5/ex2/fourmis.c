#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<conio.h>
#include<time.h>
#include"listesF.h"
#include"couleurs.h"

#ifdef _WIN32
	#include <windows.h>
	#define couleur SetConsoleTextAttribute
#else
	#include<unistd.h>
#endif

#define DEBUG

HANDLE console;

// *************************************
// ***** Definition des constantes *****
// *************************************

#define DIMX 40		// Dimensions du plateau
#define DIMY 60

#define VIDE 0		// Codage des elements fixes du plateau
#define MARE -1
#define FEUILLE -2

#define PAUSE 1000		// Duree de pause entre deux tours
#define SEUIL_PONTE 50		// Seuil min d'energie de la reine
#define NB_MARES 20		// Nombre de mares sur le plateau
#define NB_FEUILLES 20		// Nombre initial de feuilles
#define PROBA_FEUILLE 10	// Proba de chute de feuille 
#define PROBA_PONTE 10		// Proba que la reine ponde
#define MAX_TOUR 20		// Plafonne la duree de la partie

// La quantite initiale d'energie d'une fourmi 
// est calculee en fonction de la taille du plateau
#define ENERGIE (DIMX+DIMY)


// ************************************
// ***** Prototypes des fonctions *****
// ************************************

int possible(int x, int y,int P[DIMX][DIMY]);
int libre(int x, int y,int P[DIMX][DIMY]);
void afficher(int P[DIMX][DIMY], t_liste* R, t_liste* N, t_etat etatR, t_etat etatN);
void nouvelles_feuilles(int P[DIMX][DIMY]);
void afficherPlateau(int P[DIMX][DIMY], t_liste* R, t_liste* N);
void afficherStats(t_liste* R, t_liste* N, t_etat etatR, t_etat etatN);
void initialiser(int P[DIMX][DIMY], t_liste* rouges, t_liste* noires);
int evolution(t_fourmi* f, int P[DIMX][DIMY], t_etat* etat);
void miseAjour(int P[DIMX][DIMY], t_couleur coul, t_liste* colonie, t_etat* etat);
void dessiner_ligne();
int taille_liste(t_liste *l);

int feuilleProche(int P[DIMX][DIMY], int x, int y, int xp, int* nx, int* ny);


// *******************************
// ***** Programme principal *****
// *******************************

int main(void){
	SetConsoleOutputCP(65001);
	int plateau[DIMX][DIMY]={{VIDE}};		// Plateau de jeu
	t_liste rouges;					// Fourmis rouges
	t_liste noires;					// Fourmis noires
	t_etat etatR={100, true, 0, 0};			// Etat colonie R
	t_etat etatN={100, true, 0, 0};			// Etat colonie N
	int tour=0;					// Nombre de tours de jeu
	
	console = GetStdHandle ( STD_OUTPUT_HANDLE );

	system("cls");
	initialiser(plateau,&rouges,&noires);

	afficher(plateau,&rouges,&noires,etatR,etatN);
	// Evolution jusqu'a disparition d'une colonie
	while(!liste_vide(&noires) && !liste_vide(&rouges)){

		miseAjour(plateau,rouge,&rouges,&etatR);
		miseAjour(plateau,noire,&noires,&etatN);
		nouvelles_feuilles(plateau);

		afficher(plateau,&rouges,&noires,etatR,etatN);

		tour++;

		// Pour interrompre la partie apr�s MAX-TOUR tours
		if(tour>=MAX_TOUR) break;
	}
	

	// Une colonie gagne si sa reine est toujours vivante
	// alors que l'autre colonie a entierement trepasse

	/*if(liste_vide(&rouges) && etatN.presenceReine)
		printf("\nLes noires gagnent en %i tours\n",tour);
	else if(liste_vide(&noires) && etatR.presenceReine)
		printf("\nLes rouges gagnent en %i tours\n",tour);
	else if(tour==MAX_TOUR){
		printf("Partie stoppee au bout de %i tours\n",tour);
		printf("(modifier la variable MAX_TOUR pour changer ce seuil)\n");
	}else // les deux reines sont mortes
		printf("C'est l'apocalypse: pas de gagnant\n");*/
	

	return EXIT_SUCCESS;
}


// ************************************
// ***** Fonctions intermediaires *****
// ************************************


int possible(int x, int y,int P[DIMX][DIMY]){
// Vrai si une case est atteignable: sur plateau, hors mare
	return(x>=0 && x< DIMX && y>=0 && y<DIMY &&
			P[x][y]!=MARE);
}

int libre(int x, int y,int P[DIMX][DIMY]){
// Vrai si une case est libre: sur plateau, ni mare ni feuille
	return(x>=0 && x< DIMX && y>=0 && y<DIMY &&
			P[x][y]!=MARE && P[x][y]!=FEUILLE);
}

void nouvelles_feuilles(int P[DIMX][DIMY]){
// Chute aleatoire d'une feuille 
// tous les PROBA_FEUILLE tours (en moyenne)
	int xfeuille,yfeuille;
	int placer_feuille;

	placer_feuille = rand() % PROBA_FEUILLE;

	if(placer_feuille == 0){
		do{
			xfeuille = rand() % DIMX;
			yfeuille = rand() % DIMY;
		}while(!libre(xfeuille, yfeuille, P));
		P[xfeuille][yfeuille] = FEUILLE;
		#ifdef DEBUG
		printf("Nouvelle feuille %i %i", xfeuille, yfeuille);
		#endif
	}

}

void afficherPlateau(int P[DIMX][DIMY], t_liste* R, t_liste* N){
// Affiche l'etat du plateau de jeu avec les fourmis
// Attention: une case de matrice = deux caracteres a l'ecran


// Codage des differentes classes de fourmis
// selon leur couleur, statut, transport de feuille
typedef enum {vide, reine_rouge, reine_noire, ouvriere_rouge, ouvriere_noire, rouge_feuille, noire_feuille} t_classe_fourmi;

	int i,j;
	t_fourmi fourmi;


	
	// Pause et effacement de l'ecran
	Sleep(PAUSE);
	system("cls");


	// Placement des fourmis rouges
	en_tete(R);
	while(!hors_liste(R)){
		valeur_elt(R,&fourmi);
		if(fourmi.statut == reine)
			P[fourmi.x][fourmi.y] = reine_rouge;
		else
			P[fourmi.x][fourmi.y] = ouvriere_rouge;
		if(fourmi.feuille == true)
			P[fourmi.x][fourmi.y] = rouge_feuille;
		suivant(R);
	}


	// Placement des fourmis noires
	en_tete(N);
	while(!hors_liste(N)){
		valeur_elt(N,&fourmi);
		if(fourmi.statut == reine)
			P[fourmi.x][fourmi.y] = reine_noire;
		else
			P[fourmi.x][fourmi.y] = ouvriere_noire;
		if(fourmi.feuille == true)
			P[fourmi.x][fourmi.y] = noire_feuille;
		suivant(N);
	}

	// Affichage du plateau avec les fourmis
	dessiner_ligne();
	
	for(i = 0; i < DIMX; i++){
		couleur(console, MARRON);
		printf("███");
		for(j = 0; j < DIMY; j++)
			switch(P[i][j]) {
				case MARE :     		couleur(console, CYAN); printf("███");break;
				case FEUILLE : 			couleur(console, VERT); printf("███");break;
				case reine_rouge : 		couleur(console, ROUGE | FOND_BLANC ); printf(" U ");break;
				case reine_noire : 		couleur(console, NOIR | FOND_BLANC ); printf(" U ");break;
				case ouvriere_noire : 	couleur(console, NOIR | FOND_BLANC ); printf(" > ");break;
				case ouvriere_rouge : 	couleur(console, ROUGE | FOND_BLANC ); printf(" > ");break;
				case rouge_feuille : 	couleur(console, VERT | FOND_BLANC ); printf("*");
									 	couleur(console, ROUGE | FOND_BLANC ); printf("> ");break;
				case noire_feuille : 	couleur(console, NOIR | FOND_BLANC ); printf("*");
									 	couleur(console, ROUGE | FOND_BLANC ); printf("> ");break;
				default : 				couleur(console, NOIR | FOND_BLANC);printf("   ");
			}
		couleur(console, MARRON);
		printf("███");
		printf("\n");
	}
	dessiner_ligne();

}

void afficherStats(t_liste* R, t_liste* N, t_etat etatR, t_etat etatN){
// Affiche les statistiques des colonies en bas du plateau
	t_fourmi f;

	//Colonie rouge

	couleur(console, BLANC);
	printf("Colonie rouge :\n");

	printf("Nombre de fourmis : %i\n", taille_liste(R));
	if(etatR.presenceReine == false)
		printf("Il n'y a pas de reine !\n");
	else{
		en_tete(R);
		valeur_elt(R, &f);
		printf("La reine rouge possède une énergie de %i\n", f.energie);
	}
	printf("Le stock de nourriture de la colonie est de %i\n", etatR.stock);
	printf("Il y a eu %i naissances dans la colonie depuis le début de la partie\n", etatR.naissance);
	printf("Il y a eu %i décès depuis le début de la partie\n", etatR.deces);

	printf("------------\n");

	//Colonie noire

	printf("Colonie noire :\n");

	printf("Nombre de fourmis : %i\n", taille_liste(N));
	if(etatN.presenceReine == false)
		printf("Il n'y a pas de reine !\n");
	else{
		en_tete(N);
		valeur_elt(N, &f);
		printf("La reine rouge possède une énergie de %i\n", f.energie);
	}
	printf("Le stock de nourriture de la colonie est de %i\n", etatN.stock);
	printf("Il y a eu %i naissances dans la colonie depuis le début de la partie\n", etatN.naissance);
	printf("Il y a eu %i décès depuis le début de la partie\n", etatN.deces);

}

void afficher(int P[DIMX][DIMY], t_liste* R, t_liste* N, t_etat etatR, t_etat etatN){
// Affiche le plateau et les statistiques du jeu

	int M[DIMX][DIMY];
	int i,j;

	// Recopie les elements fixes du plateau 
	// dans une matrice intermediaire
	for(i=0;i<DIMX;i++)
		for(j=0;j<DIMY;j++)
			M[i][j]=P[i][j];

	// Ajoute les fourmis sur la matrice intermediaire
	// et affiche cette matrice puis les statistiques
	afficherPlateau(M,R,N);
	afficherStats(R,N,etatR,etatN);
}

void initialiser(int P[DIMX][DIMY], t_liste* rouges, t_liste* noires){
// Initialise chaque colonie avec une reine
// Initialise le plateau avec des mares et des feuilles
// placees de maniere aleatoire

	int i,j, xMare,yMare, xfeuille,yfeuille;
	
	t_fourmi reineRouge = 
		{rouge,reine,DIMX-1, DIMY-1, ENERGIE, false, false, nord};

	t_fourmi reineNoire = 
		{noire,reine,0, 0, ENERGIE, false, false, nord};

	srand(time(0));

	// Initialisation des listes
	init_liste(rouges);
	init_liste(noires);

	// Ajout d'une reine dans chaque liste
	
	ajout_droit(rouges,reineRouge);
	ajout_droit(noires, reineNoire);

	// Creation aleatoire de NB_MARES mares
	for(i = 0; i < NB_MARES; i++){
		xMare = rand() % DIMX;
		yMare = rand() % DIMY;
		if(possible(xMare, yMare, P))
			P[xMare][yMare] = MARE;
	} 


	// Chute aleatoire de NB_FEUILLES feuilles 
	// sur des cases libres
	for(i = 0; i < NB_FEUILLES; i++){
		xfeuille = rand() % DIMX;
		yfeuille = rand() % DIMY;
		if(possible(xfeuille, yfeuille, P))
			P[xfeuille][yfeuille] = FEUILLE;
	} 

}

int feuilleProche(int P[DIMX][DIMY], int x, int y, int xp, int* nx, int* ny){
// Vrai si la fourmi est proche d'une feuille
// La fourmi d�tecte les feuilles a une case de distance, dans 8 directions


	return false; // resultat par defaut

}

int evolution(t_fourmi* f, int P[DIMX][DIMY], t_etat* etat){
// Calcule l'evolution de la fourmi f puis modifie 
// les champs de la structure f selon cette evolution
// Met a jour l'etat du jeu si necessaire
// Renvoie evol qui vaut:
//     -1 si la fourmi meurt
//     +1 si la fourmi est une reine et qu'elle pond
//     0 sinon

	int evol=0;


	if(f->statut==ouvriere){ // la fourmi est une ouvriere


	
	}
	else { // la fourmi est une reine



	}
	return evol;
}

void miseAjour(int P[DIMX][DIMY], t_couleur coul, t_liste* colonie, t_etat* etat){
// Met a jour les fourmis de la colonie de couleur coul

	t_fourmi fourmi;		// Element courant de la liste

	int evol;			// Valeur d'evolution de la fourmi

	t_fourmi ouvriereRouge = 
		{rouge,ouvriere, DIMX-2, DIMY-2, ENERGIE, false, false, ouest};

	t_fourmi ouvriereNoire = 
		{noire,ouvriere, 1, 1, ENERGIE, false, false, est};



}
		
void dessiner_ligne(){
	int i,j;

	couleur(console, MARRON | 0xF0);
	printf("███");
	for(i = 0; i < DIMY; i++)
			printf("███");
	printf("███");
	printf("\n");	
}

int taille_liste(t_liste *l){
	//Fonction qui renvoie la taille de la liste passée en parmaètre
	int nb_elements = 0;

	
	if(!liste_vide(l)){
		en_tete(l);
		while(!hors_liste(l)){
			nb_elements++;
			suivant(l);
		}
	}

	return nb_elements;
}