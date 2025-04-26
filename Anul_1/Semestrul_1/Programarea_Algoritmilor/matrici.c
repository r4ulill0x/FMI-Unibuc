#include <stdio.h>

#define MAX_ELEMENTE 100

// matrice = colectie omogena si bidimensionala de elemente

// <tip_elemente> <nume_matrice>[<dim_1>][<dim_2>];
int mat[5][10];
float mat2[10][MAX_ELEMENTE];

// tablouri multidimensionale
// <tip_elemente> <nume_tablou>[<dim_1>][<dim_2>]...[dim_n];
int cub[3][3][3];

void afisare_matrice(int matrice[MAX_ELEMENTE][MAX_ELEMENTE], int nr_linii, int nr_coloane) {
    // Reprezentarea matricei in memorie:
    // matrice: [x_1_1, x_1_2, ..., x_1_100], [x_2_1, x_2_2, ..., x_2_100], ..., [x_100_1, x_100_2, ..., x_100_100]

    printf("Matrice:\n");
    for (int i = 0; i < nr_linii; i++) {
        for (int j = 0; j < nr_coloane; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Citim de la tastatura numer de linii/coloane:\n");

    // &n -> adresa de memorie unde este salvata variabila `n`
    scanf("%d", &n);
    printf("Am citit de la tastatura n = %d\n", n);

    if (n > MAX_ELEMENTE) {
        printf("n = %d prea mare!\n", n);
        return 1;
    }

    int matrice[MAX_ELEMENTE][MAX_ELEMENTE];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrice[i][j]);
        }
    }

    afisare_matrice(matrice, n, n);

    // int matrice_2[3][3] = {
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9}
    // };
    // // In memorie matrice_2 arata asa:
    // // matrice_2: [x_1_1, x_1_2, x_1_3], [x_2_1, x_2_2, x_2_3], [x_3_1, x_3_2, x_3_3]

    // int matrice_2[][MAX_ELEMENTE] = {
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9}
    // };
    // // In memorie matrice_2 arata asa:
    // // matrice_2: [x_1_1, x_1_2, x_1_3, ..., x_1_100], [x_2_1, x_2_2, x_2_3, ..., x_2_100], [x_3_1, x_3_2, x_3_3, ..., x_3_100]

    // afisare_matrice(matrice_2, 3, 3);

    printf("\nMatricea transpusa:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrice[j][i]);
        }
        printf("\n");
    }

    return 0;
}
