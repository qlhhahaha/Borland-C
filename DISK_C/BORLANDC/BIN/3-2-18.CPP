#include<stdio.h>
#include<conio.h>
#include<math.h>

void main()
{
	double x,y,sum;
	int i=1;
	printf("please input x:\n");
	scanf("%lf",&x);
	sum=1.0;
	y=x;

	do
	{
		sum+=y;
		y=(y*x)/(i+1);
	}while(y>1e-6);
	printf("\nthe natural constant  e:%lf",sum);

	getch();
}
