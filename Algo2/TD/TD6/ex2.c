#include <stdio.h>

#define tmax 50
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

int pilevide(){
    return (sommet == -1);
}

int fibo(int n){
    int resultat = 0;
    int temp;

    initpile();
    empiler(n);
    while(! pilevide()){
        depiler(&temp);
        if(temp == 0 || temp == 1)
            resultat += temp;
        else{
            empiler(temp - 1);
            empiler(temp - 2);
        }
    }

    return resultat;
}

int main(void){

    printf("%i\n", fibo(13));

    return 0;
}