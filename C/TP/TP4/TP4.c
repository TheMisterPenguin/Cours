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


int main(){
    table t;
    table *tt;
    lireFichier("nba2015.csv", &t);
    //printf("%d\n", lireFichier("nba2015.csv", &t));
    //afficherJoueur(&(t.joueurs[0]));
    afficherTable(&t);
    printf("%d\n",rechercheJoueurParNom("Paul Millsap", &t));
    tt = Select(&t, j30pr3pts);
    afficherTable(tt);
    return 0;
}