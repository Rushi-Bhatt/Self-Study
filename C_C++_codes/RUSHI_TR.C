#include<stdio.h>
#include<conio.h>
#define NULL 0
struct node
{
 int data;
 struct node *lptr;
 struct node *rptr;

}*p=NULL,*head,*nw,*r=NULL;
struct node* newnode(int a)
{

nw=(struct node *)malloc(sizeof(struct node));
nw->lptr=NULL;
nw->rptr=NULL;
nw->data=a;
return nw;
}


void main()
{

int a[20],n,i,r;
clrscr();
printf("enter how many elements u wanna enter:??\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("enter elements one by one::\n");
scanf("%d",&a[i]);
}

head=newnode(a[0]);
p=head;
for(i=0;i<n;i++)
{
	while(p!=NULL)
	{
		if(a[i]>p->data)
		{
		   while(p->rptr!=NULL)
		   {

		    p=p->rptr;
		   }

		   r=newnode(a[i]);
		   p->rptr=r;


		}


		   if(a[i]<p->data)
		{

		   while(p->lptr!=NULL)
		   {
		    p=p->lptr;
		   }
		   r=newnode(a[i]);
		   p->lptr=r;


		}




	}

}
printf("tree created::::");
getch();
}