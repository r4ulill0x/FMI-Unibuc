#include <iostream.h>
#include <stdlib.h>
class semiautomat {
// date membre (campuri): implicit private
   int na,    // numarul simbolurilor din alfabet
       ns,    // numarul starilor
       *tran; // functia de tranzitie reprezentata ca un pointer la o matrice indexata dupa stari si simboluri
       char *nume; // numele semiautomatului: sir de caractere dat ca un pointer
// functii membre (constructor, metode, destructor) declarate publice
   public:
   // constructor fara parametri
    semiautomat(){
          na=1; ns=1; nume="Anonim";
          tran=new int[1];
          if(!tran) {
             cout<<"Constructie esuata!";
             exit(1);
          }
          tran[0]=0;
          cout<<"S-a creat semiautomatul "<<nume<<".\n";
    };
    // constructor de copiere
    semiautomat(semiautomat &s){
          na=s.na; ns=s.ns; nume=s.nume;
          tran=s.tran;
          cout<<"S-a creat o copie a semiautomatului "<<nume<<".\n";
    };
    int get_na() {return na;}; // intoarce numarul de simboluri
    int get_ns() {return ns;}; //  intoarce numarul de stari
    int* get_tran() {return tran;}; // intoarce functia de tranzitie
    char *get_nume() {return nume;};  // intoarce numele
   // destructor
   ~semiautomat() {delete [] tran; cout<<"Semiautomatul "<<nume<<" a fost distrus.\n";};
};
int main()
{
  int a[]={-1, 1, 3}, *p=a;
  cout<<p<<'\n';
  cout<<p[0]<<','<<p[1]<<','<<p[2]<<'\n';
  delete [] p;
  cout<<p<<'\n';
  cout<<p[0]<<','<<p[1]<<','<<p[2]<<'\n';
  cout<<a<<'\n';
  cout<<a[0]<<','<<a[1]<<','<<a[2]<<'\n';
  p=new int[3];  p[0]=-1; p[1]=1;  p[2]=3;
  cout<<p<<'\n';
  cout<<p[0]<<','<<p[1]<<','<<p[2]<<'\n';
  delete [] p;
  cout<<p<<'\n';
  cout<<p[0]<<','<<p[1]<<','<<p[2]<<'\n';
  p=NULL;
  cout<<p<<'\n';
  // cout<<p[0]<<','<<p[1]<<','<<p[2]<<'\n';
  cout<<"Apasati tasta '1' si <Enter> pentru terminare.\n";
  char c='0';
  while (c!='1') cin>> c;
}
