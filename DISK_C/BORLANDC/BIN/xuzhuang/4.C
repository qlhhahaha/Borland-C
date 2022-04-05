#include<stdio.h>
#include<string.h>
#define N 10
void my_cos(char *ap[],char *str,int n);
void sort(char *ap[],int n);
void output(char *ap[],char *new_str,int n);
void main()
{
	char my_str[N][20],str[356],new_str[356];
	printf("please input string:\n");
	gets(str);
	my_cos(my_str,str,N);
	sort(my_str,N);
	output(my_str,new_str,N);

}

void my_cos(char *ap[],char *str,int n)
{
	int i,j,n,a,m=1;
	for(i=0;i<n;i++)
	{
		if(str[i]==' ')
		{
			m=0;
			n=i+1;
		}
		for(j=n;m;j++)
			ap[i][j]=str[i]


	}
}
