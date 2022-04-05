#include<stdio.h>
#include<conio.h>

void main()
{
	int a,i=0;

	printf("please input the number:\n");
	scanf("%d",&a);

	while(a%2==0)
	{
		i++;
		a/=2;
	}
	printf("the number is:%d",i);
	getch();
}