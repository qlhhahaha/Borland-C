#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()
{
	char s1[80],s2[80];
	char *p,*q;
	int n=0,l1,l2,i;
	gets(s1);
	gets(s2);
	l1=strlen(s1);
	l2=strlen(s2);
	p=s1;
	q=s2;

	for(i=0;i<l1&&i<l2;i++)
	{
		if(*(p+i)==*(q+i))
		{
			n++;
		}
	}
	printf("%d",n);
	getch();
}
