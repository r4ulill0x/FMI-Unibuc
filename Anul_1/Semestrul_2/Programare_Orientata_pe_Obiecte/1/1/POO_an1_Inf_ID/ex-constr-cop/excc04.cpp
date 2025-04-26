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
			void copiere(vector &v) {
                cout<<"Copiere"<<endl;
                delete sir;
                n=v.n;
			    for (int i=0; i<n; i++) sir[i]=v.sir[i];
			}
           ~vector(){ cout<<"Destructor : vector"<<endl;
             delete sir; 
           }
};
int main()
{
        int s[4]={1,1,1,1};
        vector v1(3); // se utilizeaza constructorul definit
		vector v2=v1; // se utilizeaza constructorul de copiere definit
					  // se aloca memorie pentru v2.sir
		v1.arata(); v2.arata();
        v1.pune(4,s); v1.arata(); 
        v2.copiere(v1); // transmiterea argumentului prin referinta
                        // nu se folosesc constructorul de copiere si destructorul
		v2.arata(); 
}// variabilele locale din main() sunt distruse
 // se apeleaza destructorul
			  
