#include<stdio.h>
#include<conio.h>
void main()
{
int b[3][3];
int i,j;
clrscr();
printf("enter the elements of matrix plz:\n");
for(i=0;i<3;i++)
{
    for(j=0;j<3;j++)
    {
     printf("\nenter A[%d,%d] th element: ",i,j);
     scanf("%d",&b[i][j]);

    }

}
printf("the row major format::");
for(i=0;i<3;i++)
{
    for(j=0;j<3;j++)
    { printf("%d  ",b[i][j]);

    }

}
printf("\nthe column major format::");
for(i=0;i<3;i++)
{
    for(j=0;j<3;j++)
    {
    printf("%d  ",b[j][i]);

    }

}

getch();
}