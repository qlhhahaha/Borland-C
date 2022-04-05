#include<stdio.h>
#include<conio.h>

void main()
{
	int a[3],i,j,temp;
	printf("please input 3 numbers:\n");
	for(i=0;i<3;i++)
	{
			scanf("%d",a+i);
	}
	for(i=0;i<2;i++)
	{
		for(j=i+1;j<3;j++)
		{
			if(*(a+i)>*(a+j))
			{
				temp=*(a+j);
				*(a+j)=*(a+i);
				*(a+i)=temp;
			}
		}
	}
	for(i=0;i<3;i++)
	{
		printf("%d\t",*(a+i));
	}
	getch();
}