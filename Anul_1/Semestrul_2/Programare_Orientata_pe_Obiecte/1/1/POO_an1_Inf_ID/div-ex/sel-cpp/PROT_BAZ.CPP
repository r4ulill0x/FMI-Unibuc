#include <iostream.h>

class baza{
  protected: int i,j;
  public:    void setij(int a,int b){i=a;j=b;};
	     void arataij(void){cout << i << ' ' << endl;};
};
class derivata:protected baza{
  private: int k;
  public:  void setk(void){
	      setij(10,12);
	      k=i*j;};
	   void arataall(void){
	      cout << k << ' ';
	      arataij();};
};
void main(void){
   derivata obiect;
   //obiect.setij(2,3);Aceasta este o comanda ilegala
   //deoarece setij este un membru protejat al calsei derivata
   //obiect.arataij();Aceasta este de asemenea o comanda ilegala
   obiect.setk();
   obiect.arataall();
}