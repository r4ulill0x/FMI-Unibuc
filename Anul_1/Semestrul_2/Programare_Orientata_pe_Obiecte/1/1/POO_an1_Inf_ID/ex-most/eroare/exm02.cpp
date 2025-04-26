#include <iostream.h>
class baza{
int i,j;
public:
	void pune(int a, int b){i=a; j=b;}
	void arata() {cout<<i<<" "<<j<<"\n";}
};
class derivata: protected baza{
int k;
public:
derivata(int x){k=x;}
void aratak() {cout<<k<<"\n";}
void arataij() {
     cout<<"Datele din baza\n";
     cout<<i<<" "<<j<<"\n";
}
};
main()
{
derivata ob (4);
ob.pune(2,3);
ob.arata();
ob.aratak();
ob.arataij();
 return 0;
}
