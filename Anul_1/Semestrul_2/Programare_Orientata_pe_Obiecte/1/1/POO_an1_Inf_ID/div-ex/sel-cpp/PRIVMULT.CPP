#include <iostream.h>

class Unu{
  public:Unu(void){
	   cout << "Constructor pentru Unu\n";
	   unu=1;};
	 int unu;
};
class Doi{
  public: Doi(void){
	    cout << "Constructor pentu Doi\n";
	    doi=2;};
	  int doi;
};

class Trei{
   public: Trei(void){
	      cout << "Constructor pentru Trei\n";
	      trei=3;};
	   int trei;
};
class Derivata:private Unu,private Trei,public Doi{
  public: Derivata(void):Unu(),Doi(),Trei()
	     {cout << "Apelat constructor Derivata\n";};
	  void arata_valoarea(void)
	     {cout << unu << doi << trei << endl;};
};

void main(void){
  Derivata clasa_mea;
  clasa_mea.arata_valoarea();
  cout << clasa_mea.doi;
}








