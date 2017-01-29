#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#define NULL 0

struct pol
{
	int c,x,y,z;
	struct pol *next;
}*start1,*start2,*rear1,*rear2,*st1,*st2,*start_ans,*temp_ans,*rear_ans;

void main()
{
	int ctr;
	int t_c,t_X,t_y,t_z;
	char con;
	clrscr();

	temp_ans=(pol*)malloc(sizeof(pol));
	start_ans=NULL;
	st1=(pol*)malloc(sizeof(pol));
	st2=(pol*)malloc(sizeof(pol));

	start1=NULL;
	start2=NULL;
	printf("enter 1st equation::\n");
	do
	{
		if(start1==NULL)
		{
			printf("enter coefficient::");
			scanf("%d",&t_c);

			printf("enter pow(x)::");
			scanf("%d",&t_X);

			printf("enter pow(y)::");
			scanf("%d",&t_y);

			printf("enter pow(z)::");
			scanf("%d",&t_z);

			st1->c=t_c;
			st1->x=t_X;
			st1->y=t_y;
			st1->z=t_z;

			 start1=st1;
			 rear1=st1;
			 rear1->next=NULL;
		}
		else
		{
			st1=(pol *)malloc(sizeof(pol));
			printf("enter coefficient::");
			scanf("%d",&t_c);

			printf("enter pow(x)::");
			scanf("%d",&t_X);

			printf("enter pow(y)::");
			scanf("%d",&t_y);

			printf("enter pow(z)::");
			scanf("%d",&t_z);

			st1->c=t_c;
			st1->x=t_X;
			st1->y=t_y;
			st1->z=t_z;

			rear1->next=st1;
			rear1=st1;
			rear1->next=NULL;
		}
		printf("add new node..?? then press 'y' else 'n'");
		fflush(stdin);
		scanf("%c",&con);
	}while(con=='y' ||con=='Y');

	printf("\nenter 2nd equation::\n");
	do
	{
		if(start2==NULL)
		{
			printf("enter coefficient::");
			scanf("%d",&t_c);

			printf("enter pow(x)::");
			scanf("%d",&t_X);

			printf("enter pow(y)::");
			scanf("%d",&t_y);

			printf("enter pow(z)::");
			scanf("%d",&t_z);

			st2->c=t_c;
			st2->x=t_X;
			st2->y=t_y;
			st2->z=t_z;

			 start2=st2;
			 rear2=st2;
			 rear2->next=NULL;
		}
		else
		{
		st2=(pol *)malloc(sizeof(pol));
		printf("enter coefficient::");
			scanf("%d",&t_c);

			printf("enter the pow(x)::");
			scanf("%d",&t_X);

			printf("enter the pow(y)::");
			scanf("%d",&t_y);

			printf("enter the pow(z)::");
			scanf("%d",&t_z);

			st2->c=t_c;
			st2->x=t_X;
			st2->y=t_y;
			st2->z=t_z;

			rear2->next=st2;
			rear2=st2;
			rear2->next=NULL;
		}
		printf("add new node..?? then press 'y' else 'n'");
		fflush(stdin);
		scanf("%c",&con);
	}while(con=='y' ||con=='Y');

	st1=start1;
	start_ans=NULL;
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
						if(start_ans==NULL)
						{
						ctr++;
						temp_ans->c=st1->c+st2->c;
						st2->c=0;
						temp_ans->x=st1->x;
						temp_ans->y=st1->y;
						temp_ans->z=st1->z;
						start_ans=temp_ans;
						rear_ans=temp_ans;
						rear_ans->next=NULL;
						}
						else
						{
						temp_ans=(pol *)malloc(sizeof(pol));
						ctr++;
						temp_ans->c=st1->c+st2->c;
						st2->c=0;
						temp_ans->x=st1->x;
						temp_ans->y=st1->y;
						temp_ans->z=st1->z;

						rear_ans->next=temp_ans;
						rear_ans=temp_ans;
						rear_ans->next=NULL;
						}
					}
				}
			}
			st2=st2->next;

		}
	    if(ctr==0)
	    {
					if(start_ans==NULL)
					{

						temp_ans->c=st1->c+st2->c;

						temp_ans->x=st1->x;
						temp_ans->y=st1->y;
						temp_ans->z=st1->z;
						start_ans=temp_ans;
						rear_ans=temp_ans;
						rear_ans->next=NULL;
						}
						else
						{
						temp_ans=(pol *)malloc(sizeof(pol));

						temp_ans->c=st1->c+st2->c;

						temp_ans->x=st1->x;
						temp_ans->y=st1->y;
						temp_ans->z=st1->z;

						rear_ans->next=temp_ans;
						rear_ans=temp_ans;
						rear_ans->next=NULL;
						}
	     }

	st1=st1->next;


	}

	st2=start2;
	while(st2!=NULL)
	{
		if(st2->c!=0)
		{
		temp_ans=(pol *)malloc(sizeof(pol));
		temp_ans->c=st2->c;
		temp_ans->x=st2->x;
		temp_ans->y=st2->y;
		temp_ans->z=st2->z;
		rear_ans->next=temp_ans;
		rear_ans=temp_ans;
		rear_ans->next=NULL;
		}
	     st2=st2->next;
	}
     printf("\ntask completed,,.. ans is::\n");
     temp_ans=start_ans;
     while(temp_ans!=NULL)
     {
	if(temp_ans->c!=0)
	{
	      printf("%d %d %d %d---->",temp_ans->c,temp_ans->x,temp_ans->y,temp_ans->z);
	}
	temp_ans=temp_ans->next;

     }
	getch();
}