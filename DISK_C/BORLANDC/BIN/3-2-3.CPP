#include<stdio.h>
#include<conio.h>

void main()
{
	int i=1,m=0;
	while(i<101)
	{
		m+=i;
		i++;
	}
	printf("the sum is:%d",m);
	getch();
}