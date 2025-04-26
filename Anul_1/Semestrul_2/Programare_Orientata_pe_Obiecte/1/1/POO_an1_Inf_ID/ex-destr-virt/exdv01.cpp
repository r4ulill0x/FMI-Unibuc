#include <iostream.h>
class Baza
{
       public:
          Baza(){ cout<<"Constructor: Baza"<<endl;}
          ~Baza(){ cout<<"Destructor : Baza"<<endl;}
};
class Derivata: public Baza
{
     // date proprii
     int n,*sir;
       public:
           Derivata(const int n){ 
            cout<<"Constructor: Derivata"<<endl;
	      sir=new int [n]; // alocarea memoriei pentru sir
		for (int i=0; i<n; i++) sir[i]=0;
           }
           ~Derivata(){ cout<<"Destructor : Derivata"<<endl;
             delete sir; // eliberarea memoriei alocate de constructor
           }
};
int main()
{
        Baza *Var = new Derivata(3); // constructorul Derivata(3) aloca memorie pentru Var->sir
        delete Var; // memoria alocata pentru Var->sir nu este eliberata
			  // deoarece se apeleaza doar destructorul ~Baza()
}
