#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

struct pqnode
{
	int val,pr;
	struct pqnode *next;
}*start,*rear,*st,*pt,*a;

void main()
{
	int tval,tpr,ctr,choice;
	char con;
	clrscr();

	start=NULL;
    do
    { printf("MENU\n1=insert\n2=delete\n3=display\n4=exit\n");
      fflush(stdin);
      printf("\nenter choice=");
      scanf("%d",&choice);

      if(choice==1)
      {
	do
	{
		printf("enter value=");
		fflush(stdin);
		scanf("%d",&tval);

		printf("enter priority of value=");
		fflush(stdin);
		scanf("%d",&tpr);

		if(start==NULL)
		{
			st=(pqnode *)malloc(sizeof(pqnode));
			st->val=tval;
			st->pr=tpr;
			start=st;
			start->next=NULL;

		}

		else
		{
			ctr=0;
			pt=(pqnode *)malloc(sizeof(pqnode));
			pt->next=start;

			while((pt->next->pr<=tpr) && (pt->next!=NULL))
			{
				ctr++;
				pt=pt->next;
			}

			if(ctr!=0)
			{
				st=(pqnode *)malloc(sizeof(pqnode));
				st->val=tval;
				st->pr=tpr;
				st->next=pt->next;
				pt->next=st;

			}

			else
			{
				st=(pqnode *)malloc(sizeof(pqnode));
				st->val=tval;
				st->pr=tpr;
				st->next=start;
				start=st;
			}
		}

		printf("want to continue?(y/n)=");
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
			printf("pr=%d,val=%d is DELETED\n",start->pr,start->val);
			start=start->next;
		}
		else
		{
		       printf("QUEUE IS EMPLTY...!!!\n");
		}

		printf("want to continue deleting?(y/n)=");
		fflush(stdin);
		scanf("%c",&con);
	}while(con=='y');
      }

      else if(choice==3)
      {
	st=start;
	printf("\n");
	if(st!=NULL)
	{
		while(st!=NULL)
		{
			printf("pr=%d,val=%d",st->pr,st->val);
			st=st->next;
			if(st!=NULL)
			printf("-->");
		}
	}
	else
	{
		printf("QUEUE IS EMPTY...!!!");
	}
	printf("\nwant use menu again?(y/n)=");
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
      printf("\n\n");
    }while(con!='y');
	getch();
}