#include<stdio.h>
#include<conio.h>
void main()
{
int n,i,a[20],last,xc,pass,temp;
clrscr();
printf("enter how many elements u wanna sort..::\n");
scanf("%d",&n);
printf("enter elements ;;;\n");
for(i=1;i<=n;i++)  
scanf("%d",&a[i]);
}

last=n;
for(pass=1;pass<n;pass++)
{
xc=0;
	for(i=1;i<=last-1;i++)
	{
	   if(a[i]>a[i+1])
	   {
	   temp=a[i];
	   a[i]=a[i+1];
	   a[i+1]=temp;
	   xc=xc+1;
	   }

	}
	if(xc==0)
	{
		printf("task completed...\n");
		break;

	 }
	 else
	 last=last-1;


}
/*******************/
for(i=1;i<=n;i++)
{
printf("%d ",a[i]);
}

getch();
}