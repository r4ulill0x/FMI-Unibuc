#include<graphics.h>
#include <conio.h>
#include <dos.h>
#include <string.h>
#include "\doc-poo\poo-mail\fig\lista.h"
#include "\doc-poo\poo-mail\fig\lista.cpp"
#include "\doc-poo\poo-mail\fig\graf.h"
#include "\doc-poo\poo-mail\fig\graf.cpp"
void main()
{
int gdrv=VGA, gmod=VGAHI;
initgraph(&gdrv, &gmod, "\\borlandc\\bgi"); // se pune calea conform cu instalarea Borland C++

int mx=getmaxx(), my=getmaxy();
int dx=(mx+1)/2-mx/5;
int dy=(my+1)/2-mx/5;
//atribute implicite
setcolor(RED);
setlinestyle(SOLID_LINE,0,THICK_WIDTH);
setfillstyle(EMPTY_FILL,0);
//bara cu atribute implicite
bara b1(0,0,mx,my);
//bara cu atribute specificate,
//obiect dinamic
bara *b2=new bara (0,0,dx,dy,mx/10,my/10,GREEN,SOLID_LINE,
		   THICK_WIDTH,HATCH_FILL,MAGENTA);
//alte atribute implicite
setcolor(BLUE);
setfillstyle(INTERLEAVE_FILL,MAGENTA);
//cerc cu atribute implicite, obiect dinamic
disc *d1=new disc(0,0,dy/2,dy/2,3*mx/4,my/4);
//elipsa, obiect dinamic
disc *d2=new disc(0,0,dx/2,dy/2,mx/4,3*my/4,CYAN,
		  SOLID_LINE,THICK_WIDTH,XHATCH_FILL,MAGENTA);
//linie cu atribute implicite
linie *l1=new linie (mx/10,my/10,dx,my/10,mx/2,my/2);
//linie cu atribute specificate
linie *l2=new linie(mx/10,my/10,dx,2*my/10,mx/2,my/2,RED,DASHED_LINE,NORM_WIDTH);
//linie desenata ca bara cu 4 pixeli latime
linie *l3=new linie(mx/10,my/10,dx,2*my/10,mx/2,my/2,RED,5,4);
text *txt=new text ("Doar un test", mx/2,my-20,0,0,YELLOW,TRIPLEX_FONT,HORIZ_DIR,3);
//ansamblu
imldi img;
img.adaug_dr(b2);
img.adaug_dr(d1);img.adaug_dr(d2);
img.adaug_dr(l1);img.adaug_dr(l2);
img.adaug_dr(l3);img.adaug_dr(txt);
//afisare
b1.arata();getch();
img.arata();getch();
cleardevice();
while(!kbhit()){
img.ascunde();delay(300);
img.arata();delay(300);
}
getch();getch();
img.prim();
fig *fp;
while((fp=(fig*)img.extrag())){
fp->ascunde();
delete fp;
getch();
}
closegraph();
}


