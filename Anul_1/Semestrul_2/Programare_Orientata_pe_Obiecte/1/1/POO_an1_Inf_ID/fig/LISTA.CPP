#ifndef __AFL
#define __AFL
// Definitii functii pentru clasa ldi
//constructor
ldi::ldi()
{ crt=cap.urm=cap.prec=&cap; }
void *ldi::citesc() //citire element curent
{  if(crt!=&cap) return crt->data;
   else return 0; }
//adaugare la stanga
void *ldi::adaug_st(void *d)
{
lnod *p;
p=new lnod(d);
if(p) {
p-> urm=crt;p->prec=crt->prec;
crt->prec=crt->prec->urm=p;
crt=p;
return p;
}
return 0;
}
//adaugare la dreapta
void *ldi::adaug_dr(void *d)
{
lnod *p;
p=new lnod(d);
if(p) {
p->prec=crt; p->urm=crt->urm;
crt->urm=crt->urm->prec=p;
crt=p; return p;
}
return 0;
}
//extragerea elementului curent
void *ldi::extrag()
{
lnod *p;
void *d;
if(crt!=&cap) {
p=crt;
crt->urm->prec=crt->prec;
crt->prec->urm=crt->urm;
crt=crt->urm;
d=p->data;
delete p;
return d;
}
return 0;
}
//---------------------------
//parcurgere in sens direct
void *ldi::spre_dr()
{
    if(nl_vida() && crt->urm!=&cap){
	crt=crt->urm;
	return crt->data;
     }
return 0;
}
//parcurgere in sens invers
void *ldi::spre_st()
{
    if(nl_vida() && crt->prec!=&cap){
	crt=crt->prec;
	return crt->data;
     }
return 0;
}
//-------------------------------
//destructor => eliberarea memoriei alocate dinamic elementelor listei
ldi::~ldi()
{
    lnod *p;
    p=cap.urm;
    while (p!=&cap){
       crt=p;p=p->urm;
       delete crt;
   }
}
//---------------------------------
#endif