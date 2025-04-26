// functie generica (template)
#include <iostream>
using namespace std;

template <class T, class U>
T GetMax (T a, U b) {
  T result;
  result = (a>b)? a : b;
  return (result);
}

int main () {
  int i=5, j=6, k;
  long l=10, m=5, n;
  k=GetMax<int, int>(i,j);
  n=GetMax<long, int>(l,k);
  cout << k << endl;
  cout << n << endl;
  return 0;
}
