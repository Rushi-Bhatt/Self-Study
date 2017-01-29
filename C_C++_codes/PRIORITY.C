#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

struct pnode
{
	int val,pr;
	struct pnode *next;
}*start,*rear,*st,*pt;

void main()
{
	int x,c,ctr,choice;
	char con;
	clrscr();

	start=NULL;
    do
    {
      printf("select operation which u want to perform:");
      printf("\n1.insertion\n2.deletion\n3.display\n4.exit\n");
      fflush(stdin);
      printf("\nenter choice=");
      scanf("%d",&choice);

      if(choice==1)
      {
	do
	{
		printf("enter value=");
		fflush(stdin);
		scanf("%d",&x);

		printf("enter priority of value=");
		fflush(stdin);
		scanf("%d",&c);

		if(start==NULL)
		{
			st=(pnode *)malloc(sizeof(pnode));
			st->val=x;
			st->pr=c;
			start=st;
			start->next=NULL;

		}

		else
		{
			ctr=0;
			pt=(pnode *)malloc(sizeof(pnode));
			pt->next=start;

			while((pt->next->pr<=c) && (pt->next!=NULL))
			{
				ctr++;
				pt=pt->next;
			}

			if(ctr!=0)
			{
				st=(pnode *)malloc(sizeof(pnode));
				st->val=x;
				st->pr=c;
				st->next=pt->next;
				pt->next=st;

			}

			else
			{
				st=(pnode *)malloc(sizeof(pnode));
				st->val=x;
				st->pr=c;
				st->next=start;
				start=st;
			}
		}

		printf("want to do the same task, then press y else n::");
		fflush(stdin);
		scanf("%c",&con);
	}while(con=='y'||con=='Y');
      }

      else if(choice==2)
      {
	do
	{
		if(start!=NULL)
		{
			printf("pr=%d,val=%d is DELETED\n",start->pr,start->val);
			start=start->next;
		}
		else
		{
		       printf("your Q is empty:(\n");
		}

		printf("want to do the same task of deletion, then press y else n::");
		fflush(stdin);
		scanf("%c",&con);
	}while(con=='y'||con=='Y');
      }

      else if(choice==3)
      {
	st=start;
	printf("\n");
	if(st!=NULL)
	{
		while(st!=NULL)
		{
			printf("priority=%d,value=%d---->",st->pr,st->val);
			st=st->next;


		}
	}
	else
	{
		printf("your Q is empty:(");
	}
	printf("\ndo u want to see the main menu:::??? then press y else n::");
	fflush(stdin);
	scanf("%c",&con);

	if(con=='y'||con=='Y')
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
      printf("\n\n");
    }while(con!='y'||con=='Y');
	getch();
}