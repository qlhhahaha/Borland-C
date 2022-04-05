#include<stdio.h>
void _math(int a);
void _math(int a)
{
	int i,n=1;
	for(i=2;i<a;i++)
	{
		if(a%i==0)
		{
			n=0;
			break;
		}
	}
	if(n==0)
		printf("%d is not a sushu\n",a);
	else
		printf("%d is a suahu\n",a);
}
void main()
{
	int a;
	printf("please input the number:\t");
	printf("\n");
	scanf("%d",&a);
	_math(a);
}