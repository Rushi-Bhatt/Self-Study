#include<conio.h>
#include<stdio.h>

void main()
{
	int a,b,c,i,ln,j;
	int tp[10],x[10],y[10];
	char A[10];
	clrscr();

	printf("ENTER INFIX EQUATION=");
	scanf("%s",&A);

	printf("please enter length of string=");
	scanf("%d",&ln);

	//CONVERTING INFIX EQUATION TO DIGITS

	for(i=0;i<ln;i++)
	{
		if(A[i]=='/' || A[i]=='*')
		{
			x[i]=2;
		}

		else if(A[i]=='+' || A[i]=='-')
		{
			x[i]=1;
		}

		else if(A[i]!='*' && A[i]!='/' && A[i]!='+' && A[i]!='-')
		{
			x[i]=3;
		}
		else
		{}
	}

	//CALCULATING MAIN OUTPUT

	a=-1;b=0;c=0;

	while(c!=ln )
	{
		while(x[b]>=tp[a] || a==-1)
		{
			a++;
			tp[a]=x[b];
			b++;

		}

		while((x[b]<=tp[a] || b==ln)  && a!=-1)
		{
			y[c]=tp[a];
			a--;
			c++;

		}
		a++;
		tp[a]=x[b];
		b++;
	}

	//PRINTING MAIN OUTPUT IN DIGITS

	for(i=0;i<ln;i++)
	{
		printf("%d",y[i]);
	}

	//PRINTING MAIN OUTPUT

	printf("\nPOSTFIX EQUZTION IS...!!!\n");

	for(i=0;i<ln;i++)
	{
		if(y[i]==3)
		{
			j=0;
			while(A[j]=='+' || A[j]=='-' || A[j]=='/' || A[j]=='*' || A[j]=='0')
			{
				j++;
			}
		}

		else if(y[i]==2)
		{
			j=0;
			while(A[j]=='+' || A[j]=='-'  || A[j]=='0')
			{
				j++;
			}
		}

		else if(y[i]==1)
		{
			j=0;
			while(A[j]=='*' || A[j]=='/' || A[j]=='0')
			{
				j++;
			}
		}

		else
		{}

		printf("%c",A[j]);
		A[j]='0';
	}

	getch();
}

