#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

int convertir(char c){
    return (int)(c - '0');
}

int faire_operation(int op_a, int op_b, char ope){

    switch (ope)
    {
    case '+' : return op_a + op_b; break;
    case '-' : return op_a - op_b; break;
    case '*' : return op_a * op_b; break;
    case '/' : return op_a / op_b; break;
    }
}

int calculer(char chaine[]){
    int i;
    int dig1, dig2;

    for(i = 0; i != '\n' ; i++){
        if(isdigit(chaine[i])){
            empiler(convertir(chaine[i]));
        }
        else
            if(chaine [i] == '+' || chaine [i] == '-' || chaine [i] == '*' || chaine [i] == '/'){
                depiler(&dig1);
                depiler(&dig2);
                empiler(faire_operation(dig1, dig2, chaine[i]));
            }
        
    }

}