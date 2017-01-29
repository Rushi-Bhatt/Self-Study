#include<stdio.h>
#include<conio.h>

#define size 10

void main()
	{
	int a[size],i,l,h,m,n,f;
	clrscr();
	printf("\nHowmany elements do u want to enter?? \n");
		scanf("%d",&n);

	printf("\nEnter elements :\n");
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	printf("\nEnter element which u want to find :\n");
		scanf("%d",&f);

	l=1;
	h=n;
	while(l<=h)


		{
		m=(l+h)/2;
		if(f<a[m])
			h=m-1;
		else
			{
			if(f>a[m])
				l=m+1;

			else

				{
				printf("\nElement %d is found on position %d",a[m],m);
				break;
				}


			}

		}

       getch();
       }

