#include<stdio.h>
#include<conio.h>

void main()
{
	int i,a1=10,a2=-3;
	for(i=1;i<=5;i++)
	{
		printf("%6d%6d",a1,a2);
		a1=3*a2+a1;
		a2=3*a1+a2;
	}
	printf("\n");
	getch();
}