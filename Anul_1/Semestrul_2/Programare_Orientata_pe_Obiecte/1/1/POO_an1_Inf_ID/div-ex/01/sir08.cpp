#include<iostream.h>
#include<iomanip.h>
#include<string.h>

class sir  //creez clasa sir
{
public:
sir operator +=(sir sir_adaug);
sir(char *in_sir)
{strcpy(prim,in_sir);
lung=strlen(prim);
}
sir()
{
 lung=0; prim[0]='\0'; 
}// bine
void afisare()      
{cout<<prim<<'\n'; cout<<"lungime="<<lung<<'\n';};

private:
char prim[100]; //TEMA: ALOCARE DINAMICA (VARIANTE)
int lung;
};

sir sir::operator +=(sir sir_adaug)
{
//sir nou;
//int lungime_nou;
//lungime_nou=strlen(prim)+strlen(sir_adaug.prim);//lungimea sirului final este lungimea primului sir +lungimea celui de-al doilea
lung=strlen(prim)+strlen(sir_adaug.prim);//lungimea sirului final este lungimea primului sir +lungimea celui de-al doilea
//strcpy(nou.prim,prim);   //copiaza in nou.prim primul sir
strcat(prim,sir_adaug.prim); //in nou prim adauga si cel de-al doilea sir
//nou.lung=lungime_nou;
return *this; 
}

int main()
{
sir text("1 decembrie"), // constructor definit
    text1; // ? constructor 
text.afisare();//afiseaza sirul
text1.afisare();//afiseaza sirul celalalt
text1=text+="2007 "; //  conversie + atribuire 
text.afisare();//afiseaza sirul
text1.afisare();//afiseaza sirul celalalt
}
