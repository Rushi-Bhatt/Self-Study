#include<conio.h>
#include<stdio.h>

struct node
{
 int val;
 struct node *next;
}*start=NULL;
struct node* newptr(int a)
{
  struct node *np=(struct node*)malloc(sizeof(struct node));
  np->next=NULL;
  np->val=a;
  return np;
}
void add_end(struct node *np)
{
 if(start==NULL)
 {
  start=np;
 }
 else
 {
  struct node* pt=start;
  do
  {
  pt=pt->next;
  }while(pt->next!=start);

  pt->next=np;
  np->next=start;
 }
}
void add_beg(struct node *np)
{
 if(start==NULL)
 {
  start=np;
  start->next=start;
 }
 else
 {
  struct node* pt=start;
  do
  {
  pt=pt->next;
  }while(pt->next!=start);

  pt->next=np;
  np->next=start;
  start=np;
 }
}
void del_beg()
{
 if(start==NULL)
 {
  printf("\nUnderFlow..!!!!");
 }
 else
 {
  struct node *np;
  struct node *pt=start;
  do
  {
  pt=pt->next;
  }while(pt->next!=start);
  pt->next=start->next;
  np=start;
  start=start->next;
  free(np);
 }
}
void del_end()
{
 if(start==NULL)
 {
  printf("\nUnderFlow..!!!!");
 }
 else
 { struct node *np,*st;
   np=start;
   if(np->next==start)
   {
    start=NULL;
   }
   else
   {
   while(np->next->next!=start)
   {
    np=np->next;
   }
     st= np->next;
     np->next=start;
     free(st);
   }
 }
}
void trav()
{
 struct node *np;
 np=start;
 printf("\nThe List is: ");
if(np==NULL)
{
 printf("\nList is NULL..");
}
else
 {
  do
   {
    printf("%d --> ",np->val);
    np=np->next;
   }while(np!=start);
  printf("Back To Start");
 }
}
void inst(int pos,struct node *np)
{
 struct node *pt=start;
 int i=1;
 if(pt==NULL)
 {
  start=np;
  np->next=start;
 }
 else
 {do
  {
   if(i==pos)
   {
    np->next=pt->next;
    pt->next=np;
    printf("\nInserted..");
    return;
   }
   pt=pt->next;
   i++;
  }while(pt!=start);
  printf("\nNot possible..");
 }

}
void main()
{
 int cho,v,pos;
 struct node* pt;
A: clrscr();
 printf("\nCircular Linked List:\n1.Insert in begining.\n2.Insert in End\n3.Delete from front\n4.Delete from end\n5.Traverse\n6.Insert\n7.Exit\n\nInput ur choice : ");
 scanf("%d",&cho);
 switch(cho)
 {
  case 1:printf("\nInput the val: ");
	 scanf("%d",&v);
	 pt=newptr(v);
	 add_beg(pt);
	 printf("\nInserted ...");
	 break;

  case 2:printf("\nInput the val: ");
	 scanf("%d",&v);
	 pt=newptr(v);
	 add_end(pt);
	 printf("\nInserted ...");
	 break;
  case 3:del_beg();
	 printf("\nDeleted ...");
	 break;
  case 4:del_end();
	 printf("\nDeleted ...");
	 break;
  case 5:trav();
	 break;
  case 6:printf("\nInput position after which u want to insert: ");
	 scanf("%d",&pos);
	 printf("\nInput the value: ");
	 scanf("%d",&v);
	 pt=newptr(v);
	 inst(pos,pt);
	 //printf("\nInserted..");
	 break;
  case 7:exit();
 }
 getch();
 goto A;
 B:
}