#include<stdio.h>
#include<conio.h>

void  main()
{
	int i,a,b,c;
	printf("the number is  :");


	for(i=0;i<1000;i++)
	{
		if(i%3)
		{
			a=i/100;
			b=(i-a*100)/10;
			c=i-a*100-b*10;
			if(a==5||b==5||c==5)
			{
				printf("%d\n",i);
			}
		}
	}
	getch();
}