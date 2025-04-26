#include <iostream.h>
#include <stdlib.h>
// Exemplu complicat intentionat, pentru ilustrarea functionarii
// apelurilor de constructori si de metode
class semiautomat {
// date membre (campuri): implicit private
   static unsigned int nc0, ncop, nc4_1, nset00, nset01, nset02, ndest; // date membre statice
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
    // care modifica parametrul (actiune posibila, dar nerecomandabila)
    // folosindu-se faptul ca parametrul este referinta  (conditie obligatorie pentru
    // constructorul de copiere, in scopul evitarii ciclarii infinite)
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
          s.set(&u);  // modificarea parametrului s prin
                      // apelarea unei metode void, cu parametrul de tip semiautomat
                      // transmis prin adresa; transmiterea prin valoare ar
                      // implica copierea intr-o variabila temporara,
                      // deci apelarea recursiva INFINITA (!) a constructorului de copiere
    }; // distrugerea instantei locale u => apelarea destructorului
    unsigned int get_na() {return na;}; // intoarce numarul de simboluri
    unsigned int get_ns() {return ns;}; //  intoarce numarul de stari
    unsigned int* get_tran() {return tran;}; // intoarce functia de tranzitie
    char *get_nume() {return nume;};  // intoarce numele
    // metoda void care copiaza in semiautomatul curent un semiautomat (parametru dat prin adresa)
    void set(semiautomat* ps) {
           static unsigned int nset00;
           cout<<"Apelare nr. "<<++nset00<<" a metodei void set(semiautomat*)\n";
           cout<<nume<<" devine copie a "<<ps->nume<<".\n=========\n";
           na=ps->na; ns=ps->ns; nume=ps->nume;
           delete [] tran;
           tran=new unsigned int [na*ns];
           if(!tran) {
              cout<<"Alocare esuata!\nApasati o tasta, apoi <Enter>"; char c; cin>>c;
              exit(1); // terminarea programului in caz de esec al alocarii de memorie
           }
           unsigned int* t=ps->tran, k=0;
           for (unsigned int i=0; i<ns; i++)
             for (unsigned int j=0; j<na; j++, k++) tran[k]=t[k];
    };
    // metoda de copiere a unui semiautomat (parametru)
    // in semiautomatul curent  (*this)
    // care intoarce o referinta la acesta
    // parametrul transmis prin valoare => copiere intr-o variabila temporara
    // => apelare a constructorului de copiere
    // => parametrul efectiv este modificat (!)
    // la fiecare apelare a metodei
    semiautomat& set(semiautomat s0) {
           static unsigned int nset01;
           cout<<"Apelare nr. "<<++nset01<<" a metodei semiautomat& set(semiautomat)\n";
           cout<<nume<<" devine copie a "<<s0.nume<<".\n=========\n";
           na=s0.na; ns=s0.ns; nume=s0.nume;
           delete [] tran;
           tran=new unsigned int [na*ns];
           if(!tran) {
              cout<<"Alocare esuata!\nApasati o tasta, apoi <Enter>"; char c; cin>>c;
              exit(1);  // terminarea programului in caz de esec al alocarii de memorie
           }
           unsigned int* t=s0.tran, k=0;
           for (unsigned int i=0; i<ns; i++)
             for (int j=0; j<na; j++, k++) tran[k]=t[k];
           return  *this;  // intoarce referinta => nu se apeleaza constructorul de copiere
    };
    // metoda de copiere in semiautomatul curent (*this) a unui semiautomat (parametru
    // dat ca referinta => nu se apeleaza constructorul de copiere la apelarea metodei)
    // care intoarce o copie a acestuia => apelare a constructorului de copiere
    // la fiecare intoarcere a valorii functiei (executie return)
    // dupa copiere semiautomatul parametru este modificat, devenind un automat
    // cu 1 simbol, 1 stare si un nume nou, dat ca parametru
    semiautomat set(semiautomat& s0, char* numenou) {
           static unsigned int nset02;
           cout<<"Apelare nr. "<<++nset02<<" a metodei semiautomat set(semiautomat&, char*)\n";
           cout<<nume<<" devine copie a "<<s0.nume<<".\n=========\n";
           na=s0.na; ns=s0.ns; nume=s0.nume;  // copierea datelor membre simple
           delete [] tran; // eliberarea memoriei ocupate de vechea functie de tranzitie
           tran=new unsigned int [na*ns]; // alocare de memorie pentru noua functie de tranxitie
           if(!tran) {
               cout<<"Alocare esuata!\nApasati o tasta, apoi <Enter>"; char c; cin>>c;
              exit(1); // terminarea programului in caz de esec al alocarii de memorie
           }
           unsigned int* t=s0.tran, k=0;
           // copierea functiei de tranzitie
           for (unsigned int i=0; i<ns; i++)
             for (unsigned int j=0; j<na; j++, k++) tran[k]=t[k];
           semiautomat s; // crearea unei instante locale cu apelarea
                          // constructorului fara parametri
           s0.set(&s); // copierea instantei noi in parametru
           cout<<s0.nume<<" devine "<<numenou<<",\n"<<"cu 1 simbol si 1 stare.\n=========\n";
           s0.nume=numenou;  // schimbarea numelui parametrului
           s.set(this); // copierea semiautomatului curent in instanta locala s
           return  s;   // intoarce valoare => copiere intr-o variabila temporara
                        // => apelarea constructorului de copiere
                        // => modificarea instantei locale s (!)
                        // daca nu s-ar fi copiat semiautomatul curent in instanta locala
                        // si s-ar fi folosit return *this, constructorul de copiere
                        // ar fi modificat semiautomatul curent
    }; // distrugerea instantei locale s => apelarea destructorului
   // definitia destructorului
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
    s2(s1),// apelare a constructorului de copiere
           // => parametrul s1 este modificat
     s3=s1.set(s2), // apelare a metodei semiautomat& set(semiautomat)
                    // (=> apelare implicita a constructorului de copiere avaand ca parametru
                    // referinta la parametrul efectiv s2
                    // => s2 este modificat),
                    // apoi initializare => apelare a constuctorului de copiere,
                    // avand ca parametru referinta la s1
                    // => s1 este modificat (!)
     s4; // obiect creat fara initializare => se apeleaza constructorul fara parametri
   unsigned int m=(s4.set(s3, "Semiaut3")).get_na(), // apelare a metodei semiautomat set(semiautomat&, char*)
                                                     // care copiaza s3 in s4, modifica s3,
                                                     // si creaza o variabila temporara de tip
                                                     // semiautomat care contine valoarea de intoarcere,
                                                     // care este distrusa dupa evaluarea expresiei in care apare
                                                     // => apelare a destructorului
                n= s4.get_ns();
   char *text[][2]={{" simboluri", " simbol"}, {" stari", " stare"}}, punct[]={'.',';'};
   cout<<"Semiautomatul "<<s4.get_nume()<<" are un alfabet cu "<<m<<text[0][m==1]<<" si "<<n<<text[1][n==1]<<".\n";
   unsigned int *t=s4.get_tran(), k=0, l=m*n-1;
   cout << "Functia de tranzitie duce\n";
   for (unsigned int i=0; i<n; i++) {
      cout<< "starea "<< i << " cu:\n";
      for (unsigned int j=0; j<m; j++, k++)
        cout << "simbolul "<<j<<" in starea "<<t[k]<<punct[k<l]<<'\n';
   }
   m=s1.get_na(), n=s1.get_ns();
   cout<<"Semiautomatul "<<s1.get_nume()<<" are un alfabet cu "<<m<<text[0][m==1]<<" si "<<n<<text[1][n==1]<<".\n";
   t=s1.get_tran(), k=0, l=m*n-1;
   cout << "Functia de tranzitie duce\n";
   for (unsigned int i=0; i<n; i++) {
      cout<< "starea "<< i << " cu:\n";
      for (unsigned int j=0; j<m; j++, k++)
        cout << "simbolul "<<j<<" in starea "<<t[k]<<punct[k<l]<<'\n';
  }
 } // obiecte locale distruse automat => se apeleaza destructorul
cout<<"Apasati tasta '1' si <Enter> pentru terminare.\n";
char c='0';
while (c!='1') cin>> c;
}
