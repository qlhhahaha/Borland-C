#include<stdio.h>
#include<conio.h>

void main()
{
	int a,b,c;
	void swap(int* x,int* y);

	printf("please input 3 numbers:\n");
	scanf("%d%d%d",&a,&b,&c);
	if(a>b)
	{
		swap(&a,&b);
	}
	if(b>c)
	{
		swap(&b,&c);
	}
	if(a>b)
	{
		swap(&a,&b);
	}
	printf("%d\t%d\t%d\n",a,b,c);
	getch();
}

void swap(int* x,int* y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

