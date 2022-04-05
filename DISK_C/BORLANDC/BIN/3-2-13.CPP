#include<stdio.h>
#include<conio.h>

void main()
{
	long int i=1,a=1;

	for(i=1;i<=10;i++)
	{
		a*=i;
		printf("%ld\n",a);
	}
	getch();
}
