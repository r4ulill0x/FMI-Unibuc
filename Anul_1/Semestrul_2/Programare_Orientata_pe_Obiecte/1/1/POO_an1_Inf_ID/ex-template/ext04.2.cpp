// clasa generica (template)
#include <iostream>
using namespace std;
class Complex
{public:
	int re,im;
	Complex(int a,int b){ re=a;im=b;}
	Complex(){};
	int operator > (Complex x) {
		if (re>x.re || re==x.re && im>x.im) return 1; else return 0;}
	void arata() {cout << "re="<<re<<"," << "im=" << im << "."<< endl;}
};
template <class T>
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
