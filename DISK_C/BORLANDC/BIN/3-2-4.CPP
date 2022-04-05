#include<stdio.h>
#include<conio.h>

void main()
{
	int a,b,temp,i;

	printf("%6d%6d",a=10,b=-3);
	for(i=3;i<=10;i++)
	{
		temp=3*b+a;
		a=b;
		b=temp;
		printf("%6d",temp);

	}
	getch();
}