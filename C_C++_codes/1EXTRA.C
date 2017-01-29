#include<stdio.h>
#include<conio.h>
struct employee
{
	int eno;
	char name[20];
	char dept[10];
	char post[10];
	float salary;

}s[5];

void main()
{
  struct employee *ptr;
  int j;
  clrscr();
  for(j=0;j<5;j++)
  {
    printf("enter %d employee details::",j+1);
     printf("\nenter employee code::");
 scanf("%d",&s[j].eno);
  printf("\nenter employee name::");
 scanf("%s",&s[j].name);
  printf("\nenter employee department::");
 scanf("%s",&s[j].dept);
  printf("\nenter employee post::");
 scanf("%s",&s[j].post);
   printf("\nenter employee salary::");
 scanf("%f",&s[j].salary);
  }
for(j=0;j<5;j++)
{
ptr=&s[0];
printf("employee code of %d employee::",ptr->eno);



}

getch();
}