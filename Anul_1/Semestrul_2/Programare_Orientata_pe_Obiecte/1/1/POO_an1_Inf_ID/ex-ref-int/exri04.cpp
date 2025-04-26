#include <iostream.h>

int & schimba(int &a, int b)
{
    a+=b;
    cout<<"in schimba a="<<a<<endl;
 return a; // corect: se intoarce referinta la argumentul transmis prin referinta a 
}
int main()
{
 int a=0;
 cout<<"in main a="<<schimba(a, 2)<<endl; // valoarea intoarsa este pastrata
                                          // pana la evaluarea intregii expresii
                                          // si afisata corect
}
