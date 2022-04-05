#include<stdio.h>
#include<conio.h>

void main()
{
	int a[11],i=3;
	a[1]=10;
	a[2]=-3;
	printf("%6d\n%6d\n",a[1],a[2]);

	for(;i<11;i++)
	{
		a[i]=a[i-1]*3+a[i-2];
		printf("%6d\n",a[i]);
	}
	getch();
}
