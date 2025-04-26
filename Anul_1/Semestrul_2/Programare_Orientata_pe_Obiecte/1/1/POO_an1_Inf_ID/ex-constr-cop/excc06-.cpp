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
           ~vector(){ 
             cout<<"Destructor : vector"<<endl;
             delete sir; 
           }
};
vector &intoarce(vector &v) { // valoarea intoarsa este referinta
        vector vl=v; // constructor de copiere
        cout<<"Intoarce"<<endl;
        cout<<"variabila locala intoarsa"<<endl;
        vl.arata();
        return vl; // incorect: valoarea intoarsa este referinta a unei variabile locale
			} // se distruge obiectul local si referinta (se apeleaza destructorul)
			  // ceea nu s-ar produce daca variabila locala ar fi de un tip simplu
			  // de exemplu int
int main()
{
        int s[4]={1,1,1,1};
        vector v(3); // se utilizeaza constructorul definit
		v.arata();
        v.pune(4,s); v.arata(); 
		intoarce(v).arata(); // nu functioneaza: obiectul apelant a fost distrus
}// variabila locala din main() este distrusa
  // se apeleaza destructorul
			  
