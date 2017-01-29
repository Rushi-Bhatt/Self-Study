#include<stdio.h>
#include<conio.h>
#include<process.h>
void main()
{
int a[10],i,low=1,high=5,pos=0;
int middle,x;
clrscr();

printf("how 10 elements you wanna insert in sorted order please,,..\n::");
for(i=1;i<=5;i++)
{
printf("enter %d th element:::",i);
scanf("%d",&a[i]);
}
printf("enter the element you wanna search::::");
scanf("%d",&x);
while(low<=high)
{

	middle=(low+high)/2;
	if(x<a[middle])
	   {  high=middle-1; }
	if(x>a[middle])
	     {low=middle+1; }

	       if(x==a[middle])
	       {
		pos=middle;
			 printf("successful search");
			 printf("element is :%d",pos);
			 break;
	       }
}
if(pos==0)
{
printf("unsuccessful search::::");
printf("element not present;;;");

}
getch();

}
