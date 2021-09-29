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

void convertir(int nb, int base){

    int val = nb;
    while(val != 0){
        empiler(val % base);
        val = val / base;
    }
}

int main(){
    int x, y;
    int base;

    scanf("%i", &base);
    scanf("%i", &x);

    initpile();
    convertir(x, base);
    while(1){
        if(pilevide())
            break;
        depiler(&y);
        printf("%i", y);
    }

    return 0;
}