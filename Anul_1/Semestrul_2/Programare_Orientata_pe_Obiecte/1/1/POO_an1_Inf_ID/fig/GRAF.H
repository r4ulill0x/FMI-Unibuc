#ifndef __ACF
#define __ACF
enum Tipuri {Linie, Bara, Disc, Text};
// Clasa fig
//----------

	class fig {         //clasa abstracta, orice figura
	protected:
	   int ax,ay;  //coordonate absolute
	   char viz;   //vizibilitate
	   int ftip;   //tip figura; valorile posibile
		       //(Linie, Bara, Disc, etc)  trebuie
		       //definite in prealabil (de ex. cu
		       //#define sau cu un tip enum)
	public:
	   fig(int ix=0,int iy=0) //constructor
	   {ftip=viz=0;ax=ix;ay=iy;}
	   virtual ~fig();  //destructor virtual
	   // fixare coordonate
	   void set_xy(int iax,int iay)
	   {ax=iax;ay=iay;}
	   void transl(int, int); //translatie
	   //afiseaza figura pe ecran
	   virtual void arata()=0;
	   //sterge figura de pe ecran
	   virtual void ascunde()=0;
	};
//=========================================================

// Clasa figatr
//--------------

	struct lin_tip {     //model linie
	    int s;           //stil linie
	    unsigned us;     //stil def. de utiliz.
	    int g;           //grosime
	};
	struct has_tip {     //model hasurare
	    int m;           //model
	    int c;           //culoare
	};
	class figatr:public fig { // clasa abstracta, adauga atributele
				  // de desenare
	protected:
	     int cul;        //culoare
	     lin_tip lin;    //linie
	     has_tip has;    //hasurare
	public:
	   //constructor
	   figatr(int iax=0,int iay=0,int c=-1,int ls=-1,int lg=0,
		  int hm=-1,int hc=0);
	   void set_cul(int c);
	   void set_lin(const lin_tip &l);
	   void set_has(const has_tip &h);
	   int get_cul() {return cul;}
	   const lin_tip &get_lin() {return lin;}
	   const has_tip &get_has() {return has;}
	   virtual void arata()=0;
	   virtual void ascunde()=0;
	};
//=============================================================

// Clase pentru figuri geometrice
//================================

// Linie
//-------

class linie:public figatr{     //linie
protected:
     int x1,y1,x2,y2;
public:
linie (int ix1,int iy1,int ix2,int iy2,
      int iax=0,int iay=0,int c=-1,int ls=-1,
      int lg=0,int hm=-1,int hc=0);
void arata ();
void ascunde();
};
//================================================================

//dreptunghi colorat, cu contur
class bara:public figatr {
protected:
	  int st,sus,dr,jos;   //coordonate relative
public:
       bara (int x1,int y1,int x2, int y2,
       int iax=0,int iay=0,int c=-1,
       int ls=-1,int lg=0,
       int hm=-1,int hc=0);
    void arata();
    void ascunde();
    //modifica dimensiunea
    void set_dim (int dx,int dy);
    };
//=================================================================

//cerc/elipsa colorate
    class disc:public figatr{
    protected:
    int xc,yc,rx,ry;       //centru(relativ) si raze
    public:
    disc(int ixc,int iyc,int irx,int iry=0,
    int iax=0,int iay=0,
    int c=-1,int ls=-1,int lg=0,
    int hm=-1,int hc=0);
    void arata();
    void ascunde();
    //modifica dimensiunea
    void set_dim(int nrx,int nry=0);
    };
//==============================================================

struct txt_tip { //atribute text
   int font;
   int dir;
   int dim;
   int oriz,vert;
};
class text:public fig{
protected:
    char *txt;       //text
    int x,y;         //pozitie relativa
    int cul;         //culoare
    txt_tip atr;     //atribute
public:
     text(char *s,int ix=0,int iy=0,
         int iax=0,int iay=0,int c=-1,
         int f=0,int dr=0,int dm=1,
         int ao=0,int av=0);
     ~text();
     void set_cul(int c);
     void set_txt(const txt_tip &t);
     int get_cul() {return cul;}
     const txt_tip &get_txtatr() {return atr;}
     void arata();
     void ascunde ();
};
//=================================================

class imldi: public fig, public ldi {
public:
void arata();
void ascunde();
void transl(int dx,int dy);
};
//==================================================
#endif