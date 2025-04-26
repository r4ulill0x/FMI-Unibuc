#include <iostream.h>
class Baza
{
       public:
          Baza(){ cout<<"Constructor: Baza"<<endl;}
          virtual ~Baza(){ cout<<"Destructor : Baza"<<endl;}
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
        delete Var; // acum memoria alocata pentru Var->sir este eliberata
			        // deoarece se apeleaza ambii destructori ~Derivata() si ~Baza()
}
