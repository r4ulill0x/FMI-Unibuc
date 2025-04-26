#include <iostream.h>
class vector
{
     int n,*sir;
       public:
           vector(const int n0){ 
            cout<<"Constructor: vector"<<endl;
            n=n0;
	        sir=new int [n]; 
		    for (int i=0; i<n; i++) sir[i]=0;
           }
           vector(const vector &v){ 
            cout<<"Constructor de copiere: vector"<<endl;
            n=v.n;
	        sir=new int [n]; 
		    for (int i=0; i<n; i++) sir[i]=v.sir[i];
           }
			void arata() {
              char d[2]={',','\n'};
			  cout<<"n="<<n<<"\n"; cout<<"sir=";
			  if (sir)
			    for (int i=0; i<n; i++) cout<<sir[i]<<d[i==n-1];
			  else cout<<"vid";
			}
			void pune(int m, int* s) {
                cout<<"Pune"<<endl;
                n=m;
			    for (int i=0; i<n; i++) sir[i]=s[i];
			}
           ~vector(){ cout<<"Destructor : vector"<<endl;
             delete sir; 
           }
};
vector & intoarce(vector v) { 
        cout<<"Intoarce"<<endl;
        return v; // argumentul este copiat in variabila temporara care 
                  // contine valoarea intoarsa
                  // se apeleaza constructorul de copiere
			} 
int main()
{
        int s[4]={1,1,1,1};
        vector v(3); // se utilizeaza constructorul definit
		v.arata();
        v.pune(4,s); v.arata(); 
		(intoarce(v)).arata(); // dupa executarea instructiunii simple 
                               // cu apelul functiei 
                               // si utilizarea variabilei temporare 
                               // cu valoarea intoarsa aceasta este distrusa
		                       // se apeleaza destructorul
		v.arata();
} // variabila locala din main() este distrusa
  // se apeleaza destructorul
			  
