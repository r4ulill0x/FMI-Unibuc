#include <iostream.h>
int & schimba(int b)
{
    int a=0;
    a+=b;
    cout<<"in schimba a="<<a<<endl;
    return a; // avertisment: se intoarce referinta la variabila locala a 
}
void afisare(int* v)
{
      cout<<*v;
}
int main()
{
 afisare(&schimba(2)); // valoarea intoarsa intr-o variabila temporara, afisata corect
 cout<<" este valoarea intoarsa in main"<<endl;
}
