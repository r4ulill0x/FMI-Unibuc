#include <iostream.h>

class Baza{
  public: void afisare(void){cout << "Aceasta este clasa Baza" << endl;};
};

class Derivata:public Baza{
  public:  void afisare(void){ cout<< "Acesta este clasa Derivata" << endl;};
};
void main(void){
  Derivata clasa_mea;
  clasa_mea.afisare();
  clasa_mea.Baza::afisare();
}
