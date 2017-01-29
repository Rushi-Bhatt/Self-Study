#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#define NULL 0

struct cirnode
{
	int val;
	struct cirnode *next;
}*start,*rear,*st;

void main()
{
	int x,y,choice;
	char con;

	clrscr();

	st=(cirnode*)malloc(sizeof(cirnode));
	start=NULL;
  //	printf("CHOICES\n1=insert\n2=delete from end\n3=delete from middle\n4=display\nchoice=");
//	scanf("%d",&choice);

	do
	{
		printf("CHOICES\n1=insert\n2=delete from end\n3=delete from middle\n4=display\n5=exit\n\nchoice=");
		fflush(stdin);
		scanf("%d",&choice);
		printf("\n");
		if(choice==1)
		{
			do
			{
				if(start==NULL)
				{
					printf("input value=");
					fflush(stdin);
					scanf("%d",&x);
					st->val=x;
					start=st;
					rear=st;
					rear->next=start;
				}

				else
				{
					st=(cirnode*)malloc(sizeof(cirnode));
					printf("input value=");
					fflush(stdin);
					scanf("%d",&x);
					st->val=x;
					rear->next=st;
					rear=st;
					rear->next=start;
				}
				printf("want to continue???(enter y)=");
				fflush(stdin);
				scanf("%c",&con);
			}while(con=='y');
		}

		else if(choice==2)
		{
			do
			{
				st=start;
				while(st->next!=rear)
				{
					st=st->next;
				}
				printf("%d deleted...\n",rear->val);
				rear=st;
				rear->next=start;
				printf("want to continue deleting???(enter y)=");
				fflush(stdin);
				scanf("%c",&con);
			}while(con=='y');
		}

		else if(choice==3)
		{
			do
			{
				printf("enter value u want to delete=");
				fflush(stdin);
				scanf("%d",&y);
				st->next=start;

				if(st->next->val==x)
				{
					printf("%d deleted\n",st->next->val);
					start=start->next;
				}
				else
				{
					while(st->next->val!=x)
					{
						st=st->next;
					}
				       printf("%d deleted\n",st->next->val);
				       st->next=st->next->next;

				}


				printf("want to continue deleting???(enter y)=");
				fflush(stdin);
				scanf("%c",&con);
			}while(con=='y');
		}


		else if(choice==4)
		{
			st->next=start;
			printf("OUTPUT IS...!!!\n");
			do
			{
				printf("%d-->",st->next->val);
				st=st->next;
			}while(st->next!=start);

			printf("\n\n");
			printf("want to use menu again???(enter y)=");
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

		else if(choice==5)
		{
			exit(0);
		}
	}while(con!='y');

	getch();
}