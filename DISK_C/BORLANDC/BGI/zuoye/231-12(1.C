#include<stdio.h>
void mut(char (*p)[30],int 10,int *px);

void mut(char (*p)[30],int 10,int *px)
{
	int i,j;
	for(i=0,i<10,i++)
	{
		gets(*(p+i)[30]);
		scanf("%d\n",px[i]);
	}

}
void main()
{
	char str[10][30];
	int data[10];
	mut(str,data);
}