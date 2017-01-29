#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#define NULL 0

struct pol
{
	int c,x,y,z;
	struct pol *next;
}*start1,*start2,*rear1,*rear2,*st1,*st2,*s_ans,*t_ans,*r_ans;

void main()
{
	int ctr;
	int tc,tx,ty,tz;
	char con;
	clrscr();

	t_ans=(pol*)malloc(sizeof(pol));
	s_ans=NULL;
	st1=(pol*)malloc(sizeof(pol));
	st2=(pol*)malloc(sizeof(pol));

	start1=NULL;
	start2=NULL;
	printf("enter first equation::\n");
	do
	{
		if(start1==NULL)
		{
			printf("enter coefficient::");
			scanf("%d",&tc);

			printf("enter the power of x::");
			scanf("%d",&tx);

			printf("enter the power of y::");
			scanf("%d",&ty);

			printf("enter the power of z::");
			scanf("%d",&tz);

			st1->c=tc;
			st1->x=tx;
			st1->y=ty;
			st1->z=tz;

			 start1=st1;
			 rear1=st1;
			 rear1->next=NULL;
		}
		else
		{
			st1=(pol *)malloc(sizeof(pol));
			printf("enter coefficient::");
			scanf("%d",&tc);

			printf("enter the power of x::");
			scanf("%d",&tx);

			printf("enter the power of y::");
			scanf("%d",&ty);

			printf("enter the power of z::");
			scanf("%d",&tz);

			st1->c=tc;
			st1->x=tx;
			st1->y=ty;
			st1->z=tz;

			rear1->next=st1;
			rear1=st1;
			rear1->next=NULL;
		}
		printf("do you wanna add new node..??");
		fflush(stdin);
		scanf("%c",&con);
	}while(con=='y' ||con=='Y');

	printf("\nenter second equation::\n");
	do
	{
		if(start2==NULL)
		{
			printf("enter coefficient::");
			scanf("%d",&tc);

			printf("enter the power of x::");
			scanf("%d",&tx);

			printf("enter the power of y::");
			scanf("%d",&ty);

			printf("enter the power of z::");
			scanf("%d",&tz);

			st2->c=tc;
			st2->x=tx;
			st2->y=ty;
			st2->z=tz;

			 start2=st2;
			 rear2=st2;
			 rear2->next=NULL;
		}
		else
		{
		st2=(pol *)malloc(sizeof(pol));
		printf("enter coefficient::");
			scanf("%d",&tc);

			printf("enter the power of x::");
			scanf("%d",&tx);

			printf("enter the power of y::");
			scanf("%d",&ty);

			printf("enter the power of z::");
			scanf("%d",&tz);

			st2->c=tc;
			st2->x=tx;
			st2->y=ty;
			st2->z=tz;

			rear2->next=st2;
			rear2=st2;
			rear2->next=NULL;
		}
		printf("do you wanna add new node..??");
		fflush(stdin);
		scanf("%c",&con);
	}while(con=='y' ||con=='Y');

     /*	st1=start1;
	while(st1!=NULL)
	{
		printf("%d",st1->c);
		st1=st1->next;
	};*/

	st1=start1;
	s_ans=NULL;
	while(st1!=NULL)
	{
		st2=start2;
		ctr=0;
		while(st2!=NULL)
		{

			if(st1->x==st2->x)
			{
				if(st1->y==st2->y)
				{
					if(st1->z==st2->z)
					{
						if(s_ans==NULL)
						{
						ctr++;
						t_ans->c=st1->c+st2->c;
						st2->c=0;
						t_ans->x=st1->x;
						t_ans->y=st1->y;
						t_ans->z=st1->z;
						s_ans=t_ans;
						r_ans=t_ans;
						r_ans->next=NULL;
						}
						else
						{
						t_ans=(pol *)malloc(sizeof(pol));
						ctr++;
						t_ans->c=st1->c+st2->c;
						st2->c=0;
						t_ans->x=st1->x;
						t_ans->y=st1->y;
						t_ans->z=st1->z;

						r_ans->next=t_ans;
						r_ans=t_ans;
						r_ans->next=NULL;
						}
					}
				}
			}
			st2=st2->next;

		}
	    if(ctr==0)
	    {
					if(s_ans==NULL)
					{

						t_ans->c=st1->c+st2->c;

						t_ans->x=st1->x;
						t_ans->y=st1->y;
						t_ans->z=st1->z;
						s_ans=t_ans;
						r_ans=t_ans;
						r_ans->next=NULL;
						}
						else
						{
						t_ans=(pol *)malloc(sizeof(pol));

						t_ans->c=st1->c+st2->c;

						t_ans->x=st1->x;
						t_ans->y=st1->y;
						t_ans->z=st1->z;

						r_ans->next=t_ans;
						r_ans=t_ans;
						r_ans->next=NULL;
						}
	     }

	st1=st1->next;


	}

	st2=start2;
	while(st2!=NULL)
	{
		if(st2->c!=0)
		{
		t_ans=(pol *)malloc(sizeof(pol));
		t_ans->c=st2->c;
		t_ans->x=st2->x;
		t_ans->y=st2->y;
		t_ans->z=st2->z;
		r_ans->next=t_ans;
		r_ans=t_ans;
		r_ans->next=NULL;
		}
	     st2=st2->next;
	}
     printf("\nOUTPUT IS...!!!\n");
     t_ans=s_ans;
     while(t_ans!=NULL)
     {
	if(t_ans->c!=0)
	{
	      printf("%d %d %d %d",t_ans->c,t_ans->x,t_ans->y,t_ans->z);
	}
	t_ans=t_ans->next;
	if(t_ans!=NULL)
	{
		printf(" + ");
	}
     }
	getch();
}