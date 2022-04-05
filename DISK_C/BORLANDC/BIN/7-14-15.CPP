#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#define N 2

struct subject
{
	char stuNo[20];
	char name[20];
	int sex;
	int math;
	int phy;
	int english;
	int computer;
	float aver;
}student[N];

void input(subject *stu);
void output(subject *stu,float classAver);
float calc(subject *stu);
void sort(subject *stu);

void main()
{
	float subjectAver=0.0;
	input(student);
	subjectAver=calc(student);
	sort(student);
	output(student,subjectAver);
	getch();
}

void input(subject *stu)
{
	int i;
	for(i=0;i<N;i++)
	{
		printf("student %d information\n",i+1);
		scanf("%s\n",stu[i].stuNo);
		scanf("%s\n",stu[i].name);
		scanf("%d\n",&stu[i].sex);
		scanf("%d\n",&stu[i].math);
		scanf("%d\n",&stu[i].phy);
		scanf("%d\n",&stu[i].english);
		scanf("%d\n",&stu[i].computer);
	}
}

void output(subject *stu,float classAver)
{
	int i;
	for(i=0;i<N;i++)
	{
	if(stu[i].aver>=classAver&&stu[i].sex==1)
	{
		printf("%s",stu[i].stuNo);
		printf("%s",stu[i].name);
		printf("%d",stu[i].sex);
		printf("%5d",stu[i].math);
		printf("%5d",stu[i].phy);
		printf("%5d",stu[i].english);
		printf("%5d",stu[i].computer);
		printf("\n");
	}
	}
}

float calc(subject *stu)
{

	int i;
	float subAver=0.0;
	for(i=0;i<N;i++)
	{
		stu[i].aver=(float)(stu[i].math+stu[i].phy+stu[i].english+stu[i].computer)/4;
		subAver+=stu[i].aver;
	}
	subAver=subAver/N;
	return subAver;

}

void sort(subject *stu)
{
	int i,j;
	subject item;
	for(i=0;i<N-1;i++)
	{
		for(j=i+1;j<N;j++)
		{
			if(stu[i].aver<stu[j].aver)
			{
				item=stu[i];
				stu[i]=stu[j];
				stu[j]=item;
			}
		}
	}
}





