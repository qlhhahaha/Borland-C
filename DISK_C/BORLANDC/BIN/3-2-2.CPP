#include<stdio.h>
#include<conio.h>

void main()
{
	int a,b,c,max=0;
	printf("please input 3 numbers:\n");
	scanf("%d%d%d",&a,&b,&c);

	if(a>b)
	{
		if(a>c)
		{
			max=a;
		}
		else
		{
			max=c;
		}
	}
	else
	{
		if(b>c)
		{
			max=b;
		}
		else
		{
			max=c;
		}
	}
	printf("the bigget is:%d",max);
	getch();
}