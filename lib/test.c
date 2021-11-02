#include "pile.h"
#include "file.h"
#include <stdio.h>

int main(){
    pile p;
    int i;

    /*init_pile(&p);
    if(pile_vide(&p))
        printf("Pilevide\n");
    else    
        printf("pile non vide\n");
    empiler(&p, 3);
    if(pile_vide(&p))
        printf("Pilevide\n");
    else    
        printf("pile non vide\n");
    
    depiler(&p, &i);
    */

    file f;

    init_file(&f);
    if(file_vide(&f))
        printf("Filevide\n");
    else    
        printf("file non vide\n");
    ajouter(&f, 5);
    if(file_vide(&f))
        printf("Filevide\n");
    else    
        printf("file non vide\n");
    retirer(&f, &i);
    if(file_vide(&f))
        printf("Filevide\n");
    else    
        printf("file non vide\n");

    printf(" %i\n", i);
    return 0;
}