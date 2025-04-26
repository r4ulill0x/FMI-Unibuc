// clasa generica (template)
#include <iostream>
using namespace std;

template <class T, class U>
class mypair {
    T a; U b;
  public:
    mypair (T first, U second)
      {a=first; b=second;}
    T getmax ();
};

template <class T, class U>
T mypair<T,U>::getmax ()
{
  T retval;
  retval = a>b? a : (T)b;
  return retval;
}

int main () {
  mypair <int, float> myobject (100, 175.12);
  cout << myobject.getmax();
  return 0;
}
