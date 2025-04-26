// functie generica (template)
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

template <class T>
T GetMax (T a, T b) {
  T result;
  result = (a>b)? a : b;
  return (result);
}

int main () {
  int i=5, j=6, k; Complex u(3,6), v(5,1), w;
  long l=10, m=5, n;
  k=GetMax<int>(i,j);
  n=GetMax<long>(l,m);
  w=GetMax<Complex>(u,v);
  cout << k << endl;
  cout << n << endl;
  w.arata();
  return 0;
}
