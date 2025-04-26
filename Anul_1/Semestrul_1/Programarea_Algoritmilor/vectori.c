#include <stdio.h>

// Vector: o colectie liniara si omogena

// <tip_elemente> <nume_vector>[<dimensiune>];
int a[100];
float b[30];

int v1[3] = {1, 2, 3}; // v1 are dimensiunea 3 si toate elementele sunt initializate
float v2[] = {1.2, 3.14}; // v2 are dimensiunea 2 si elementele sunt initializate. Dimnesiunea este calculata de catre compilator.

#define MAX_LEN 1000

int v3[MAX_LEN]; // Avem un vector v3 de intregi cu MAX_LEN elemenete neinitializate
int v4[MAX_LEN] = {0}; // Avem un vector v4 de intregi cu MAX_LEN elemente initializate cu 0
int v5[MAX_LEN] = {0}; // Avem un vector v5 de intregi cu MAX_LEN elemente initializate cu 0

// Functie de cautare liniara.
int cautare_liniara(int v[], int nr_elemenete, int element_cautat) {
    for (int i = 0; i < nr_elemenete; ++i) {
        if (v[i] == element_cautat) {
            return i;
        }
    }

    return -1;
}

int main() {
    int n;

    printf("Citim n de la tastatura:\n");

    // &n -> adresa de memoirie unde este salvata variabila `n`
    scanf("%d", &n);
    printf("Am citit de la tastatura n = %d\n", n);

    int vec[MAX_LEN] = {0};
    for (int i = 0; i < n; ++i) {
        scanf("%d", &vec[i]);
    }

    printf("Vectorul citit: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", vec[i]);
    }
    printf("\n");

    printf("Introduceti elementul cautat: ");

    int element_cautat;
    scanf("%d", &element_cautat);

    int index = cautare_liniara(vec, n, element_cautat);
    printf("Element gasit la pozitia: %d\n", index);

    return 0;
}