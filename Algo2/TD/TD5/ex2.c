#include <stdio.h>

#define tmax 50
#define MAX_BITS 8
int pile[tmax];
int sommet;

void initpile(void){
    sommet = -1;
}

void empiler(int x){

    if(sommet < tmax-1){
        sommet++;
        pile[sommet] = x;
    }
}

void depiler(int *x){

    if(sommet > -1){
        *x = pile[sommet];
        sommet--;
    }
}

int pilevide(void){
    return (sommet == -1);
}

void convertir(int nb){

    int val = nb;
    while(val != 0){
        empiler(val % 2);
        //printf("%i %i \n", val % 2, val / 2);
        val = val / 2;
    }
}

int main(){
    int x, y;

    scanf("%i", &x);

    initpile();
    convertir(x);
    while(1){
        if(pilevide())
            break;
        depiler(&y);
        printf("%i", y);
    }

    return 0;
}