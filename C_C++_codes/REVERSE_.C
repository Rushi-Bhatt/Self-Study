#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
#define null 0

struct link
	{
	int info;
	struct link *next;
	};

typedef struct link node;
node *start=null;
void ins_end();
void display();

void rev();

void ins_front()
	{
	node *np;

	np=(node*)malloc(sizeof(node));

	printf("Enter data: \n");
	scanf("%d",&np->info);
	np->next=start;
	start=np;
	if(start==null)
		start=np;
       printf("node is inserted\n");
	}

void rev()
	{

	printf("\n string reversed...........");
	printf("\n answer::::\n");
	node *temp=start;
		while(temp!=null)
			{
			printf(" %d",temp->info);
			temp=temp->next;
			}


	}
	void main()
	{
	int c,n;
	clrscr();

	do
	{

	printf("\n 1.Insert the node \n 2.Reverse the node and 3.exit \n");
	scanf("%d",&c);

	switch(c)
		{
		case 1:
			ins_front();
			break;
		case 2:
			rev();

			break;
		case 3:exit(0);
		       break;

		}

	printf("\nIf u want to repeat this process then pres 1\n");
	scanf("%d",&n);
	}

	while(n==1);
	getch();
	}

