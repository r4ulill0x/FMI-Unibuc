#include<iostream.h>
#include<iomanip.h>
#include<string.h>

class sir  //creez clasa sir
{
public:
friend sir operator +(sir sir1, sir sir2); // suficient
sir(char *in_sir)
{
         cout<<"constructor sir(char *)"<<endl;
         strcpy(prim,in_sir);
         lung=strlen(prim);
}
sir()
{
 cout<<"constructor sir()"<<endl;
 lung=0; prim[0]='\0'; 
}// bine
void afisare()      
{cout<<prim<<'\n'; cout<<"lungime="<<lung<<'\n';};

private:
char prim[100]; //TEMA: ALOCARE DINAMICA (VARIANTE)
int lung;
};
sir operator +(sir sir1, sir sir2)
{
sir nou;
int lungime_nou;
lungime_nou=strlen(sir1.prim)+strlen(sir2.prim);//lungimea sirului final este lungimea primului sir +lungimea celui de-al doilea
strcpy(nou.prim,sir1.prim);   //copiaza in nou.prim primul sir
strcat(nou.prim,sir2.prim); //in nou prim adauga si cel de-al doilea sir
nou.lung=lungime_nou;
return nou; // complet!
}
int main()
{
sir text("1 decembrie"), // constructor definit
    text1, text2,  // constructor fara argumente
     text3=text;   // ? constructor
text.afisare();//afiseaza primul sir
text1.afisare();//afiseaza al doilea sir
text2.afisare();//afiseaza al treilea sir
text3.afisare();//afiseaza al patrulea sir
text1=(sir)"2007 "+ text; //  da
text1.afisare();//afiseaza al doilea sir
text2="2007 "+ text; //  da
text2.afisare();//afiseaza al treilea sir
text3="1 aprilie 2009";
text3.afisare();//afiseaza al patrulea sir
}
