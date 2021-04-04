#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define LG_NOM 30
#define NB_JOUEURS 50

typedef struct{
    char nom[LG_NOM];
    int age;
    float fg, fga, p3, p3a, ft, fta, orb, drb;
} joueur;


typedef struct{
    joueur joueurs[NB_JOUEURS];
    int nbJoueurs;
} table;

int lireFichier(char *nomFichier, table *t){
    FILE *fichier = fopen(nomFichier, "r"); 
    int nbj = 0;
    int finFich = 0;
    joueur *j;
    //fichier++;
    if(fichier != NULL)
    {
    while(finFich != EOF) {
        j = &(t->joueurs[nbj]);
        finFich = fscanf(fichier,"%d;%f;%f;%f;%f;%f;%f;%f;%f;%[^\n]",&(j->age), &(j->fg), &(j->fga), &(j->p3), &(j->p3a), &(j->ft), &(j->fta), &(j->orb), &(j->drb),(j->nom));
        nbj++;
    }
    t->nbJoueurs = --nbj;
    fclose(fichier);
    return 1;
    }
    return 0;
}

void afficherJoueur(joueur *j){

    printf("%-25s age=%d, fg=%5.2f, 3pts=%5.2f, ft=%5.2f, rb=%5.2f\n",(j->nom), (j->age), (j->fg),(j->p3), (j->ft), ((j->orb) + (j->drb)));

}

void afficherTable(table *t){
    int i;
    for(i = 0; i < t->nbJoueurs; i++){
        printf("%2d:",i);
        afficherJoueur(&(t->joueurs[i]));
    }
}

int joueur30ans(joueur j){
   return (j.age > 30); 
}
int j30pr3pts(joueur j){
    float p;
    p = (j.p3 / j.p3a) * 100;
    return (p > 30); 
}

table* Select(table *t, int(*critere)(joueur)){
    table *res = malloc(sizeof(*res));
    int i;
    res->nbJoueurs = 0;
    for(i = 0; i<t->nbJoueurs; i++){
        if((*critere)(t->joueurs[i]))
            res->joueurs[res->nbJoueurs++] = t->joueurs[i];
    }
    return res;
}



int rechercheJoueurParNom(char *nom, table *t){
    int i;
    for(i = 0; i < t->nbJoueurs; i++){
    if(strcoll(nom,t->joueurs[i].nom) == 0)
        return i;
    }
    return -1;
}

int ecrireFichier(char *nomFichier, table *t) {
    int nbj = 0;
    joueur * j;
    FILE *f = fopen(nomFichier, "w");
    while(nbj < t->nbJoueurs) {
      j = &(t->joueurs[nbj]);
      fprintf(f, "%2d;%2.1f;%2.1f;%2.1f;%2.1f;%2.1f;%2.1f;%2.1f;%2.1f;%s\n", (j->age), (j->fg), (j->fga), (j->p3), (j->p3a), (j->ft), (j->fta), (j->orb), (j->drb), (j->nom));
      nbj++;
    }
    fclose(f);
    return 1;
}

int main(){
    char choix;
    int dummy = 0;
    table t;
    table *tt;
    char *nomFich;
    nomFich = malloc(sizeof(char*) * 81);
    do{
    printf("Quel fichier voulez vous lire ? : ");
    scanf("%s", nomFich);
    if((dummy = lireFichier(nomFich, &t)) != 1)
        printf("Ce fichier n'existe pas !\n");
    }while(dummy != 1);
    afficherTable(&t);
    do{
    printf("Voulez vous trier les joueurs de plus de treinte ans ? (o/n) ");
    scanf("\n%c", &choix);
    }while(choix != 'o' && choix != 'n');
        if(choix == 'o'){
        tt = Select(&t, joueur30ans);
        afficherTable(tt);
        do{
        printf("Voulez vous enregistrer cette chaine ? (o/n) ");
        scanf("\n%c", &choix);
        }while(choix != 'o' && choix != 'n');
        if(choix == 'o'){
            printf("Sous quel nom voulez vous l'enregistrer ? : ");
            scanf("%s", nomFich);
            ecrireFichier(nomFich, tt);
        }
        return 0;
    }
    do{
    printf("Voulez vous trier les joueurs qui ont un pourcentage de réussite supérieur à 30 %% aux 3 points ? (o/n) ");
    scanf("\n%c", &choix);
    }while(choix != 'o' && choix != 'n');
    if(choix == 'o'){
        tt = Select(&t, j30pr3pts);
        afficherTable(tt);
        do{
        printf("Voulez vous enregistrer cette chaine ? (o/n) ");
        scanf("\n%c", &choix);
        }while(choix != 'o' && choix != 'n');
        if(choix == 'o'){
            printf("Sous quel nom voulez vous l'enregistrer ? : ");
            scanf("%s", nomFich);
            ecrireFichier(nomFich, tt);
        }
        return 0;
    }
    return 0;
}