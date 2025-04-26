#include <iostream.h>
#include <string.h>

class Baza{
  public: Baza(char *sir){ strcpy(mesaj,sir);};
	  void arata_baza(void){
	     cout << mesaj << endl;};
  protected: char mesaj[256];
};

class Nivel1:public Baza{
    public: Nivel1(char *sir,char *baza):Baza(baza){strcpy(mesaj,sir);};
	    void arata_nivel1(void){cout << mesaj << endl;};
    protected: char mesaj[256];
};

class De_jos: public Nivel1{
   public:  De_jos(char *sir,char *nivel1,char *baza):Nivel1(nivel1,baza){
	       strcpy(mesaj,sir);};
	    void arata_de_jos(void){
		arata_baza();
		arata_nivel1();
		cout << mesaj << endl;
	      };
   protected: char mesaj [256];
};

void main(void){
 De_jos jos("Mesajul clasei De_jos","Mesajul clasei Nivel1","Mesajul clasei Baza");
 jos.arata_de_jos();
}



