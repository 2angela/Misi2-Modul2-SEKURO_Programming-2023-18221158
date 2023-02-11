#include "console.h"

/* 
cara compile
gcc main.c console.c menu.c history.c -o main
*/

int main() {
    Menu M;
    Riwayat H;
    createMenu(&M);
    H.Count = 0;
    home(M, &H);
    return 0;
}