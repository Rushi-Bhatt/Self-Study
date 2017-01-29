#include<conio.h>
#include<stdio.h>
#include<string.h>

void main()
{
	int a,b,c,i,ln,j,bln;
	int tp[20],x[20],y[20];
	char A[20];
	clrscr();

	printf("ENTER INFIX EQUATION=");
	scanf("%s",&A);

	ln=strlen(A);
	bln=0;

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

		else if(A[i]>='a' && A[i]<='z')
		{
			x[i]=4;
		}
		else if(A[i]=='(')
		{
			x[i]=0;
			A[i]='0';
			bln++;
		}

		else if(A[i]==')')
		{
			x[i]=-1;
			A[i]='0';
			bln++;
		}

		else if(A[i]=='^')
		{
		       x[i]=3;
		}
	}

	for(i=0;i<ln;i++)
	{
		printf("%d",x[i]);
	}
	printf("\n");

	//CALCULATING MAIN OUTPUT

	a=-1;b=0;c=0;

	while(c!=ln-bln )
	{
		while((x[b]>=tp[a] || a==-1 || x[b]==0) && b!=ln)
		{
			a++;
			tp[a]=x[b];
			b++;

		}
		for(i=0;i<=a;i++)
		{
			printf("%d",tp[i]);
		}
		printf("\n");

		while((x[b]<=tp[a] || b>=ln)  && a!=-1)
		{
			if(x[b]==-1)
			{
				while(tp[a]!=0)
				{
					y[c]=tp[a];
					a--;
					c++;
				}
				a--;
				b++;
			}

			else
			{
				y[c]=tp[a];



				a--;
				c++;
			}

		}

		if(x[b]!=-1)
		{
			a++;
			tp[a]=x[b];
			b++;
		}

	}

	//PRINTING MAIN OUTPUT IN DIGITS

	printf("\n");
	for(i=0;i<ln-bln;i++)
	{
		printf("%d",y[i]);
	}

	//PRINTING MAIN OUTPUT

	printf("\nPOSTFIX EQUZTION IS...!!!\n");

	for(i=0;i<ln-bln;i++)
	{
		if(y[i]==4)
		{
			j=0;
			while(A[j]<'a' || A[j]>'z')
			{
				j++;
			}
		}

		else if(y[i]==2)
		{
			j=0;
			while(A[j]!='*' && A[j]!='/')
			{
				j++;
			}
		}

		else if(y[i]==1)
		{
			j=0;
			while(A[j]!='+' && A[j]!='-')
			{
				j++;
			}
		}

		else if(y[i]==3)
		{
			j=0;
			while(A[j]!='^')
			{
				j++;
			}
		}


		else{}

		printf("%c ",A[j]);
		A[j]='0';
	}

	getch();
}

