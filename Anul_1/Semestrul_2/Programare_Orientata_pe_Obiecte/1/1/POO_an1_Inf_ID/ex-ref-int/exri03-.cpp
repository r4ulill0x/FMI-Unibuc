#include <iostream.h>
int & schimba(int b)
{
    int a=0;
    a+=b;
    cout<<"in schimba a="<<a<<endl;
    return a; // avertisment: se intoarce referinta la variabila locala a 
}
int main()
{
 cout<<"valoarea intoarsa in main este "<<schimba(2)<<endl; 
// valoarea intoarsa este transmisa corect intr-o variabila temporara
// care este eliminata pe parcursul evaluarii expresiei, inainte de afisare
}
