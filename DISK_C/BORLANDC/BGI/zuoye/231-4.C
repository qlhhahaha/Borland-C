#include<stdio.h>
#include<string.h>
void delet(char *p,char del);
void delet(char *p,char del)
{
	for(;*p!='\0';)
	{
	if(*p==del)
		strcpy(p,p+1);
	else
        	p++;
	}
	return;
}
void main()
{
	char str[80];
	char m;

	gets(str);
	scanf("%c",&m);
	delet(str,m);
	puts(str);
}
