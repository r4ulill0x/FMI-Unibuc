#include <iostream.h>

class baza{
    int i;
  public: int j,k;
	  void seti(int x){i=x;};
	  int redai(void){return i;};
};

class derivata:private baza{
  public:  baza::j;
	   baza::seti;
	   baza::redai;
	   int a;
};
void main(void){
  derivata obiect;
  obiect.j=20;
  obiect.a=40;
  obiect.seti(10);
  cout << obiect.redai() << ", " << obiect.j << ", " << obiect.a;
}