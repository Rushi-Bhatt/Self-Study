
#include <stdio.h>
#include <conio.h>
void main()
{
	int arr[100],k=0,arr1[10][10],i,j,a,b;
	clrscr();

	printf("Enter the number of rows and columns : ");
	scanf("%d %d",&a, &b);

	printf("Enter the numbers : ");

	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			scanf("%d", &arr1[i][j]);
			arr[k++]=arr1[i][j];
		}
	}
	k=0;

	printf("\nRow major : \n\n");

	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{

			printf("%d  ", arr[k++]);
		}


	}

	printf("\nColumn Major :\n\n");

	for(j=0;j<b;j++)
	{
		for(i=j;i<k;i=i+b)
		{

			printf("%d ", arr[i]);

		}
	}
       getch();
}