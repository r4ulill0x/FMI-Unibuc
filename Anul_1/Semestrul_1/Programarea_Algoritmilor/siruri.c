#include <stdio.h>
#include <string.h>

#define MAX 100

// In C un caracter se declara:
char caracter = 'C';

// Sir de caractere: vector de caractere, terminat prin caracterul '\0' (terminator)
char str_1[MAX];
char str_2[] = "un alt sir"; // Va avea dimensiunea 11 (10 caractere + terminatorul)

// ASA NU!
// Nu initializam un vector de caractere cu un sir mai lung decat dimensiunea declarata
// char str_3[3] = "un sir si mai lung";

char sir[6] = "unsir";
char *sir_2 = "unsir"; // !!! compilatorul va salva sirul intr-o zona de memorie fara drepturi de scriere !!!

int main() {
    // printf("%s\n", str_2);

    // printf("sir = %s\n", sir);

    // sir[0] = 'U';
    // printf("sir (dupa atribuire) = %s\n", sir);

    // printf("sir_2 = %s\n", sir_2);

    // sir_2[0] = 'U'; // Illegal action pentru scriere
    // printf("sir_2 (dupa atribuire) = %s\n", sir_2);

    char s1[MAX];
    gets(s1);

    printf("Sirul citit s1: %s\n", s1);

    // char s2[MAX], c;
    // int pozitie = 0;

    // do {
    //     scanf("%c", &c);

    //     if (c == '_') {
    //         break;
    //     }

    //     s2[pozitie] = c;
    //     pozitie++;
    // } while(1);

    // printf("Sirul citit s2: %s\n", s2);

    int lungime_sir = strlen(s1);
    printf("Lungime sir: %d\n", lungime_sir);

    char rezultat_copiere[MAX];

    strcpy(rezultat_copiere, s1);
    printf("Rezultat copiere = %s\n", rezultat_copiere);

    strcpy(rezultat_copiere, " --- ");
    printf("Rezultat copiere = %s\n", rezultat_copiere);

    char s2[MAX];
    gets(s2);

    char rezultat_concatenare[MAX];

    strcat(rezultat_concatenare, s1);
    strcat(rezultat_concatenare, " --- ");
    strcat(rezultat_concatenare, s2);
    printf("Rezultat concatenare = %s\n", rezultat_concatenare);

    char sir[] = "sir nou 0 altceva";
    char *pozitie_caracter = strchr(sir, '0');
    if (pozitie_caracter == NULL) {
        // caracterul nu a fost gasit in sir
        printf("Nu a fost gasit!\n");
    } else {
        // caracterul a fost gasit in sir
        printf("A fost gasit!\n");
    }

    char sir_lung[] = "Acesta este un sir mai lung, dar incape in memorie!";
    char *p = strtok(sir_lung, ".,;:! ");
    while (p != NULL) {
        printf("Token: %s\n", p);
        p = strtok(NULL, ".,;:! ");
    }

    return 0;
}