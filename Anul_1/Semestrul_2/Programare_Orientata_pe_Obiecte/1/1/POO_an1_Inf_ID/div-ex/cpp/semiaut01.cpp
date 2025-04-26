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
    int get_na() {return na;}; // intoarce numarul de simboluri
    int get_ns() {return ns;}; //  intoarce numarul de stari
    int* get_tran() {return tran;}; // intoarce functia de tranzitie
    char *get_nume() {return nume;};  // intoarce numele
   // destructor
   ~semiautomat() {delete [] tran; cout<<"Semiautomatul "<<nume<<" a fost distrus.\n";};
};
int main()
{
 {
   semiautomat s; // obiect creat fara initializare => se apeleaza constructorul fara parametri
   int m=s.get_na(), n=s.get_ns();
   char *text[][2]={{" simboluri", " simbol"}, {" stari", " stare"}}, punct[]={'.',';'};
   cout<<"Semiautomatul "<<s.get_nume()<<" are un alfabet cu "<<m<<text[0][m==1]<<" si "<<n<<text[1][n==1]<<".\n";
   int *t=s.get_tran(), k=0, l=m*n-1;
   cout << "Functia de tranzitie duce\n";
   for (int i=0; i<n; i++) {
      cout<< "starea "<< i << " cu:\n";
      for (int j=0; j<m; j++, k++)
        cout << "simbolul "<<j<<" in starea "<<t[k]<<punct[k<l]<<'\n';
  }
 } // obiectul distrus automat => se apeleaza destructorul
cout<<"Apasati tasta '1' si <Enter> pentru terminare.\n";
char c='0';
while (c!='1') cin>> c;
}
