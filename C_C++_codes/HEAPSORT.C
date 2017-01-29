#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int *a,size;
void swap (int *low,int *high)
{
	int temp;
	temp = a[*low];
	a[*low] = a[*high];
	a[*high] = temp;
	(*low)++;
	(*high)--;
}
void heapsort (int LOW , int HIGH)
{
	int low,high,mid;
	int *k,*l;
	low = LOW;
	high = HIGH;
	mid = (high+low+1)/2;
	while(low<=high)
	{
		fflush(stdin);
		while(a[low] < a[mid])
		low++;
		fflush(stdin);
		while(a[high]  > a[mid])
		high--;
		if(low<=high)
		{
			k =&low;
			l = &high;
			swap(k,l);
		}
	}
	fflush(stdin);
	if(high > LOW )
	{
		heapsort(LOW,high);
	}
	if( low < HIGH )
	{
		heapsort(low,HIGH);
	}
}

void main ()
{
	int i,j,k;
	clrscr ();
	printf("Enter The Size Of Array\n");
	scanf("%d",&size);
	a = (int *)malloc(sizeof(size) );
	for(i=0;i<=(size-1);i++)
	scanf("%d",&a[i]);
	heapsort(0,size-1);
	for(i=0;i<=(size-1);i++)
	printf("%d\n",a[i]);
	getch ();
	}