#include<conio.h>
#include<stdio.h>

struct node
{
 int val;
 struct node *next;
 struct node *prev;
}*front=NULL,*rear=NULL;
struct node* newptr(int a)
{
  struct node *np=(struct node*)malloc(sizeof(struct node));
  np->next=NULL;
  np->prev=NULL;
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
  np->prev=rear;
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
  front->prev=np;
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
  front->next->prev=NULL;
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
 { struct node *np;
   if(rear->prev==NULL)
   {
    front=rear=NULL;
   }
   else
   {
    np=rear;
    rear->prev->next=NULL;
    rear=rear->prev;
    free(np);
   }
 }
}
void trav_front()
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
void trav_back()
{
 struct node *np;
 np=rear;
 printf("\nThe list is: ");
 while(np!=NULL)
 {
  printf("%d --> ",np->val);
  np=np->prev;
 }
 printf("END");

}
void main()
{
 int cho,v;
 struct node* pt;
A: clrscr();
 printf("\Doubly linked list:\n1.Insert in begining.\n2.Insert in End\n3.Delete from front\n4.Delete from end\n5.Traverse from front\n6.Traverse Backwarsds\n7.Exit\n\nInput ur choice : ");
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
  case 5:trav_front();
	 break;
  case 6:trav_back();
	 break;
  case 7:exit();
 }
 getch();
 goto A;
 B:
}