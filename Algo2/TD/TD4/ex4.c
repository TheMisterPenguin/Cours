#include <stdio.h>

#define N 50

 void permuter(int T[], int i, int j){
     int temp;

     temp = T[i];
     T[i] = T[j];
     T[j] = temp;
 }

int partition(int T[N], int debut, int fin){
    int i, j = debut;
    for(i = debut + 1; i <= fin; i++)
        if(T[i] < T[debut]){
            j++;
            permuter(T,i,j);
        }
    permuter(T, debut, j);
    return j;

}

int main(){
    return 2;
}