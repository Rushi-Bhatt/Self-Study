#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10
int a[MAX][MAX],b[MAX],n,visited[MAX];

struct node1
{
	int data;
	struct node1 *link;
}*first1=NULL,*save1,*n1;

void input()
{
	int i,j;
	printf("\nEnter the no of nodes:");
	scanf("%d",&n);
	printf("\nEnter the nodes:");
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	printf("\nEnter the adjacency matrix:");
	for(i=0;i<n;i++)
	{
		printf("\nVertex %3d: ",b[i]);
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
}

void push1(int x)
{
	n1=(struct node1 *)malloc(sizeof(struct node1));
	n1->data=x;
	n1->link=NULL;
	if(first1==NULL)
	{
		first1=n1;
	}
	else
	{
		save1=first1;
		while(save1->link!=NULL)
			save1=save1->link;
		save1->link=n1;
	}
}

void traverse()
{
	int count,i,flag,j,check;
	count=0;
	flag=0;
	printf("\nEnter the source vertex no.(0..n-1):");
	scanf("%d",&i);
	printf("%d ",b[i]);
	visited[count]=b[i];
	count++;
	for(j=0;j<n;j++)
	{
		if(a[i][j]==1)
			push1(j);
	}
	while(first1!=NULL)
	{
		i=first1->data;
		first1=first1->link;
		flag=0;
		for(check=0;check<count;check++)
		{
			if(b[i]==visited[check])
				flag=1;
		}
		if(flag==0)
		{
			printf("%d ",b[i]);
			visited[count]=b[i];
			count++;
			for(j=0;j<n;j++)
			{
				if(a[i][j]==1)
					push1(j);
			}
		}
	}
}

void main()
{
	input();
	traverse();
	getch();
}