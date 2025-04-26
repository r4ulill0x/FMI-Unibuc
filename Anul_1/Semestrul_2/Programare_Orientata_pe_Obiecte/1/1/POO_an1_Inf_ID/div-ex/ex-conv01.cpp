#include <iostream.h>
using namespace std;
class complex {

      //re=partea reala,im=partea imaginara
      float re,im;
 public:
      complex(float r ,float i=0) //constructor cu 2 parametri, i cu valoare implicita 
                                   
      { re=r;im=i; 
      cout<<"constructor, "; afisare();}
      complex(complex & c) //constructor copiere
      { re=c.re;im=c.im;
      cout<<"constructor de copiere, ";afisare();}
      operator float() //conversie complex-->float
      {   cout<<"apel float(),re="<<re;
          cout<<",im="<<im<<endl; return re;}
void afisare()
{   cout<<"re="<<re;
    cout<<",im="<<im<<'\n';}
};

void fct(float r)//functie de test
{cout<<"apel fct("<<r<<")\n";}
void fct1(complex c)//functie de test
{cout<<"apel fct1(";c.afisare();cout<<")\n";}
int main()
{
    complex c(1); 
    complex c1(1,1),c2(2,2);
    float r1=0,r2=0;
  r1=(float)c1;
  cout<<"r1="<<r1<<'\n';
  r2=c2;
  cout<<"r2="<<r2<<'\n';
  fct(r1);
  fct(c1);
  fct1(c1);
  fct1((complex)r1);
  fct1(complex(r1));
//fct1(r1);
  r1=c1+r1;
  cout<<"r1="<<r1<<'\n';
  r2=c1+c2;
  cout<<"r2="<<r2<<'\n';
  r2=c2+4.55;
  cout<<"r2="<<r2<<'\n';
}
