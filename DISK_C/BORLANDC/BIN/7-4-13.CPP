#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>

void transHexToDec(char *d,char *h);
void reverse(char *s);

void main()
{
	char HStirng[5]="12";
	char DString[10];
	printf("please enter hex string!\n");
	scanf("%s",HString);
	transHexToDec(DString,HString);
	printf("HString:%s\n",HString);
	printf("DStirng:%s\n",DString);
}

void transHexToDec(char *d,char *h)
{
	long int sum=0;
	char *s=dStr;
	int count=0;
	while(*hStr!='\0')
	{
		if(*hStr>='0'&&*hStr<='9')
		{
			sum=sum*16+*hst-

