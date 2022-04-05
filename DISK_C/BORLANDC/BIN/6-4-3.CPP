#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()
{
	char s1[80],s2[80];
	int m,n,i,j;

	printf("please input the string:\n");
	gets(s1);
	n=strlen(s1);

	do
	{
		printf("please set the m:\n");
		scanf("%d",&m);
	}while(n<m);
       /*	for(i=0,j=m-1;j<n;i++,j++)
	{
		*(s2+i)=*(s1+j);
	}*/
	j=0;
	i=m-1;
	while(*(s2+j)!='\0')
	{

		*(s2+j)=*(s1+i);
		j++;
		i++;
	}
	printf("the changed string is:%s\n",s2);
	getch();
}

