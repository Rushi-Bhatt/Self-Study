#include<stdio.h>
#include<conio.h>
#include<malloc.h>

typedef struct bst
{
 int info;
 int height;
 struct bst *left;
 struct bst *right;
}NODE;

typedef NODE* ROOT;

int set_height(ROOT r)
{
 int left_h = -1;
 int right_h = -1;
 if(r->left)
  left_h = r->left->height;
 if(r->right)
  right_h = r->right->height;
 if(left_h >= right_h)
  r->height = left_h+1;
 else
  r->height = right_h+1;
 return r->height;
}


int compare(int data1, int data2)
{
 if(data1<data2)
  return -1;
 if(data1>data2)
  return 1;
 else
  return 0;
}


//Doing Left-Left rotation
void rotate_LL(ROOT *r)
{
 NODE *r1, *r2 = *r,*t1,*t2,*t3;

 r1 = r2->left;
 t1 = r1->left;
 t2 = r1->right;
 t3 = r2->right;


 r1->right = r2;
 r2->left = t2;


 set_height(r1);
 set_height(r2);

 *r = r1;
}


//Doing Right-Left rotation

void rotate_RL(ROOT *r)
{
 NODE *r1,*r2, *r3=*r,*t1,*t2,*t3,*t4;

 r1 = r3->left;
 r2 = r1->right;
 t2 = r2->left;
 t3 = r2->right;


 r1->right = t2;
 r3->left = t3;
 r2->left = r1;
 r2->right = r3;


 set_height(r1);
 set_height(r2);
 set_height(r3);

 *r = r2;
}


//Doing Left-Right rotation
void rotate_LR(ROOT *r)
{
 NODE *r1=*r, *r2,*r3,*t1,*t2,*t3,*t4;

 r3 = r1->right;
 r2 = r3->left;
 t2 = r2->left;
 t3 = r2->right;


    r1->right = t2;
    r3->left = t3;
    r2->left = r1;
    r2->right = r3;


    set_height(r1);
    set_height(r2);
    set_height(r3);

    *r = r2;
}


//Doing Right-Right rotation
void rotate_RR(ROOT *r)
{
 NODE *r1=*r,*r2,*t1,*t2,*t3;

 r2 = r1->right;
 t1 = r1->left;
 t2 = r2->left;
 t3 = r2->right;


 r1->right = t2;
 r2->left = r1;

 set_height(r1);
 set_height(r2);

 *r = r2;
}


int find_rotation_type(int parent_data, int child_data, int data)
{
 if(compare(data, parent_data)<0) // inserting left
 {
  if(compare(data, child_data)<0)
   return 1;
  else if(compare(data, child_data)==0)
   return 0;
  else
   return 2;

 }
 else //inserting right
 {
  if(compare(data, child_data)>0)
   return 4;
  else if(compare(data, child_data)==0)
   return 0;
  else
   return 3;
 }
}


void do_rotation(ROOT *r, int rotation_type)
{
 if(rotation_type == 1)
  rotate_LL(r);
 else if(rotation_type == 2)
  rotate_RL(r);
 else if(rotation_type == 3)
  rotate_LR(r);
 else if(rotation_type == 4)
  rotate_RR(r);
 else
  printf("invalid rotation type \n");
}

int insert(ROOT *r, int data)
{
 NODE *new_node, *root = *r;
 int left_h = -1, right_h = -1;
 int diff,rotation_type;

 //tree is empty
 if(root == NULL)
 {
  new_node = (NODE *)malloc(sizeof(NODE));
  new_node->info = data;
  new_node->height = 0;
  new_node->left = new_node->right = NULL;
  *r = new_node;
  return 0;
 }
 if(root->left)
  left_h = root->left->height;
 if(root->right)
  right_h = root->right->height;

 if(compare(data, root->info)<0)
 {
  left_h = insert(&(root->left), data);
  rotation_type = find_rotation_type(root->info, root->left->info, data);
 }
 else if(compare(data, root->info)>0)
 {
  right_h = insert(&(root->right), data);
  rotation_type = find_rotation_type(root->info, root->right->info, data);
 }
 else
 {
    printf("Value repeated");
    return -1;
 }

 diff = left_h-right_h;
 if(diff>1 || diff<-1)
 {
	printf("Tree is Un-Balanced at node data %d ", root->info);
	if(rotation_type == 1)
	    printf("need to do LL rotation\n");
	if(rotation_type == 2)
	    printf("need to do RL rotation\n");
	if(rotation_type == 3)
	    printf("need to do LR rotation\n");
	if(rotation_type == 4)
	    printf("need to do RR rotation\n");
	//this call is for doing rotation
	do_rotation(r,rotation_type);
	printf("rotation done successfully\n");
  root = *r;
 }
 //set the height for the node and return the height
 return set_height(root);
}



void print_inorder(NODE *root)
{
 NODE *temp = root;
 if(temp)
 {
  print_inorder(temp->left);
  printf("%d ",temp->info);
  print_inorder(temp->right);
 }
}


int main()
{
 ROOT r = NULL;
 int i,num,data,choice;
 clrscr();
 printf("enter the no. of elements\n");
 scanf("%d",&num);
 printf("Enter the elements\n");
 for(i=0;i<num;i++)
 {
  scanf("%d",&data);
  insert(&r,data);
 }
 printf("1.Insert\n2.In-order\n3.Height of the tree\n4.exit\n");
 printf("Enter the choice\n");
 scanf("%d",&choice);
 while(1)
 {
  switch(choice)
  {
   case 1:
     printf("Enter the element\n");
     scanf("%d",&data);
     insert(&r,data);
     break;
   case 2:
     printf("Inorder is \n ");
     print_inorder(r);
     printf("\n");
     break;
   case 3:
     //height of the root node height is heoght of the tree
     printf("\nHeight of the tree is %d\n",r->height);
     break;
   case 4:
     return 0;
     break;
  }
  printf("1.Insert\n2.Inorder\n3.Height of the tree\n 4.exit\n");
  printf("Enter the choice\n");
  scanf("%d",&choice);
 }
 getch();
}