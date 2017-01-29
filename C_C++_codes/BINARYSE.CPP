#include<conio.h>
#include<stdio.h>

void main()
{
	int x[10];
	int l,m,h,i;
	int A;

	clrscr();
	l=0;
	h=9;

	for(i=0;i<10;i++)
	{
		printf("enter value %d=",i+1);
		scanf("%d",&x[i]);
	}
	printf("\nenter value u want to search=");
	scanf("%d",&A);


	do
	{
		m=(l+h)/2;

		if(x[m]>A)
		{
			h=m;
		}
		else
		{
			l=m;
		}
	}while(x[m]!=A);

	printf("\nyour Number  %d is at %d Nndex no. and %d Positin",A,m,m+1);
getch();
}
