#include <stdio.h>
// #include "fisier_1.h"

// tip_returnat nume_functie (tip_param1 nume_param1, tip_param2 nume_param2, ...)
// void functie_1();

// Trimitere parametru prin valoare
// int functie_2(int a);

// Timitere parametru prin referinta
// int functie_3(int *n);

int main(int argc, char *argv[]) {
    // functie_1();

    int a = 3;
    int rez = functie_2(a);
    printf("rez = %d\n", rez);

    return 0;
}

// void functie_1() {
//     printf("functie_1\n");
// }

int functie_2(int a) {
    return a + 1;
}