#include <stdio.h>

/* 2^3 : 2 * 2^2 = 2 * 4 = 8
        : 2 * 2^1 = 2 * 2 = 4
        : 2 * 2^0 = 2 * 1 = 2 */

int puissance(int x, int n, int result){

    if(n == 0)
        return result;
    else{
        return puissance(x, n-1, x * result);
    }
}

int puissance_iter(int x, int n, int result){

    while(n != 0){
        n--;
        result = result * x;
    }

    return result;
}

int main(){

    printf("%i\n", puissance(5, 2, 1));
    printf("%i\n", puissance_iter(5, 2, 1));
}