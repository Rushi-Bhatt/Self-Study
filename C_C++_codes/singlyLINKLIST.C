#include<conio.h>
#include<stdio.h>

struct node
{
 int val;
 struct node *next;
}*front=NULL,*rear=NULL;
struct node* newptr(int a)
{
  struct node *np=(struct node*)malloc(sizeof(struct node));
  np->next=NULL;
  np->val=a;
  return np;
}
void add_end(struct node *np)
{
 if(front==NULL)
 {
  front=rear=np;
 }
 else
 {
  rear->next=np;
  rear=np;
 }
}
void add_beg(struct node *np)
{
 if(front==NULL)
 {
  front=rear=np;
 }
 else
 {
  np->next=front;
  front=np;
 }
}
void del_beg()
{
 if(front==NULL)
 {
  printf("\nUnderFlow..!!!!");
 }
 else
 {
  struct node *np;
  np=front;
  front=front->next;
  free(np);
 }
}
void del_end()
{
 if(front==NULL)
 {
  printf("\nUnderFlow..!!!!");
 }
 else
 { struct node *np,*st;
   np=front;
   if(np->next==NULL)
   {
    front=NULL;
   }
   else
   {
   while(np->next->next!=NULL)
   {
    np=np->next;
   }
     st= np->next;
     np->next=NULL;
     free(st);
   }
 }
}
void rev()
{
 struct node *np,*st,*rt;
 np=front;
 st=np->next;
 np->next=NULL;
 while(st!=NULL)
 {
   rt=st->next;
   st->next=np;
   np=st;
   st=rt;
 }
 front=np;
}
void trav()
{
 struct node *np;
 np=front;
 printf("\nThe List is: ");

 while(np!=NULL)
 {
  printf("%d --> ",np->val);
 np=np->next;
 }
 printf("END");
}
void main()
{
 int cho,v;
 struct node* pt;
A: clrscr();
 printf("\n1.Insert in begining.\n2.Insert in End\n3.Delete from front\n4.Delete from end\n5.Traverse\n6.Reverse\n7.Exit\n\nInput ur choice : ");
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
  case 6:rev();
	 printf("\nReversed..");
	 break;
  case 7:exit();
 }
 getch();
 goto A;
 B:
}