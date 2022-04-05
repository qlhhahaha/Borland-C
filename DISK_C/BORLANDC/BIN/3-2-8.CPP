#include<stdio.h>
#include<conio.h>
#define N 99999

void main()
{
	int i,m,b[5];
	long int temp,a;

	printf("please input a :\n");
	scanf("%ld",&a);
	if(a<1||a>N)
	{
		printf("Error in input data\n");
	}
	else
	{
		temp=a;
		for(i=0;temp!=0;i++)
		{
			temp=temp/10;
		}
		m=i;
		printf("the number a=%ld have %d single numbers\n",a,m);

		temp=a;
		printf("the orignal numbers are:\n");
		for(i=0;i<m;i++)
		{
			b[i]=temp%10;
			temp=temp/10;
		}
		for(i=m-1;i>=0;i--)
		{
			printf("%d",b[i]);
		}
		printf("\n");
		printf("every letter is :");
		for(i=m-1;i>=0;i--)
		{
			printf("%d\t",b[i]);
		}
		printf("\n");
		printf("the inverted numbers are:\n");
		for(i=0;i<m;i++)
		{
			printf("%d\t",b[i]);
		}
	}
	getch();
}