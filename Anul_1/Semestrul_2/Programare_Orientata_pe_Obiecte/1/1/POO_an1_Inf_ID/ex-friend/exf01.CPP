#include <iostream.h>
#include <string.h>
using namespace std;
class Stan{
  public: Stan(char *msj){ strcpy(mesaj,msj);};
	  void arata_mesaj(void){cout << mesaj << endl;};
	  friend class Bran;
	  void arata_bran(class Bran bran);
   private: char mesaj[256];
};

class Bran{
  public: Bran(char *msj){strcpy(mesaj,msj);};
	  void arata_mesaj(void){cout << mesaj << endl;};
	  friend class Stan;
	  void arata_stan(class Stan stan);
  private: char mesaj[256];
};

void Stan::arata_bran(class Bran bran){ cout << bran.mesaj << endl;};
void Bran::arata_stan(class Stan stan){ cout << stan.mesaj << endl;};

int main(void){
  class Bran bran("Hi,hi,hi...");
  class Stan stan("Ho,ho,ho...");
  bran.arata_mesaj();
  bran.arata_stan(stan);
  stan.arata_mesaj();
  stan.arata_bran(bran);
}

