
#include<stdio.h>
#include<string.h>
void main()
{
	int i,j,k,a[100],t,m;
	char str[100][20],str1[20];
	printf("please input name and marks\n");
	for(i=0;i<100;i++)
	{
		scanf("%s",str[i]);
		scanf("%d",&a[i]);
		if(strcmp(str[i],"end")==0)
		break;
	}
	m=i;
	for(i=0;i<m-2;i++)
	{
		j=i;
		for(k=i+1;k<m-1;k++)
		{
			if(a[k]>a[j])
			{
				j=k;
			}
		}
		if(j!=i)
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
			strcpy(str1,str[i]);
			strcpy(str[i],str[j]);
			strcpy(str[j],str1);
		}

	}
	for(i=0;i<m;i++)
	{
		printf("%s\n",str[i]);
		printf("%d\n",a[i]);
	}
}