#ifndef __ACL
#define __ACL
struct lnod {
//pointer catre componenta listei
void *data;
//adresele nodurilor adiacente
lnod *urm, *prec;
lnod(void *d=0) //constructor
{ data=d; urm=prec=0; }
};
//lista dublu inlantuita,circulara,cu nod capat
class ldi {
protected:
  lnod cap,*crt;
public:
ldi();   //constructor
~ldi(); //destructor
//test lista vida
int nl_vida() {return &cap!=cap.urm;}
//initializeaza indicator curent pe nodul
//capat
void capat() {crt=&cap;}
//initializeaza indicator curent in fata
void prim() {crt=cap.urm;}
//initializeaza indicator curent la sfarsit
void ultim() {crt=cap.prec;}
//avanseaza indicator curent si
//intoarce element
void* spre_dr();
void* spre_st();
//citeste elementul curent
void *citesc();
//adauga la dreapta nodului curent
void *adaug_dr(void*d);
//adauga la stanga nodului curent
void *adaug_st(void*d);
//extrage nodul curent
void *extrag();
};
//--------------------------------------------------------------
#endif