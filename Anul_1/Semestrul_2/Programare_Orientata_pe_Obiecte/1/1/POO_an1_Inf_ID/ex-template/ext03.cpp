// functie generica (template) cu parametru non-tip
#include <iostream>
using namespace std;

template <class T, int N>
T* vector (T value, T end) {
  T* p=new T[N+1];
  for(int i=0; i<N; i++)
  p[i]=value;
  p[N]=end;
  return p;
}
int main () {
  int *pint;
  cout << vector<char, 10>('A','\0')<< endl;
  pint=vector<int, 20>(1,0);
  for(int i=0; i<20; i++)
  cout << pint[i] << ',';
  cout << pint[20] << endl;
  return 0;
}
