#include<stdio.h>
#include<conio.h>

void main()
{
	long int m,n,i;

	printf("please input 2 numbers:\n");
	scanf("%ld%ld",&m,&n);

	for(i=(m>n?n:m);i>0;i--)
	{
		if((m%i==0)&&(n%i==0))
		{
			printf("the common small is:%ld\n",i);
			break;
		}

	}
	m=m*n/i;
	printf("the common big number is %ld\n",m);
	getch();
}



