#include <iostream.h>

class Baza{
  public: void arata_baza(void){ cout << "Mesajul clasei Baza\n";}
};

class Nivel1:public Baza{
  public: void arata_nivel1(void){
	     arata_baza();
	     cout << "Mesajul clasei Nivel 1\n";};
};

class Nivel2:public Nivel1{
  public: void arata_nivel2(void){
	       arata_nivel1();
	       cout << "Mesajul clasei Nivel 2 \n";};
};

class Nivel3:public Nivel2{
   public:  void arata_nivel3(void){
	       arata_nivel2();
	       cout << "Mesajul clasei Nivel 3 \n";
	    };
};
void main(void){
   Nivel3 datele_mele;
   datele_mele.arata_nivel3();
}


