// date membre statice
#include <iostream.h>
class OClasa{
  public: static int contor;
	  OClasa(int valoare){
	      contor++;
	      datele_mele=valoare;};
	   ~OClasa(void){contor--;};
	   int datele_mele;
};
int OClasa::contor;
void main(void){
  OClasa Unu(1);
  cout << "Unu: " << Unu.datele_mele << ' ' << Unu.contor << endl;
  OClasa Doi(2);
  cout << "Doi:" << Doi.datele_mele << ' ' << Doi.contor << endl;
  OClasa Trei(3);
  cout << "Trei: " << Trei.datele_mele << ' ' << Trei.contor << endl;
}

