#include<stdio.h>
#include<graphics.h>
#include<conio.h>
int main()
{
	int gdriver,gmode;
	gdriver=VGA;
	gmode=VGAHI;
	initgraph(&gdriver,&gmode,"C:\\BORLANDC\\BGI");
	line(100,100,200,200);
	getch();
	closegraph();
	return 0;
}