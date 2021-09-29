#include <stdio.h>

int pgcd_rec(int a, int b){
        if(a == b)
            return a;

        if( a > b)
            return pgcd_rec(a - b, b); 
        else {  
            return pgcd_rec(a, b - a);
        }
}

int main(){
    
    printf("%i\n", pgcd_rec(36,96));
    return 0;
}

//La fonction est récursive terminale
