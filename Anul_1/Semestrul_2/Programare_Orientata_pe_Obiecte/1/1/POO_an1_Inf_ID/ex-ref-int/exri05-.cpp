#include <iostream.h>
int & schimba(int a, int b)
{
    a+=b;
    cout<<"in schimba a="<<a<<endl;
 return a; // avertisment: se intoarce referinta la variabila temporara
           // in care s-a transmis argumentul a 
}
int main()
{
 int a=0;
 cout<<"valoare intoarsa="<<schimba(a, 2)<<endl;
 // valoarea intoarsa este transmisa corect intr-o variabila temporara
 // care este eliminata pe parcursul evaluarii expresiei, inainte de afisare
 cout<<"in main a="<<a;
}
