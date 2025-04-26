// clasa generica (template)
// EROARE. DE EXPLICAT SI CORECTAT
#include <iostream.h>
using namespace std;
class Complex // numere complexe
{public:
	int re,im;
	Complex(int a,int b){ re=a;im=b;}
	Complex(){};
	void arata() {cout << "re="<<re<<"," << "im=" << im << "."<< endl;}
};
template <class T> // perechi ordonate cu elemente de tip T
class mypair {
    T a, b;
  public:
    mypair (T first, T second)
      {a=first; b=second;}
    T getmax ();
};

template <class T>
T mypair<T>::getmax ()
{
  T retval;
  retval = a>b? a : b;
  return retval;
}

int main () {
  Complex u(3,6), v(5,1), w;
  mypair <int> myobject (100, 75);
  mypair <Complex> myobject1 (u, v);
  cout << myobject.getmax()<<endl;
  w=myobject1.getmax();
  w.arata();
  return 0;
}
