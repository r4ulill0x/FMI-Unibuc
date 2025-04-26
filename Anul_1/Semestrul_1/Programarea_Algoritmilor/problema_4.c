#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file = fopen("problema_4.c", "r"); // Deschidem fisierul
    if (file == NULL) {
        printf("Eroare la deschiderea fisierului!\n");
        return 1;
    }

    char c;
    int uppercaseWords = 0, numbersCount = 0;
    int uppercaseLetters = 0, lowercaseLetters = 0, digitCount = 0;

    int inWord = 0, inNumber = 0, isFirstLetterUppercase = 0;

    while ((c = fgetc(file)) != EOF) {
        if (isalpha(c)) {
            if (!inWord) { // Detectam inceputul unui cuvant
                inWord = 1;
                isFirstLetterUppercase = isupper(c);
            }
            if (isupper(c)) uppercaseLetters++;
            else lowercaseLetters++;
        } else {
            if (inWord && isFirstLetterUppercase) {
                uppercaseWords++;
            }
            inWord = 0;
        }

        if (isdigit(c)) {
            if (!inNumber) {
                inNumber = 1;
                numbersCount++; // Gasim un nou numar
            }
            digitCount++;
        } else {
            inNumber = 0;
        }
    }

    fclose(file);

    // Afisarea rezultatelor
    printf("Numar de cuvinte care incep cu litera mare: %d\n", uppercaseWords);
    printf("Numar de numere in text: %d\n", numbersCount);
    printf("Numar de litere mari: %d\n", uppercaseLetters);
    printf("Numar de litere mici: %d\n", lowercaseLetters);
    printf("Numar de cifre: %d\n", digitCount);

    return 0;
}