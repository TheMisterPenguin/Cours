#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    int max;
    int min;
    int nombre_lu;
    FILE *r;
    FILE *p;
    FILE *n;

    r = fopen("releves.txt", "r");
    p = fopen("positif.txt", "w");
    n = fopen("negatif.txt", "w");

    min = 0;
    max = 0;

    fscanf(r, "%i", &nombre_lu);
    while(! feof(r)){

        if( nombre_lu < min)
            min = nombre_lu;
        if( nombre_lu > max)
            max = nombre_lu;
        
        if( nombre_lu >= 0)
            fprintf(p, " %i ", nombre_lu);
        if( nombre_lu < 0)
            fprintf(n, " %i ", nombre_lu);
        fscanf(r, "%i", &nombre_lu);
    }

    printf("Valeur maximale : %i, valeur minimale : %i\n", max, min);

    fclose(r);
    fclose(p);
    fclose(n);

    return 0;
}