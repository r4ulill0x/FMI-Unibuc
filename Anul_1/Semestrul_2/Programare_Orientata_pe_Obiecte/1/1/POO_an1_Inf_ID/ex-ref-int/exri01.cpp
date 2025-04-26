#include <iostream.h>
int a;
int & schimba(int b)
{
 a+=b;
 cout<<"in schimba a="<<a<<endl;
 return a; // se intoarce referinta la variabila globala a schimbata de functie
}
int main()
{
 schimba(2)+=3; // se schimba valoarea lui a de catre functie si de catre atribuire
 cout<<"in main a="<<a<<endl;
}
