#include<stdio.h>
#include<conio.h>

void main()
{
	int i;
	char a[7][20]={"sunday","monday","tuesday","wedensday","thursday","friday","saturday"};

	do
	{
		printf("\nplease input the i:\n");
		scanf("%d",&i);
	}while(!(i<=6&&i>=0));
	printf("%s",a[i]);
	getch();
}