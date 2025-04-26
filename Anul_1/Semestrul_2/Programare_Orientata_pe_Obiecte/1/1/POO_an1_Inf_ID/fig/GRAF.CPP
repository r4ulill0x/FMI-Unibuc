#ifndef __AFF
#define __AFF
//definitii functii pentru clasa fig
	fig:: ~fig(){}
	void fig::transl(int dx,int dy)
	{
	   char v=viz;
	   if(v) ascunde();
	   ax+=dx;ay+=dy;
	   if(v) arata();  }

//=========================================================

//definitii functii pentru clasa figatr


	figatr::figatr(int iax,int iay,int c,int ls,int lg,int hm,
		       int hc):fig(iax,iay)
	{
	   if(c<0) cul=getcolor();
	   else cul=c;
	   if(ls<0) getlinesettings((struct linesettingstype *)  &lin);
	   else {lin.s=ls;lin.g=lg;}
	   if(hm<0) getfillsettings((struct fillsettingstype *)  &has);
	   else {has.m=hm;has.c=hc;}
	}
	void figatr::set_cul(int c)
	{
	   char v=viz;
	   cul=c;
	   if(v)arata();
	}
	void figatr::set_lin(const lin_tip  &l)
	{
	   char v=viz;
	   if(v)ascunde();
	   lin=l;
	   if(v)arata();
	}
	void figatr::set_has(const has_tip  &h)
	{
	 char v=viz;
	 if(v)ascunde();
	 has=h;
	 if(v)arata();
	}

//=============================================================

//definitii functii pentru clasa linie
linie::linie (int ix1,int iy1,int ix2,int iy2,
      int iax,int iay,int c,int ls,int lg,int hm,
      int hc):
figatr (iax,iay,c,ls,lg,hm,hc)
  { x1=ix1;y1=iy1;x2=ix2;y2=iy2;
   ftip=Linie;}  // ftip din clasa fig; valoarea Linie trebuie
		// definita in prealabil (de ex. cu #define sau
		// cu enum)
void linie::arata()
{
viz=1;
setviewport(ax,ay,getmaxx(),getmaxy(),0);
if (lin.s<5)           //linie standard; lin din clasa figatr
{     setcolor (cul);
      setlinestyle(lin.s,lin.us,lin.g);
      line(x1,y1,x2,y2);
}
//linie nestandard, orizontala sau verticala
else
{     setfillstyle(has.m,has.c);
      if (y1==y2)        //linie orizontala
	    bar (x1,y1-lin.g/2,
		  x2,y2+lin.g-lin.g/2);
      if (x1==x2)        //linie verticala
	     bar(x1-lin.g/2,y1,
	     x2+lin.g-lin.g/2,y2);
}
}
void linie ::ascunde()
{
	viz=0;
	setviewport(ax,ay,getmaxx(),getmaxy(),0);
	if(lin.s<5)       //linie standard
	{setcolor(0);
	setlinestyle(lin.s,lin.us,lin.g);
	line (x1,y1,x2,y2);
	}
	//linie nestandard, orizontala sau verticala
	else
	{  setfillstyle(0,0);
	   if (y1==y2)    //linie orizontala
	   bar(x1,y1-lin.g/2,x2,y2+lin.g-lin.g/2);
	   if(y1==y2)    //linie verticala
	   bar(x1-lin.g/2,y1,x2+lin.g-lin.g/2,y2);
	}
}

//================================================================

//definitii functii pentru clasa bara
    bara::bara(int x1,int y1,int x2,int y2,
    int iax,int iay,
    int c, int ls, int lg, int hm,int hc):
    figatr(iax,iay,c,ls,lg,hm,hc)
    {st=x1;sus=y1;dr=x2;jos=y2;ftip=Bara;}
    void bara::arata()
    {viz=1;
    setcolor(cul);
    setlinestyle(lin.s,lin.us,lin.g);
    setfillstyle(has.m,has.c);
    setviewport(ax,ay,getmaxx(),getmaxy(),0);
    bar3d(st,sus,dr,jos,0,0);
    }
    void bara::ascunde()
    {
    viz=0;setcolor(0);
    setlinestyle(lin.s,lin.us,lin.g);
    setfillstyle(0,0);
    setviewport(ax,ay,getmaxx(),getmaxy(),0);
    bar3d(st,sus,dr,jos,0,0);
    }
    void bara::set_dim(int dx,int dy)
    {
    char v=viz;
    if(v)ascunde();
    dr=st+dx; jos=sus+dy;
    if (v) arata();
    }

//================================================================

//definitii functii pentru clasa disc
    disc::disc(int ixc,int iyc,int irx,int iry,int iax,int iay,int c,int ls,
    int lg,int hm,int hc):
    figatr(iax,iay,c,ls,lg,hm,hc)
    {
    xc=ixc;
    yc=iyc;
    rx=irx;
    if (iry) ry=iry;
    else iry=irx;
    ftip=Disc;
    }
    void disc::arata()
    {
    viz=1;
    setcolor(cul);
    setlinestyle(lin.s,lin.us,lin.g);
    setfillstyle(has.m,has.c);
    setviewport(ax,ay,getmaxx(),getmaxy(),0);
    fillellipse(xc,yc,rx,ry);
    }
    void disc::ascunde()
    {
    viz=0;
    setcolor(0);
    setlinestyle(lin.s,lin.us,lin.g);
    setfillstyle(0,0);
    setviewport(ax,ay,getmaxx(),getmaxy(),0);
    fillellipse(xc,yc,rx,ry);
    }
    void disc::set_dim(int dx,int dy)
    {
	char v=viz;
	if(v) ascunde ();
	rx=dx;
	if (ry) ry=dy;
	else ry=dx;
	if (v) arata();
    }

//==============================================================

//definitii functii pentru clasa text
text::text(char *s,int ix,int iy,int iax,int iay,
      int c,int f,int dr, int dm, int ao, int av):
      fig(iax,iay)
{ ftip=Text;
x=ix;y=iy;
txt=new char[strlen(s)+1];//text +'\0'
strcpy(txt,s);
if(c<0) cul=getcolor();
else cul=c;
atr.font=f;
atr.dir=dr;atr.dim=dm;
atr.oriz=ao;atr.vert=av;
}
text::~text(){delete txt;}
void text::set_cul(int c)
{
char v=viz;
if(v) ascunde();
setcolor (c);
if(v) arata();
}
void text::set_txt(const txt_tip&t)
{
char v=viz;
if(v)ascunde();
atr=t;
if(v)arata();
}
void text::arata()
{
viz=1;
setcolor(cul);
settextstyle(atr.font,atr.dir,atr.dim);
settextjustify(0,0);
outtextxy(x,y,txt);
}
void text::ascunde()
{
viz=0;
setcolor(0);
settextstyle(atr.font,atr.dir,atr.dim);
settextjustify(atr.oriz,atr.vert);
setviewport(ax,ay,getmaxx(),getmaxy(),0);
outtextxy(x,y,txt);
}

//=================================================
//definitii functii pentru clasa imldi
void imldi::arata()
{
viz=1;
for(crt=cap.urm;crt!=&cap;
     crt=crt->urm)
     ((fig*)crt->data)->arata();
}
void imldi::ascunde()
{
viz=0;
for (crt=cap.urm;crt!=&cap;
     crt=crt->urm)
     ((fig*)crt->data)->ascunde();
}
void imldi::transl(int dx, int dy)
{
   char v=viz;
   if(v) ascunde ();
   for (crt=cap.urm;crt!=&cap;
     crt=crt->urm)
     ((fig*)crt->data)->fig::transl(dx, dy);
  if (v) arata();
}
//=============================================================
#endif