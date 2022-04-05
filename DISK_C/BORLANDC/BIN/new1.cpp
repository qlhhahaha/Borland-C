#include<conio.h>
#include<stdlib.h>
#include "stdio.h"
#include "graphics.h"
#include "math.h"
donghua()
{int graphdriver=VGA;
int graphmode=VGAHI;
int i,j;
initgraph(&graphdriver,&graphmode,"");
cleardevice();
/************wan nian li*************************/
for(i=0;i<=150;i+=5)
{setcolor(i);
textbackground(RED);
settextstyle(0,0,5);
outtextxy(100,i+140,"Wan Nian Li");
delay(10000000);
cleardevice();
}
setcolor(RED);
outtextxy(50,200,"Loading");
delay(100000000000);
outtextxy(50,200,"Loading.");
delay(100000000000);
outtextxy(50,200,"Loading..");
delay(100000000000);
outtextxy(50,200,"Loading...");
delay(100000000000);
outtextxy(50,200,"Loading....");
delay(100000000000);
outtextxy(50,200,"Loading.....");
delay(100000000000);
outtextxy(50,200,"Loading......");
delay(100000000000);
outtextxy(50,200,"Loading.......");
delay(100000000000);
outtextxy(50,200,"Loading........");
delay(100000000000);
outtextxy(50,200,"Loading.........");
delay(100000000000);
outtextxy(50,200,"Loading..........");
delay(100000000000);
outtextxy(50,200,"Loading...........");
outtextxy(50,200,"Loading............");
delay(100000000000);
for(i=0;i<=10;i++)
delay(100000000000);
cleardevice();
/*********************printf color*************************/
for(i=0;i<=15;i++) /*15 color of kind*/
{
setbkcolor(i+1);
setcolor(i);
setfillstyle(1,i+1);
for(j=0;j<=600;j++)
{delay(1000);
circle(320,240,j);
floodfill(320,240,i);
}
}
}
/*************menu**********************/
void menu()
{int i,j;
cleardevice();
setbkcolor(GREEN);
for(i=0;i<=100;i++)
{delay(1000);
for(j=0;j<=10;j++)
{setfillstyle(1,LIGHTGREEN);
setcolor(BROWN);
circle(320,240,i);
floodfill(320,240,BROWN);}
}
for(i=0;i<=70;i++)
{delay(1000);
for(j=0;j<=20;j++)
{setfillstyle(1,RED);
setcolor(RED);
circle(220,100,i);
floodfill(220,100,RED);}
}
setcolor(YELLOW);
settextstyle(3,0,5);
outtextxy(190,75,"Run");
for(i=0;i<=70;i++)
{delay(1000);
for(j=0;j<=20;j++)
{setfillstyle(1,BLUE);
setcolor(BLUE);
circle(420,100,i);
floodfill(420,100,BLUE);}
}
setcolor(RED);
settextstyle(3,0,5);
outtextxy(375,75,"Game"); 
for(i=0;i<=70;i++)
{delay(1000);
for(j=0;j<=20;j++)
{setfillstyle(1,LIGHTBLUE);
setcolor(LIGHTBLUE);
circle(220,380,i);
floodfill(220,380,LIGHTBLUE);}
}
setcolor(RED);
settextstyle(3,0,5);
outtextxy(165,360,"Me");

for(i=0;i<=70;i++)
{delay(1000);
for(j=0;j<=20;j++)
{setfillstyle(1,LIGHTRED);
setcolor(LIGHTRED);
circle(420,380,i);
floodfill(420,380,LIGHTRED);}
}
setcolor(YELLOW);
settextstyle(3,0,5);
outtextxy(390,360,"Exit");
setcolor(BLUE);
settextstyle(3,0,6);
delay(1500000);
outtextxy(280,210,"Help");
/***********draw line*******************/
for(i=130;i<=500;i++)
{for(j=0;j<=100;j++)
delay(10);
setcolor(BLUE);
line(130,20,i,20);
delay(10);
line(128,18,i+2,18);
}
for(i=20;i<=460;i++)
{for(j=0;j<=100;j++)
delay(10);
setcolor(BLUE);
line(500,20,500,i);
delay(10);
line(502,18,502,i+2);
}
for(i=500;i>=130;i--)
{for(j=100;j>=0;j--)
delay(10);
setcolor(BLUE);
line(500,460,i,460);
delay(10);
line(502,462,i-2,462);
}
for(i=460;i>=20;i--)
{for(j=100;j>=0;j--)
delay(10);
setcolor(BLUE);
line(130,460,130,i);
delay(10);
line(128,462,128,i-2);
}
/*************wan nian li*****************************/
setcolor(RED);
settextstyle(0,0,4);
for(j=15;j>=0;j-=2)
{delay(1000000);
outtextxy(j+10,j+50,"Wan");
}
for(j=15;j>=0;j-=2)
{delay(1000000);
outtextxy(j,j+200,"Nian");
}
for(j=15;j>=0;j-=2)
{delay(1000000);
outtextxy(j+10,j+350,"Li");
}
getch();
}
/**************************************/
bofangdonghua()
{int graphdriver=VGA;
int graphmode=VGAHI;
int i,j;
char c;
initgraph(&graphdriver,&graphmode,"");
/*************shi fou bo fang dong hua?**************/
printf:{setcolor(RED);
settextstyle(3,0,5);
outtextxy(100,30,"bo fang dong hua?");
outtextxy(150,80,"Yes");
outtextxy(300,80,"No");
c=getch();
if(c=='Y'||c=='y')
{donghua();
menu();
}
else
if(c=='N'||c=='n')
menu();
else
{setcolor(GREEN);
settextstyle(3,0,8);
outtextxy(200,240,"Error!");
delay(10000000000);
cleardevice();
goto printf;
}
}
/**************************************/

}
main()
{int graphdriver=VGA;
int graphmode=VGAHI;
char c;
initgraph(&graphdriver,&graphmode,"");
bofangdonghua();
c=getch();
while(c!='e'&&c!='E')
{if(c=='r'||c=='R')
run();
else if(c=='G'||c=='g')
game();
else if(c=='m'||c=='M')
about();
else if(c=='H'||c=='h')
help();
else {
settextstyle(3,1,6);
delay(10000000000);
outtextxy(530,240,"ERROR!");
}
c=getch(); }
end();}
game()
{cleardevice();
setbkcolor(BLACK);
setcolor(RED);
settextstyle(3,0,5);
bar3d(10,10,600,500,2,1);
outtextxy(100,210,"Sorry,it's mading!!");
setcolor(WHITE);
settextstyle(3,0,3);
outtextxy(300,450,"press any key to menu!!");
getch();
jingzhimenu();
}
run()
{int graphdriver=VGA;
int graphmode=VGAHI;
int i;
int day;
int year;
int temp;
int temp_i;
long int Year_days = 0;
int Year_Start = 1;
int Per_Year_Days;
int month_day[]={31,28,31,30,31,30,31,31,30,31,30,31,29};
initgraph(&graphdriver,&graphmode,"");
cleardevice();
setbkcolor(BLACK);
printf("Please enter the year: ");
scanf("%d",&year);

while(Year_Start < year)
{
if( IsLeapYear( Year_Start ) )
Per_Year_Days = 366;
else
Per_Year_Days = 365;

Year_days = Year_days + Per_Year_Days;
Year_Start++;
}

for( temp = 1; temp <=12; temp++ )
{
switch( temp )
{
case 1:
printf(" January(%d)\n",year);
break;
case 2:
printf(" February(%d)\n",year);
break;
case 3:
printf(" March(%d)\n",year);
break;
case 4:
printf(" April(%d)\n",year);
break;
case 5:
printf(" May(%d)\n",year);
break;
case 6:
printf(" June(%d)\n",year);
break;
case 7:
printf(" July(%d)\n",year);
break;
case 8:
printf(" August(%d)\n",year);
break;
case 9:
printf(" September(%d)\n",year);
break;
case 10:
printf(" October(%d)\n",year);
break;
case 11:
printf(" November(%d)\n",year);
break;
case 12:
printf(" December(%d)\n",year);
break;
}
i = Year_days % 7;
printf("Sun Mon Tue Wed Thu Fri Sat \n");
if( i != 0 )
for( temp_i = 0; temp_i < i; temp_i++)
printf(" ");
day = 1;
if( IsLeapYear(year) && temp == 2)
while( day <= month_day[12] )
{
if( day >1 )
if( Year_days % 7 == 0 )
printf("\n");
if( day >= 10 )
printf("%d ",day);
else
printf("%d ",day);
Year_days++;
day++;
}

else
while (day <= month_day[temp-1])
{
if( day > 1 )
if( Year_days % 7 == 0 )
printf("\n");
if( day >=10 )
printf("%d ",day);
else
printf("%d ",day);
Year_days++;
day++;
}
printf("\n");
if( getch() == 'q' )
exit(0);
}
getch();
jingzhimenu();
}


int IsLeapYear( int year )
{
if ((year %4 == 0) && (year % 100 != 0) ||
(year % 400 == 0) )
return 1;
else
return 0;

}
help()
{ int gdriver=DETECT,gmode,i,n;
float t,x[6],y[6],a[5],b[5];
initgraph(&gdriver,&gmode,"c:\\tc");
cleardevice();
hua();
setbkcolor(BLUE);
setcolor(YELLOW);
settextstyle(3,0,3);
outtextxy(100,200,"press 'r'or'R'----run");
outtextxy(100,300,"press 'G'or'g'-----game");
outtextxy(100,400,"press 'm'or'M-----about me'");
outtextxy(100,480,"press 'e'or'E'----exit");
setcolor(RED);
outtextxy(100,100,"press any key to menu!!");
getch();
jingzhimenu();
}
hua2(int x,int y)
{int graphdriver=VGA;
int graphmode=VGAHI;
register i;
initgraph(&graphdriver,&graphmode,"");
setcolor(12);
arc(x+65,y-60,150,350,8);
arc(x+66,y-54,300,470,8);
arc(x+65,y-56,30,230,10);
arc(x+64,y-57,300,460,17);
ellipse(x+73,y-30,250,450,27,40);
ellipse(x+59,y-30,100,290,27,40);
ellipse(x+65,y-40,140,270,20,30);
setfillstyle(SOLID_FILL,5);
floodfill(x+65,y-20,12);
arc(x,y,150,350,12);
arc(x+1,y+8,280,470,12);
arc(x,y+2,30,230,16);
arc(x,y+3,80,240,28);
arc(x+2,y+8,180,330,22);
arc(x-2,y+2,310,460,25);
ellipse(x-12,y+30,120,300,30,40);
ellipse(x+10,y+28,250,423,30,42);
ellipse(x-4,y+10,290,393,30,40);
setfillstyle(SOLID_FILL,4);
floodfill(x+5,y+31,12);
ellipse(x+120,y+5,0,360,15,25);
setfillstyle(SOLID_FILL,15);
floodfill(x+120,y,12);
ellipse(x-70,y+10,0,360,14,20);
setfillstyle(SOLID_FILL,14);
floodfill(x-70,y+10,12);
setcolor(10);
ellipse(x-15,y+32,190,310,30,35);
ellipse(x+16,y+32,235,355,26,35);
ellipse(x,y+35,190,350,43,50);
arc(x,y+82,190,350,6);
setfillstyle(SOLID_FILL,2);
floodfill(x,y+75,10);
ellipse(x+50,y-48,190,320,22,50);
ellipse(x+80,y-48,220,350,22,50);
ellipse(x+65,y-28,180,360,36,50);
floodfill(x+65,y+18,10);
for(i=0;i<3;i++)
{
ellipse(x-98,y+100+i,255,371,100,80);
ellipse(x-20,y+30+i,260,358,140,140);
ellipse(x+233,y+20+i,180,218,160,140);
}
ellipse(x+70,y+34,180,233,140,140);
ellipse(x,y+40,205,255,100,120);
ellipse(x+135,y-30,209,249,72,120);
ellipse(x,y+20,263,301,100,120);
ellipse(x+85,y-10,278,305,100,120);
ellipse(x+100,y-62,282,308,90,120);
ellipse(x-50,y-10,277,314,30,120);
ellipse(x+70,y+80,222,266,52,120);
ellipse(x-60,y-45,229,266,52,120);
ellipse(x+79,y-45,229,266,52,120);
ellipse(x+84,y,224,273,52,120);
ellipse(x+110,y+40,240,282,100,120);
ellipse(x+120,y-6,200,340,17,25);
ellipse(x+120,y+7,160,380,17,27);
ellipse(x-70,y+15,140,380,17,20);
}
hua()
{int graphdriver=VGA;
int graphmode=VGAHI;
initgraph(&graphdriver,&graphmode,"");
cleardevice();
hua2(480,90);
setcolor(10);
rectangle(0,0,639,479);
}
about()
{cleardevice();
setbkcolor(BLUE);
setcolor(GREEN);
settextstyle(3,0,3);
outtextxy(10,100,"My English name is Kemble");
outtextxy(10,150,"My homepage http://www.kemble0673.533.net");
outtextxy(10,200,"glad to meet you!!");
outtextxy(300,400,"press any key to menu!");
getch();
jingzhimenu();
}
end()
{int i;
for(i=0;i<=15;i++)
{cleardevice();
setcolor(i);
setcolor(i);
settextstyle(3,0,i-5);
outtextxy(20,200,"Happy evrey day!!");
delay(10000000000);
}

outtextxy(100,200,"Bye.......");
cleardevice();
for(i=0;i<=25;i++)
delay(1000000000000);
outtextxy(100,200,"Bye.......");
closegraph();}

jingzhimenu()
{int graphdriver=VGA;
int graphmode=VGAHI;
initgraph(&graphdriver,&graphmode,"");
cleardevice();
setbkcolor(GREEN);
setfillstyle(1,LIGHTGREEN);
setcolor(BROWN);
circle(320,240,100);
floodfill(320,240,BROWN);
setfillstyle(1,RED);
setcolor(RED);
circle(220,100,70);
floodfill(220,100,RED);
setcolor(YELLOW);
settextstyle(3,0,5);
outtextxy(190,75,"Run");
setfillstyle(1,BLUE);
setcolor(BLUE);
circle(420,100,70);
floodfill(420,100,BLUE);

setcolor(RED);
settextstyle(3,0,5);
outtextxy(375,75,"Game");
setfillstyle(1,LIGHTBLUE);
setcolor(LIGHTBLUE);
circle(220,380,70);
floodfill(220,380,LIGHTBLUE);
setcolor(RED);
settextstyle(3,0,5);
outtextxy(165,360,"Me");
setfillstyle(1,LIGHTRED);
setcolor(LIGHTRED);
circle(420,380,70);
floodfill(420,380,LIGHTRED);
setcolor(YELLOW);
settextstyle(3,0,5);
outtextxy(390,360,"Exit");
setcolor(BLUE);
settextstyle(3,0,6);
outtextxy(280,210,"Help");
line(130,20,500,20);
delay(10);
line(128,18,502,18);
line(500,20,500,460);
delay(10);
line(502,18,502,462);
line(500,460,130,460);
delay(10);
line(502,462,128,462);
line(130,460,130,20);
delay(10);
line(128,462,128,18);
setcolor(RED);
settextstyle(3,0,6);
outtextxy(10,50,"wan");
outtextxy(10,240,"nian");
outtextxy(50,380,"li");
}