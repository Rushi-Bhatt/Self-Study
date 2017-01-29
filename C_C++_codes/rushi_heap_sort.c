/************* C Program To Sort An Array Using Heap Sort *************/

#include < stdio.h>
#include < conio.h>

void swap(int *x,int *y)
{
int temp;
temp=*x;
*x = *y;
*y = temp;
}

void heapsort(int a[],int n)
{
int i,s,f;
for(i=1;i< n;++i)
{
s=i;
f=(s-1)/2;
while( a[f]< a[s])
{
swap(&a[f],&a[s]);
s=f;
if(s==0)
break;
f=(s-1)/2;
}
}
for(i=n-1;i>=1;--i)
{
swap(&a[0],&a[i]);
f=0;
s=1;
if(i==1)
break;
if(i>2)if(a[2]>a[1])s=2;
while( a[f]< a[s] )
{ 
swap(&a[f],&a[s]);
f=s;
s=2*f+1;
if(i>s+1 )if(a[s+1]>a[s])s=s+1;
if (s>=i)
break;
}
}
}


void main()
{
int a[100],n,i;
clrscr();
printf("\t\tHEAP SORT\n");
printf("\nEnter The Number Of Elements\t: ");
scanf("%d",&n);
printf("\nEnter Elements\n");
for(i=0;i< n;++i)
scanf("%d",&a[i]);
heapsort(a,n);
printf("\n\t\t\tSorted List\n");
for(i=0;i< n;++i)
printf("\t%d",a[i]);
getche();
}