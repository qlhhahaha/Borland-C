#include<stdio.h>
#include<conio.h>

void main()
{
	int Y,x;

	printf("please input x:\n");
	scanf("%d",&x);

	if(x<1)
	{
		Y=x;
	}
	else if(x>=1&&x<10)
	{
		Y=x*2-1;
	}
	else
	{
		Y=3*x-11;
	}
	printf("Y=%d\n",Y);
	getch();
}