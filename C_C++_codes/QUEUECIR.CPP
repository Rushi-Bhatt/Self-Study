#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#define NULL 0

struct cqnode
{
	int val;
	struct cqnode *next;
}*start,*rear,*st,*start1;

void main()
{
	int x,choice;
	char con;

	clrscr();

	start=NULL;
    do
    {
	printf("\nMENU\n1=insert\n2=delete\n3=display\n4=exit\n");
	printf("\nenter choice=");
	fflush(stdin);
	scanf("%d",&choice);
	if(choice==1)
	{
	do
	{
		st=(cqnode *)malloc(sizeof(cqnode));
		printf("enter value=");
		scanf("%d",&x);
		if(start==NULL)
		{
			st->val=x;
			start=st;
			rear=st;
			start->next=start;
		}

		else
		{
			st->val=x;
			rear->next=st;
			rear=st;
			rear->next=start;
			rear=st;
		}

		printf("wnat add more...?(y/n)==");
		fflush(stdin);
		scanf("%c",&con);
	}while(con=='y');
	}

	else if(choice==2)
	{
		do
		{
			if(start!=NULL)
			{
			if(start!=start->next)
			{
				start=start->next;
				rear->next=start;
			}
			else
			{
				start=NULL;
			}
			}
			else
			{
				printf("QUEUE IS EMPTY...!!!\n");
			}
			printf("want to cont. deleting?(y/n)=");
			fflush(stdin);
			scanf("%c",&con);
		}while(con=='y');
	}
	else if(choice==3)
	{
		st=start;
		if(start!=NULL)
		{
		do
		{
			printf("%d",st->val);
			st=st->next;
			if(st!=rear);
			{
				printf("-->");
			}
		}while(st!=start);

		}
		else
		{
			printf("QUEUE IS EMPTY...!!!\n");
		}

		printf("\nwant to use menu again...?(y/n)=");
		fflush(stdin);
		scanf("%c",&con);


		if(con=='y')
		{
			con='n';
		}
		else
		{
			exit(0);
		}
	}

	else if(choice==4)
	{
		exit(0);
	}

	else
	{
		printf("Plz enter correct choice...!!!");
		con='n';
	}
    }while(con!='y');
	getch();
}