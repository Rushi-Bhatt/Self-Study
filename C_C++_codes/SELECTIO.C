#include<stdio.h>
#include<conio.h>
void main()
{
int n,a[20],pass,min,i,temp;

clrscr();
printf("enter how many elements u wanna sort..::\n");
scanf("%d",&n);
printf("enter  lements ;;;\n");
for(i=1;i<=n;i++)
{
scanf("%d",&a[i]);
}


for(pass=1;pass<=n-1;pass++)
{

  min=pass;
	for(i=pass+1;i<=n;i++)
	{
		if(a[i]<a[min])
		{
		min=i;
		}
	}
  if(min!=pass)
  {
  temp=a[min];
  a[min]=a[pass];
  a[pass]=temp;
  }

}
/**************************************/
printf("sorted array is::\n");
for(i=1;i<=n;i++)
{
printf("%d ",a[i]);
}


getch();
}