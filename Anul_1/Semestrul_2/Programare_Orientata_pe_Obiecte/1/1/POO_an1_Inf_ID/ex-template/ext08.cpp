// supraincarcarea functiilor template cu functii non-template
// ambiguitate: au prioritate functiile non-template
#include <iostream>
using namespace std;

template<class T> void f(T x, T y) { cout << "Template" << endl; }

void f(int w, int z) { cout << "Non-template" << endl; }

int main() {
   f( 1 ,  2 ); // non-template
   f('a', 'b'); // template: T este char
   f(1, 1.5); // non-template cu avertisment (conversie double->int)
   f('b', 1.5); // non-template cu avertisment (conversie double->int)
   f(2.3, 1.5); // template: T este double
   f( 1 , 'b'); // non-template
}
