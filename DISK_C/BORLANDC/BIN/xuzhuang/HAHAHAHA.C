#include<stdio.h>
#define N 1
void input(float (*marks)[5],int *id,int n);
void average(float (*marks)[5],int *data,int n);
void order(float (*marks)[5],int *data,int *id,int n);

void input(float (*marks)[5],int *id,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		printf("please input the number:\n");
		scanf("%d",&id[i]);
		for(j=0;j<5;j++)
		{
			printf("please input the marks:\n");
			scanf("%d",&marks[i][j]);
		}
	}
}

void average(float (*marks)[5],int *data,int n)
{
	int i,j;
	float s=0.0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<5;j++)
		{
			s=s+marks[i][j];
		}
		data[i]=s/5;
	}

}

void order(float (*marks)[5],int *data,int *id,int n)
{
	int i,j,k,t,m;
	float a;
	for(i=0;i<n-i;i++)
	{
		k=i;
		for(j=0;j<n;j++)
		{
			if(data[j]>data[i])
				k=j;
		}
		if(k!=i)
		{
			t=data[i];
			data[i]=data[j];
			data[j]=t;
			t=id[i];
			id[i]=id[j];
			id[j]=t;
			for(m=0;m<5;m++)
			{
				a=marks[i][m];
				marks[i][m]=marks[j][m];
				marks[j][m]=a;
			}
		}

	}
}

void main()
{
	int m=0,n,i,j,id[N]={0},data[N]={0};
	float marks[N][5];
	input(marks,id,N);
	order(marks,data,id,N);
	for(i=0;i<N;i++)
	{
		for(j=0;j<5;j++)
		{
			if(marks[i][j]<60)
				m++;
		}
		if(m>=2)
		printf("%d\t%d",id[i],data[i]);
		for(n=0;n<5;n++)
			printf("%d ",marks[i][n]);
			printf("\n");
	}
}