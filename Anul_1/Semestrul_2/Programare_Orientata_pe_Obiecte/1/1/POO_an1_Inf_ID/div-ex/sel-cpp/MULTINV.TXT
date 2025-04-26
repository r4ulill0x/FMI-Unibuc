#include <iostream.h>

class Unu{
  public:  Unu(void){cout << "Constructorul clasei Unu\n";};
};
class Doi{
  public:  Doi(void){cout << "Constructorul calsei 2\n";};
};
class Trei{
  public: Trei(void){ cout << "Constructorul calsei 3\n";};
};
class Derivata:public Unu,public Trei,public Doi{
  public:Derivata(void):Unu(),Doi(),Trei(){
	    cout << "Apelam constructorul clasei Derivata\n";};
};
void main(void){
  Derivata clasa_mea;
}


