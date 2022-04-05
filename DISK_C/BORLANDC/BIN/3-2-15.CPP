#include<stdio.h>
#include<conio.h>
#define pie 3.14

void main()
{
	float r,h,v;
	printf("please input r & h:\n");
	scanf("%f%f",&r,&h);

	v=pie*r*h*1/3;
	printf("v=%f",v);
	getch();
}