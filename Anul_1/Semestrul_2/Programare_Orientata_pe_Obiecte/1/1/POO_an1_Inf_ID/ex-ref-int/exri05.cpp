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
 cout<<schimba(a,2); // valoarea intoarsa intr-o variabila temporara, afisata corect
 cout<<" este valoarea intoarsa in main"<<endl;
 cout<<"in main a="<<a;
}
