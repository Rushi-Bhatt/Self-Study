#include<stdio.h>
#include<conio.h>
void quick_sort(int a[],int lb,int ub);
void main()
{
      int n,a[20],i;
clrscr();
printf("enter how many elements u wanna enter;;\n");
scanf("%d",&n);
printf("enter elements::\n");
for(i=0;i<n;i++)
{
 scanf("%d",&a[i]);
}

quick_sort(a,0,n-1);

printf("the sorted array is:::\n");
for(i=0;i<n;i++)
{
 printf("%d ",a[i]);
}


 getch();
}

void quick_sort(int a[],int lb,int ub)
{
int n,flag=1,i,p=lb+1,q=ub,k=a[lb],temp;
if(lb<=ub)
{
	while(flag)
	{
	 while(a[p]<k && lb<=ub)
	 {
	   p=p+1;

	 }
	 while(a[q]>k && lb<=ub)
	 {
	   q=q-1;

	 }
	 if(p<=q)
	 {
	  temp=a[p];
	  a[p]=a[q];
	  a[q]=temp;
	 }
	 else
	 {
	  flag=0;
	   a[lb]=a[q];
	   a[q]=k;

	 }
	}
}
else
    return;
 quick_sort(a,lb,q-1);
 quick_sort(a,q+1,ub);


}