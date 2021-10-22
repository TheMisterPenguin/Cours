#include <windows.h>
#include "couleurs.h"

int main(){ 
    SetConsoleOutputCP(65001);
    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute ( h, CYAN | FOREGROUND_INTENSITY );
    printf("█");

    return 0;
}