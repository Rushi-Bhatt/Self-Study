#include<stdio.h>
#include<conio.h>
void main()
{
int n,a[10],k,j,i;
clrscr();
printf("How many elements do you want::");
scanf("%d",&n);
for(i=0;i<n;i++)
  {
   scanf("%d",&a[i]);

  }

for(i=1;i<n;i++)
{
  k=a[i];
   for(j=i-1;j>=0&&a[j]>k;j--)
   {

	a[j+1]=a[j];
   }

a[j+1]=k;

}

printf("sorted array is:::\n");
for(i=0;i<n;i++)
  {

   printf("%d ",a[i]);

  }

getch();

}