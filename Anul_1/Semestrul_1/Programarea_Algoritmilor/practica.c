#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 200 
char sir2[MAX];
char sir[] = "Acesta este un sir";
char concatenare[MAX];
int main() {
    printf("Sirul este: %s\n", sir);
    for(int i = 0; sir[i]; i++) {
        sir[i] = toupper(sir[i]);
    }
    printf("Sirul schimbat este: %s\n", sir);
    for(int i = 0; sir[i]; i++) {
        sir[i] = tolower(sir[i]);
    }
    printf("Sirul schimbat este: %s\n", sir);
    char sir[2] = "X";
    printf("Sirul schimbat este: %s\n", sir);
    printf("Lungimea sirului este: %d\n", strlen(sir));
    gets(sir2);
    printf("Sirul introdus este: %s\n", sir2);
    for(int i =0; sir2[i]; i++) {
        sir2[i] = toupper(sir2[i]);
    }
    printf("Sirul introdus si schimbat este: %s\n", sir2);
    printf("Lungimea sirului este: %d\n", strlen(sir2));
    strcat(concatenare, sir);
    strcat(concatenare, sir2);
    printf("Rezultatul concatenarii este: %s\n", concatenare);
    strcmp(sir, sir2) == 0 ? printf("Sirurile sunt egale\n") : printf("Sirurile nu sunt egale\n");
    return 0;
}

