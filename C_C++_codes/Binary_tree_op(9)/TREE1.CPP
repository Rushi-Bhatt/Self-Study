/*11BCE108 :Kishan Panchal */
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
#define null 0

typedef struct tree
		{
		int info;
		struct tree *l,*r,*h;
		}node;

node *root=null;
int leaves;
void ins(int,node**);
void display(node*,int);
void del_node(int,node**);
void del(node**,node*);
void search(int,node*);
void inorder(node*);
void preorder(node*);
void postorder(node*);
void count_leaves(node*);

void main()
	{
	clrscr();
	int m,n,j,k;
		do
		{

		printf("\t\t11BCE108(Kishan Panchal)");
		printf("\n\tMain Menu(operation on binary tree)\n");
		printf("\n1.Insert node");
		printf("\n2.Display in tree form");
		printf("\n3.Pre-order traversal of tree");
		printf("\n4.In-order traversal of tree");
		printf("\n5.Post-order traversal of tree");
		printf("\n6.Number of leaves");
		printf("\n7.Searching");
		printf("\n8.Delete");
		printf("\n9.Exit");
		printf("\n\Enter your choice : \n");
		scanf("%d",&m);
		switch(m)
			{

			case 1: printf("\nEnter number: ");
				scanf("%d",&n);
				ins(n,&root);
				break;
			case 2: printf("\nDisplay is like tree form first element of left side is root node");
				display(root,1);
				break;
			case 3: display(root,1);
				printf("\nPreorder of above tree :");
				preorder(root);
				break;
			case 4: display(root,1);
				printf("\nInorder of above tree :");
				inorder(root);
				break;
			case 5: display(root,1);
				printf("\nPostorder of above tree :");
				postorder(root);
				break;
			case 6: leaves=0;
				count_leaves(root);
				printf("No of leaves : %d",leaves);
				break;
			case 7: printf("\nEnter the value to be searched: ");
				scanf("%d",&n);
				search(n,root);
				break;
			case 8: display(root,1);
				printf("\nEnter the value to be deleted from tree: ");
				scanf("%d",&n);
				del_node(n,&root);
				printf("\nYour desired value from tree is to be deleted !!");
				display(root,1);
				break;
			case 9:exit(0);
				break;
			default:
				printf("\nWrong Choice !!");
			}
		printf("\nDo u want to try again then press 1 :");
		scanf("%d",&k);

		}while(k==1);
	getch();

	}
void ins(int item,node **ptr)
	{
	if((*ptr)==null)
		{
		(*ptr)=(node*)malloc(sizeof(node));
		(*ptr)->l=(*ptr)->r=null;
		(*ptr)->info=item;
		}
	else if(item<(*ptr)->info)
		ins(item,&((*ptr)->l));
	else
		ins(item,&((*ptr)->r));
	}

void display(node *ptr,int l)
	{
	int i;
	if(ptr)
		{
		display(ptr->r,l+1);
		printf("\n");
		for(i=0;i<l;i++)
			printf("  ");
		printf(" %d",ptr->info);
		display(ptr->l,l+1);
		}
	}
void preorder(node *ptr)
	{


	if(ptr)
		{
		printf(" %d",ptr->info);
		preorder(ptr->l);
		preorder(ptr->r);
		}
	}
void inorder(node *ptr)
	{

	if(ptr)
		{
		postorder(ptr->l);
		printf(" %d",ptr->info);
		postorder(ptr->r);
		}
	}
void postorder(node *ptr)
	{

	if(ptr)
		{
		preorder(ptr->l);
		preorder(ptr->r);
		printf(" %d",ptr->info);
		}
	}

void count_leaves(node *ptr)
	{
	if(ptr)
		{
		if((ptr->l==null)&&(ptr->r==null))
			leaves++;
		else
			{
		       count_leaves(ptr->l);
		       count_leaves(ptr->r);
		       }
		}

	}
void search(int item,node *ptr)
	{
	if(ptr==null)
		printf("\nElement is not found !!");
	else if(item<ptr->info)
		search(item,ptr->l);
	else if(item>ptr->info)
		search(item,ptr->r);
	else
		printf("\nElement is found");
	}
void del_node(int item,node **ptr)
	{
	node *save;
	if((*ptr)==null)
		printf("\nItem does not exists");
	else
		{
		if(item<(*ptr)->info)
			del_node(item,&((*ptr)->l));
		else if(item>(*ptr)->info)
			del_node(item,&((*ptr)->r));

		else if(item==(*ptr)->info)
			{
			save=*ptr;
			if(save->r==null)
				{
				*ptr=save->l;
				free(save);
				}
		       else if(save->l==null)
				{
				*ptr=save->r;
				free(save);
				}
		       else
				del(&(save->l),save);
			 }
		}
	}
void del(node **p,node *q)
	{
	node *delnode;
	if((*p)->r!=null)
		del(&((*p)->r),q);
	else
		{
		delnode=*p;
		q->info=(*p)->info;
		*p=(*p)->l;
		free(delnode);
		}
	}


