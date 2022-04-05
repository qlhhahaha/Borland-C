#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 2
struct student{
char name[20];
char gender;
float marks[3];
};
void input(struct student *p,int n);
float aver(struct student *p,int n);
void sort(struct student *p,int n);
void output(struct student *p,float *px,int n);
void main()
{
	struct student data[N];
	float average;
	input (data,N);
	average=aver(data,N);
	sort(data,N);
	output(data,&average,N);

}

void input(struct student *p,int n)
{
	int i,j;
	char temp[10];
	for(i=0;i<n;i++)
	{
		printf("please input name\n");
			gets(p[i].name);
		printf("please input gender\n");
			gets(temp);
			p[i].gender=temp[0];
		printf("please input marks of chinese math and english\n");
			for(j=0;j<3;j++)
			{
				gets(temp);
				p[i].marks[j]=atof(temp);
			}
	}

}
float aver(struct student *p,int n)
{
	int i,j;
	float s=0;
	for(i=0;i<n;i++)
	{
		s+=p[i].marks[1];
	}
	return s/n;
}
void sort(struct student *p,int n)
{
	int i,j;
	struct student m;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[j].marks[1]>p[i].marks[1])
			{
				m=p[i];
				p[i]=p[j];
				p[j]=m;
			}
		}
	}
}
void output(struct student *p,float *px,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(p[i].gender=='F'&&p[i].marks[1]>*px)
		{
			printf("name:%s\nmarks:%f %f %f\n",p[i].name,p[i].marks[0],p[i].marks[1],p[i].marks[2]);
		}
	}
}