#include<stdio.h>
#include<conio.h>

void main()
{
	int a,b,max=0;
	printf("please input 2 numbers:\n");
	scanf("%d%d",&a,&b);
	max=a>b?a:b;
	printf("the bigger is:%d",max);
	getch();
}
