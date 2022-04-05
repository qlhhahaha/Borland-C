#include<stdio.h>
#include<conio.h>

void main()
{
	int a,n;
	long tmp,sum=0;
	while(!(a>=0&&a<=9))
	{
		printf("please  input a:\n");
		scanf("%d\n",&a);
	}
	printf("please input n:\n");
	scanf("%d\n",&n);

	tmp=a;
	while(n--)
	{
		sum+=tmp;
		tmp=tmp*10+a;
	}
	printf("\na+aa+aaa+...=%ld(a=%d)",sum,a);
	getch();
}