 #include<stdio.h>
 #include<conio.h>

 void main()
 {
	long int a=1,i;
	for(i=1;i<=10;i++)
	{
		a=(a+1)*2;
		printf("%ld\n",a);
	}
	getch();
 }