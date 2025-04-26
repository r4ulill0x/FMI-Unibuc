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
			
			void pune(int m, int* s) {
                cout<<"Pune"<<endl;
                n=m;
			    for (int i=0; i<n; i++) sir[i]=s[i];
			}
			void copiere(vector &v) {
                cout<<"Copiere"<<endl;
                delete sir;
                n=v.n;
			    for (int i=0; i<n; i++) sir[i]=v.sir[i];
			}
			friend void arata(vector &v); 
           ~vector(){ cout<<"Destructor : vector"<<endl;
             delete sir; 
           }
};
void arata(vector &v) {
              char d[2]={',','\n'};
			  cout<<"n="<<v.n<<"\n"; cout<<"sir=";
			  if (v.sir)
			    for (int i=0; i<v.n; i++) cout<<v.sir[i]<<d[i==v.n-1];
			  else cout<<"vid"<<endl;
}
vector &intoarce(vector &v) { // valoarea intoarsa este referinta
        vector vl=v; // constructor de copiere
        cout<<"Intoarce"<<endl;
        cout<<"variabila locala intoarsa"<<endl;
        arata(vl);
        return vl; // incorect: valoarea intoarsa este referinta a unui obiect local
			} // se distruge obiectul local si referinta (se apeleaza destructorul)
			  // ceea nu s-ar produce daca variabila locala ar fi de un tip simplu
			  // de exemplu int
int main()
{
        int s[4]={1,1,1,1};
        vector v(3); // se utilizeaza constructorul definit
		arata(v);
        v.pune(4,s); arata(v); 
		arata(intoarce(v)); // nu functioneaza: argumentul a fost distrus
}// variabila locala din main() este distrusa
  // se apeleaza destructorul
			  
