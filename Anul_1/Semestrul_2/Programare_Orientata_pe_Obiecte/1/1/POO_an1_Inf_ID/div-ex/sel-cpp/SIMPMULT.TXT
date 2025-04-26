#include <iostream.h>
#include <string.h>

class Coperta{
  public:    Coperta(char *titlu){strcpy(Coperta::titlu,titlu);};
  protected: char titlu[256];
};

class Pagina{
  public:     Pagina(int linii=55){Pagina::linii=linii;};
  protected:  int linii;
	      char *text;
};
class Carte:public Coperta,public Pagina{
  public:  Carte(char *autor,char *titlu,float cot):Coperta(titlu),Pagina(60){
		strcpy(Carte::autor,autor);
		strcpy(Carte::titlu,titlu);
		Carte::cost=cost;};
	   void arata_carte(void){
	      cout << titlu << endl;
	      cout << autor << '\t' << cost;};
  private: char autor[256];
	   float cost;
};
void main(void){
 Carte text("Jamsa and Klender", "Jamsa's C/C++ Programmmer's Bible",49.95);
 text.arata_carte();
}


