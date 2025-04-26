#include<iostream.h>
#include<iomanip.h>
#include<string.h>

class sir  //creez clasa sir
{
public:
sir operator +(sir sir_adaug);
sir(char *in_sir)
{strcpy(prim,in_sir);
lung=strlen(prim);
}
sir(){lung=0;};// nu e bine
void afisare()      
{cout<<prim;};

private:
char prim[100]; //TEMA: ALOCARE DINAMICA (VARIANTE)
int lung;
};

sir sir::operator +(sir sir_adaug)
{
sir nou;
int lungime_nou;
lungime_nou=strlen(prim)+strlen(sir_adaug.prim);//lungimea sirului final este lungimea primului sir +lungimea celui de-al doilea
strcpy(nou.prim,prim);   //copiaza in nou.prim primul sir
strcat(nou.prim,sir_adaug.prim); //in nou prim adauga si cel de-al doilea sir
return nou;
}

int main()
{
sir text("1 decembrie");
text=text+" 2007"; // conversie! ? atribuire
text.afisare();//afiseaza sirul
}
