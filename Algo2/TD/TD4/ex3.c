#include <stdio.h>

#define N 50
#define C 8

int fibo(int x){

    if(x == 1)
        return 0;
    else {
        if(x == 2)
            return 1;
        else{
            return fibo(x - 1) + fibo( x - 2);
        }
    }
}// Cette fonction est récursive non terminale

int fibo_iter1(int x){
    int tab[N];
    int i;

    tab[0] = 0;
    tab[1] = 1;
    for(i = 2; i < x; i++)
        tab[i] = tab[i - 1] + tab[i - 2];
    
    return tab[x - 1];
}

int fibo_iter2(int x){
    int ui, i;
    int ui_1 = 1;
    int ui_2 = 0;

    if(x == 1)
        return ui_2;
    if(x == 2)
        return ui_1;
    for(i = 3; i <= x; i++){

        ui = ui_1 + ui_2;
        ui_2 = ui_1;                     
        ui_1 = ui;
    }

    return ui;
}

int main(){

    printf("%i\n", fibo(C));
    printf("%i\n", fibo_iter1(C));
    printf("%i\n", fibo_iter2(C));
}