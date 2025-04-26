#include <iostream.h>

class Unu{
   public: Unu(void){ cout << "Constructor pentru Unu\n";};
	   ~Unu(void){ cout << "Destructor pentru Unu\n";};
};
class Doi{
   public: Doi(void){ cout << "Constructor pentru Doi\n";};
	   ~Doi(void){ cout << "Destructor pentru Doi\n";};
};
class Trei{
   public: Trei(void){ cout << "Constructor pentru Trei\n";};
	   ~Trei(void){ cout << "Destructor pentru Trei\n";};
};
class Derivata:public Unu,public Doi,public Trei{
   public: Derivata(void):Unu(),Doi(),Trei(){
	      cout << "Apelat constructor derivata\n";};
	   ~Derivata(void){
	      cout << "Apelat destructor Derivata\n";};
};
void main(){
  Derivata clasa_mea;
}







