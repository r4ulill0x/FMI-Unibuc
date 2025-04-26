#include <iostream.h>

int & schimba(int a, int b)
{
    cout<<"in schimba a+b="<<a+b<<endl;
 return a+b; // eroare: se intoarce referinta la variabila temporara ! DE CORECTAT
} 
int main()
{
 cout<<"in main a="<<schimba(0,2)<<endl;
}
