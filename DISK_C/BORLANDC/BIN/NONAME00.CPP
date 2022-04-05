#include<graphics.h>
#include<conio.h>
#include<dos.h>
main()
{
int graphdriver=VGA;
int graphmode=VGAMED;
int i,height,width;
unsigned char *temp="welcome";
initgraph(&graphdriver,&graphmode,"C:\\BORLANDC\\BGI");
settextjustify(LEFT_TEXT,TOP_TEXT);
cleardevice();
for(i=1;i<11;i++)
{
  setvisualpage(0);
  setactivepage(1);
  cleardevice();
  setcolor(12);
  setbkcolor(BLUE);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,i);
  width=textwidth(temp);
  height=textheight(temp);
  outtextxy((639-width)/2,175-height/2,temp);
  setvisualpage(1);
  setactivepage(0);
  cleardevice();
  setcolor(10);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,i++);
  width=textwidth(temp);
  height=textheight(temp);
  outtextxy((639-width)/2,175-height/2,temp);
  delay(1000);
  }
  getch();
  closegraph();
}
