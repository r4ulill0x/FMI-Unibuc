#include <iostream.h>
#include "\doc-poo\poo-mail\fig\lista.h"
#include "\doc-poo\poo-mail\fig\lista.cpp"
#include <conio.h>
void main()
{
ldi list;
int *ip,i;
//inscrie la inceput valorile: 0..9
for(i=0;i<10;i++)
list.adaug_dr(new int(i));
//inscrie la sfarsit valorile: 19..10
list.capat();
for(i=9;i>=0;i--)
list.adaug_st(new int(i+10));
//citeste primul element
list.prim();
cout<<*(int*)list.citesc()<<endl;
//parcurge in sens direct (stanga->dreapta ) si afiseaza
list.capat();
while (ip=(int*)list.spre_dr())
cout<<*ip<<' '; cout<<endl;
//parcurge in sens invers (dreapta->stanga ) si afiseaza
list.capat();
while (ip=(int*)list.spre_st())
cout<<*ip<<' '; cout<<endl;
//extrage si elimina componentele
list.prim();
while (ip=(int*)list.extrag())
{
cout<<*ip<<' ';delete ip;
cout<<endl;
//test lista vida
if(!list.nl_vida()) cout<<"Lista vida!"<<endl;
} getch();
}