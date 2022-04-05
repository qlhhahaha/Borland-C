#include<stdio.h>
void reverse(int (*p)[3]);
int search(int (*p)[3],int *px,int *ppx);
void output(int (*p)[3],int max,int x,int y);
void main()
{
	int i,j,x,y,max,a[3][3];
	printf("please input a[][]:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	reverse(a);
	max=search(a,&x,&y);
	output(a,max,x,y);
}
void reverse(int (*p)[3])
{
	int i,j,m;
	for(i=0;i<2;i++)
	{
		for(j=i+1;j<3;j++)
		{
			m=p[i][j];
			p[i][j]=p[j][i];
			p[j][i]=m;
		}

	}
}
int search(int (*p)[3],int *px,int *ppx)
{
	int i,j,n;
	n=p[0][0];
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(p[i][j]>n)
			{
				n=p[i][j];
				*px=i;
				*ppx=j;
			}
		}
	}
	return n;
}
void output(int (*p)[3],int max,int x,int y)
{
	int j;
	for(j=0;j<3;j++)
	{
		printf("%d ",p[0][j]);
		printf("%d ",p[1][j]);
		printf("%d ",p[2][j]);
	}
	printf("the largest number is %d\n",max);
	printf("the location is x: %d,y:  %d\n",x+1,y+1);

}