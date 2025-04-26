#include <iostream.h>
int a;
int &schimba(int b)
{
 a+=b;
 cout<<"in schimba b="<<b<<" a="<<a<<endl;
 return a;
}
int main()
{
 schimba(2)=schimba(1)+3; 
 cout<<"in main a="<<a<<endl;
}
