#include<stdio.h>
#include<string.h>
void conclude(int *p,char *px);
void main()
{
	char str[100],string[10],b[4][10]={"big","small","number","space","else"};
	int i,j,a[4]={0},m;
	printf("please input the string:\n");
	gets(str);
	conclude(a,str);
	for(i=0;i<3;i++)
	{
		for(j=i+1;j<4;j++)
		{
			if(a[j]>a[i])
			{
				m=a[i];
				a[i]=a[j];
				a[j]=m;
				strcpy(string,b[i]);
				strcpy(b[i],b[j]);
				strcpy(b[j],string);
			}
		}
	}
	for(i=0;i<4;i++)
		printf("%s:%d\n",b[i],a[i]);


}
void conclude(int *p,char *px)
{
	int i;
	for(i=0;px[i]!='\0';i++)
	{
		if(px[i]>='A'&&px[i]<='Z')
			p[0]++;
		if(px[i]>='a'&&px[i]<='z')
			p[1]++;
		if(px[i]>='0'&&px[i]<='9')
			p[2]++;
		if(px[i]==' ')
			p[3]++;
		else
			p[4]++;
	}
}