#include<stdio.h>
#include<conio.h>

void main()
{
	int i;

	printf("please input a number:\n");
	scanf("%d",&i);
	if(i%2==1)
	{
		printf("odd\n");
	}
	else
	{
		printf("even");
	}
	getch();
}