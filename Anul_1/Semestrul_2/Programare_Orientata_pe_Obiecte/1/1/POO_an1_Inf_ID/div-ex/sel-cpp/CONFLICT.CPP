#include <iostream.h>

class Baza{
  public:  void afisare(void){
	       cout << "Aceasta este clasa Baza" <<endl;};
};
class Derivata:public Baza{
  public: void afisare(void){
    cout << "Aceasta este clasa Derivata" << endl;};
};
void main(void){
   Derivata clasa_mea;
   clasa_mea.afisare();
}