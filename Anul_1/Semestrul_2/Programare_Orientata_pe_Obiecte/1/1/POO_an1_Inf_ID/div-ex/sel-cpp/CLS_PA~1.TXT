#include <iostream.h>

class baza{
  protected:int i;
  public:   baza(int x){
	       i=x;
	       cout << "Construieste clasa baza.\n";};
	    ~baza(void){cout << "Distruge clasa baza.\n";}
};

class derivata :public baza{
    int j;
    public:derivata(int x, int y):baza(y){
		j=x;
		cout << "Construieste clasa derivata.\n";}
	    ~derivata(void){cout <<  "Distruge clasa derivata.\n";}
	    void arata(void){cout << ", " << endl;}
};
void main(void){
  derivata obiect(3,4);
  obiect.arata();
}

