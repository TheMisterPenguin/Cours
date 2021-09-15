#include <stdio.h>

typedef enum{magicienne, geant, zombie, vampire} t_categorie;
const char *cat[4] = {"Magicienne", "Géant", "Zombie", "Vampire"};

typedef union{
    char grade;
    float taille;
    int vitesse;
    char gs[3];
} t_valeur;

typedef struct{
    char id[20];
    t_categorie cate;
    int x, y;
    int pv;
    t_valeur val;
} t_personnage;

void cara_affich(t_personnage p){
    //Fonction qui affiche les caractéristiques d'un personnage

    printf("%s appartenant à la catégorie %s ", p.id, cat[p.cate]);
    switch (p.cate)
    {
    case magicienne     : printf("ayant le grade \"%c\"", p.val.grade);
        break;
    case geant          : printf("mesurant %f m", p.val.taille);
        break;
    case zombie         : printf("se déplaçant à %i km/h", p.val.vitesse);
        break;
    case vampire        : printf("ayant pour groupe sanguin préféré %s", p.val.gs);
        break;
    }
    printf(" possède %i point(s) de vie et se trouve aux coordonées %i %i \n", p.pv, p.x, p.y);
}

int main(){
    float taille = 15.35;
    t_personnage p1 = {"Claudine", magicienne, 55, 65, 10, 'A'};
    t_personnage p2 = {"Gérard", zombie, 65, 55, 15, 1};
    t_personnage p3 = {"Edouard", vampire, 0, 0, 1, "AB"};
    t_personnage p4 = {"Stéphane", geant, -500, 500, 150, taille};
    //t_personnage p4 = {"Stéphane", geant, -500, 500, 150, ((float)15.35)};

    cara_affich(p1);
    cara_affich(p2);
    cara_affich(p3);
    cara_affich(p4);
}