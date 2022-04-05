#include<stdio.h>
#include<string.h>
#define N 3
void input(struct data *p,int n);
void output(struct data *p,int n);
struct data{
char name[20];
char gender[10];
int year;
float wage;
};

void main()
{
	struct data form[N];
	input(form,N);
	output(form,N);
}

void input(struct data *p,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("please input name:\n");
			gets(p[i].name);
		printf("please input gender:\n");
			gets(p[i].gender);
		printf("please input year:\n");
			scanf("%d",&p[i].year);
		printf("please input wage:\n");
			scanf("%f",&p[i].wage);
	}

}

void output(struct data *p,int n)
{
	int i;
	char str[]={'m','a','n'};
	for(i=0;i<n;i++)
	{
		if(p[i].year>10&&p[i].wage<300&&(strcmp(p[i].gender,str)==0))
			printf("%-s\t%-s\t%-d\t%-f\n",p[i].name,p[i].gender,p[i].year,p[i].wage);
	}
}