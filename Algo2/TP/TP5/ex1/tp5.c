// L2 info - TP5 listes
#include<stdio.h>
#include<stdlib.h>
#include "liste.h"

#define DEBUG

// Fonctions de manipulation de la liste 

void afficher(void){
// Affiche les valeurs de la liste 

	int elem;

	if(liste_vide())
		printf("La liste est vide\n");
	else{
		printf("\nLa liste contient: ");
		en_tete();
		while(!hors_liste()){
			valeur_elt(&elem);
			printf("%i ",elem);
			suivant();
		}
		printf("\n");
	}
}

void inserer(void){
// Insere une valeur dans la liste 
	int i, v;

    printf("Saisir un entier : ");
    scanf("%i", &i);

    if(liste_vide()){
        ajout_droit(i);
    }
    else{
        en_queue();
        valeur_elt(&v);
        if(i >= v)
            ajout_droit(i);
        else{
            en_tete();
            do{
                valeur_elt(&v);
                suivant(); 
            }while(v < i);
            precedent();
            ajout_gauche(i);
       }
    }  
}

void afficher_multiples(void){
// Affiche tous les multiples d'une valeur lue au clavier
	int val_liste;
	int val_clavier;

	printf("Saisir une valeur au clavier : ");
	scanf("%d", &val_clavier);

	if(!liste_vide()){
		en_tete();
		while(!hors_liste()){
			valeur_elt(&val_liste);
			if(val_liste % val_clavier == 0)
				printf("%d est un multiple de %d\n", val_liste, val_clavier);
			suivant();
		}
    }
 	
}

void compter(void){
// Compte les occurrences d'une valeur lue au clavier 
	int nb_occu = 0;
	int val_liste;
	int val_clavier;

	printf("Saisir une valeur au clavier : ");
	scanf("%d", &val_clavier);

	if(!liste_vide()){
		en_tete();
		while(!hors_liste()){
			valeur_elt(&val_liste);
			if(val_liste == val_clavier)
				nb_occu++;
			suivant();
		}
    }

	printf("Il y a %d occurence(s) de %d\n", nb_occu, val_clavier);
}

void supprimer(void){
// Supprime toutes les occurrences d'une valeur lue au clavier
    int v,x;

	printf("Saisir une valeur au clavier : ");
	scanf("%d", &x);
    if(!liste_vide()){
        en_queue();
        do{
            valeur_elt(&v);
            if(v == x)
                oter_elt();
            precedent();
        }while(!hors_liste());
    }

}

void vider_liste(void){
// Supprime toutes les valeurs de la liste
	
    en_queue();
	while(!hors_liste())
		oter_elt();
}

//	Programme principal 
int main(void){
	int choix;

// Initialisation de la liste d'entiers
	init_liste();

	do{
// Affichage du menu et saisie du choix
		printf("\nMenu :\n");
		printf(" 1 - Inserer une valeur\n");
		printf(" 2 - Afficher les multiples\n");
		printf(" 3 - Compter les occurrences d'une valeur\n");
		printf(" 4 - Supprimer une valeur\n");
		printf(" 5 - Vider la liste\n");
		printf(" 6 - Quitter\n");
		printf("Votre choix : ");
		scanf("%d",&choix);

// Traitement du choix de l'utilisateur 
		switch(choix){
			case 1: inserer();  afficher(); break;
			case 2: afficher_multiples(); afficher(); break;
			case 3: compter(); afficher(); break;
			case 4: supprimer(); afficher(); break;
			case 5: vider_liste(); afficher(); break;
			case 6: break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 6\n");
		}
	}
	while(choix!=6);

	printf("Au revoir !\n");
	return EXIT_SUCCESS;
}
