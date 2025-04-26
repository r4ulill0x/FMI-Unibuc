//ACEST PROGRAM CONTINE TREI ERORI SI NU SE VA COMPILA
#include <iostream.h>

class baza{
  public: int i;
};

class derivata1:public baza{
  public: int j;
};

class derivata2:public baza{
  public:int k;
};

class derivata3:public derivata1,public derivata2{
  public: int sum;
};

void main(void){
  derivata3 obiect;
  obiect.i=10;
  obiect.j=20;
  obiect.k=30;
  obiect.sum=obiect.i+obiect.j+obiect.k;
  cout << obiect.i << " ";
  cout << obiect.j << " " << obiect.k << " ";
  cout << obiect.sum << endl;
}