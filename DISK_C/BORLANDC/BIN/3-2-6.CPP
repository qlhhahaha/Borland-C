#include<stdio.h>
#include<conio.h>

void main()
{
	int n,a[11],b[11],sum;

	a[1]=8;
	b[1]=1;
	sum=a[1];
	for(n=2;n<11;n++)
	{
		b[n]=b[n-1]+3;
		a[n]=a[n-1]+b[n];
		sum+=a[n];
	}
	printf("sum of a[n] is:%d\n",sum);
	getch();
}

