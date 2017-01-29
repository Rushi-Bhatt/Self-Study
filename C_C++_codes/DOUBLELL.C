#include<conio.h>
#include<stdio.h>
#include<alloc.h>

struct node
	{
		int info;
		struct node *rptr, *lptr;
	} *left=NULL, *right=NULL, *temp, *save;




void main()
{
	int n,i,j;
	int c;
	clrscr();


	printf("Enter no. of elemnts: ");
	scanf("%d", &n);

	for(i=1; i<=n; i++)
	{
		temp=(struct node *)malloc(struct node *);

		printf("Enter element %d: ",i);
		scanf("%d", &c);

		temp->info=c;

		if(left==NULL && right==NULL)
		{
			left=temp;
			right=temp;
			left->lptr=NULL;
			right->rptr=NULL;
		}

		else
		{
			save=left;
			while(save->lptr!=NULL)
				save=save->lptr;



