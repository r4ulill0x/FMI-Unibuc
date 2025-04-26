#include <iostream.h>
#include <stdlib.h>
// Exemplu GRESIT INTENTIONAT, pentru ilustrarea functionarii
// apelurilor de constructori si de metode
class semiautomat {
// date membre (campuri): implicit private
   static unsigned int nc0, ncop, nc4_1, nset00,  ndest; // date membre statice
    // utilizate pentru numararea diverselor apelari de functii membre
   unsigned int na,    // numarul simbolurilor din alfabet
               ns,    // numarul starilor
               *tran; // functia de tranzitie reprezentata ca un pointer la o matrice indexata dupa stari si simboluri
       char *nume; // numele semiautomatului: sir de caractere dat ca un pointer
// functii membre (constructor, metode, destructor) declarate publice
   public:
   // constructor fara parametri
    semiautomat(){
          static unsigned int nc0;
          cout<<"Apelare nr. "<<++nc0<<" a constructorului fara parametri\n";
          na=1; ns=1; nume="Anonim";
          tran=new unsigned int[1];
          if(!tran) {
             cout<<"Constructie esuata!\nApasati o tasta, apoi <Enter>"; char c; cin>>c;
             exit(1);   // terminarea programului in caz de esec al alocarii de memorie
          }
          tran[0]=0;
          cout<<"S-a creat semiautomatul "<<nume<<",\n"<<"cu 1 simbol si 1 stare.\n=========\n";
    };
    // constructor cu 4 parametri, reprezentand valorile datelor membre
    semiautomat(unsigned int nai, unsigned int nsi, char* numei, unsigned int* trani){
          static unsigned int nc4_1;
          char *text[][2]={{" simboluri", " simbol"}, {" stari", " stare"}}, punct[]={'.',';'};
          cout<<"Apelare nr. "<<++nc4_1<<" a constructorului semiautomat(int, int, char*, int*)\n";
          na=nai; ns=nsi; nume=numei;
          tran=new unsigned int [na*ns];
          if(!tran) {
             cout<<"Constructie esuata!\nApasati o tasta, apoi <Enter>"; char c; cin>>c;
             exit(1); // terminarea programului in caz de esec al alocarii de memorie
          }
          cout<<"S-a creat semiautomatul "<<nume<<",\n";
          cout<<"cu "<<na<<text[0][na==1]<<" si "<<ns<<text[1][ns==1]<<",\n";
          unsigned int *t=trani, k=0, l=na*ns-1;
          cout << "a carui functie de tranzitie duce\n";
          for (unsigned int i=0; i<ns; i++) {
             cout<< "starea "<< i << " cu:\n";
             for (unsigned int j=0; j<na; j++, k++) {
                  cout << "simbolul "<<j<<" in starea "<<t[k];
                  // verificarea corectitudinii valorilor functiei de tranzitie
                  // si inlocuirea cu 0 a celor incorecte
                  if(t[k]<0 || t[k]>=ns) {
                     cout <<" inexistenta, inlocuita cu 0";
                     t[k]=0;
                    }
                  tran[k]=t[k];
                  cout << punct[k<l] <<'\n';
             }
          }
          cout<<"=========\n";
    };
    // constructor de copiere (recomandabil sa existe)
    // in acest caz nu functioneaza deoarece
    // incearca sa modifice parametrul
    // prin apelarea unei metode care apeleaza implicit
    // constructorul de copiere => ciclare infinita
    semiautomat(semiautomat &s){
          static unsigned int ncop;
          cout<<"Apelare nr. "<<++ncop<<" a constructorului de copiere\n";
          na=s.na; ns=s.ns; nume=s.nume; 
          tran=new unsigned int [na*ns];
          if(!tran) {
             cout<<"Constructie esuata!\nApasati o tasta, apoi <Enter>"; char c; cin>>c;
             exit(1); // terminarea programului in caz de esec al alocarii de memorie
          }
          unsigned int* t=s.tran, k=0;
          cout<<"S-a creat o copie a semiautomatului "<<s.nume<<".\n=========\n";
          for (unsigned int i=0; i<ns; i++)
             for (unsigned int j=0; j<na; j++, k++) tran[k]=t[k];
          unsigned int a[]={1, 0, 0, 1};
          semiautomat u(2, 2, "NOU", a);  // apelarea constructorului cu 4 parametri
          char c;
          cout << "Apasati o tasta, apoi <Enter>\n"; cin >> c;
          s.set(u);  // modificarea parametrului s prin
                      // apelarea unei metode void, cu parametrul de tip semiautomat
                      // transmis prin valoare 
                      // => copierea intr-o variabila temporara,
                      // => apelarea recursiva INFINITA (!) a constructorului de copiere
                      // => programul nu poate continua
    }; // aici ar trebui sa se efectueze
       // distrugerea instantei locale u => apelarea destructorului
       // dar nici una din apelarile recursive nu ajunge aici
       // memoria va fi ocupata de copii ale instantei locale u
       // pana la epuizarea memoriei disponibile
       // => oprirea executiei de catre sistemul de operare
       // sau de catre acest program, in urma imposibilitatii de alocare a memoriei
    unsigned int get_na() {return na;}; // intoarce numarul de simboluri
    unsigned int get_ns() {return ns;}; //  intoarce numarul de stari
    unsigned int* get_tran() {return tran;}; // intoarce functia de tranzitie
    char *get_nume() {return nume;};  // intoarce numele
    // metoda void care copiaza in semiautomatul curent un semiautomat (parametru dat prin valoare =>
    // la apelarea acestei metode se apeleaza si constructorul de copiere)
    void set(semiautomat ps) {
           static unsigned int nset00;
           cout<<"Apelare nr. "<<++nset00<<" a metodei void set(semiautomat*)\n";
           cout<<nume<<" devine copie a "<<ps.nume<<".\n=========\n";
           na=ps.na; ns=ps.ns; nume=ps.nume;
           delete [] tran;
           tran=new unsigned int [na*ns];
           if(!tran) {
              cout<<"Alocare esuata!\nApasati o tasta, apoi <Enter>"; char c; cin>>c;
              exit(1); // terminarea programului in caz de esec al alocarii de memorie
           }
           unsigned int* t=ps.tran, k=0;
           for (unsigned int i=0; i<ns; i++)
             for (unsigned int j=0; j<na; j++, k++) tran[k]=t[k];
    };
   ~semiautomat() {
           static unsigned int ndest;
           cout<<"Apelare nr. "<<++ndest<<" a destructorului\n";
           delete [] tran; cout<<"Semiautomatul "<<nume<<" a fost distrus.\n=========\n";};
};
int main()
{
 {
   unsigned int a[]={0, 5, 1, 3, 2, 0};
   semiautomat s1(2, 3, "Semiaut1", a), // apelare a constructorului cu 4 parametri
    s2(s1);// apelare a constructorului de copiere DEFECT
           // => ciclare infinita => restul programului nu se va executa
           
 } // obiecte locale distruse automat => se apeleaza destructorul
cout<<"Apasati tasta '1' si <Enter> pentru terminare.\n";
char c='0';
while (c!='1') cin>> c;
}
