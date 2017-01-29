#include<stdio.h>
#include<conio.h>
#include<process.h>
void main()
{

int a[5],i,temp,selection,t,c,tempf;
int top=0;
clrscr();
while(1)
{
	printf("enter which operation you want to perform::");
	printf("\nselect 1 for push operation:");
	printf("\nselect 2 for  pop operation:");
	printf("\nselect 3 for peep operation:");
	printf("\nselect 4 for change operation:");
	printf("\nselect 5 for display:");
	printf("\nselect 6 for exit:");
	scanf("%d",&selection);
		switch(selection)
		{
		case 1:
			clrscr();
			if(top>5)
			printf("\nstack overflow condition ;;;;");
			else
			{	printf("\nenter  element::");
				scanf("%d",&a[top]);
				top++;
			}
			break;
		case 2:
			clrscr();
			if(top==-1)
			printf("\nstack underflow condition ;;;;");
			else
			{	printf("\ndeleting the top most element::");
				top--;
			}


		break;
		case 3:
			clrscr();
			if(top==-1)
			printf("\nstack underflow condition ;;;;");
			else
			{
			printf("enter which element from the top u wanna search::");
			scanf("%d",&temp);
			t=top-temp+1;
			printf("the index is a[%d]",t);
			}
		break;


		case 4:
			clrscr();
			if(top==-1)
			printf("\nstack underflow condition ;;;;");
			else
			{
			printf("enter which element from the top u wanna change::");
			scanf("%d",&temp);
			printf("enter the new value::");
			scanf("%d",&c);
			t=top-temp;
			a[t]=c;
			printf("the value has been changed");
			}
			break;
		case 5 : clrscr();
			 tempf=top;
			 printf("\nthe final stack is::");
			 for(i=0;i<tempf;i++)
			 {
			  printf(" %d ",a[i]);
			 }
			  break;
		 case 6 : exit(0);



	default:
	printf("enter the valid choice please::");
	break;
      }

}




getch();
}