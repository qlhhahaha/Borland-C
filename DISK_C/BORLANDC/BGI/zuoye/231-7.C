#include<stdio.h>
void conclude(char *p1,int *p2);
void conclude(char *p1,int *p2)
{       
	for(;*p1!='\0';p1++)
	{
		if(((*p1>='a')&&(*p1<='z'))||((*p1>='A')&&(*p1<='Z')))
			(*p2)++;
		else if((*p1>='0')&&(*p1<='9'))
			(*(p2+1))++;
		else if(*p1==' ')
			(*(p2+2))++;
		else
			(*(p2+3))++;
	}
}
void main()
{
	int data[4]={0,0,0,0};
	char str[80];
	gets(str);
	conclude(str,data);
	printf("the number of english is %d\nthe number of number is :%d\nthe number of space is :%d\nthe number of others is :%d\n",data[0],data[1],data[2],data[3]);

}