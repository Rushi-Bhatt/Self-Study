#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
char infix[20],postfix[20],stack[20];
int top=-1,t;
int psd(char ch);
char pop();
char topel();
void push(char ch)
{
      top++;
      stack[top]=ch;
}
int braces(char *);
void main()
{
	char ele,element,st[2];
	int pret,pre,popped,j=0,chk=0;
	strcpy(postfix," ");
	clrscr();
	printf("Enter the infix expression:\n");
	gets(infix);
	chk=braces(infix);
	int i=0,t=0;
	while(infix[i]!='\0')
	    {

		 if(infix[i]=='+'|| infix[i]=='*'|| infix[i]=='-'|| infix[i]=='/' )
		    t=t+(-1);
		 else
		     if(infix[i]>=65 && infix[i]<=122 )
		       t=t+1;
		 i++;
	    }

	if(t!=1)
	   chk=1;

	if(chk!=0)
	{
		printf("Invalid expression\n");

	getch();
	exit(1);
	}
	for(i=0;infix[i]!='\0';i++)
	{
		if(infix[i]!='(' && infix[i]!=')' && infix[i]!='^' && infix[i]!='*'
		  &&infix[i]!='/' && infix[i]!='+' &&infix[i]!='-')
			postfix[j++]=infix[i];
		else if(infix[i]=='(')
		{
			element=infix[i];
			push(element);
		}
		else if(infix[i]==')')
		{
			while((popped=pop())!='(')
			{
				postfix[j++]=popped;
			}
		}
		else
		{
			element=infix[i];
			pre=psd(element);
			ele=topel();
			pret=psd(ele);
			if(pre>pret)
			{
				push(element);
			}
			else
			{
				while(pret>=pre)
				{
					if(ele=='#') break;
					popped=pop();
					ele=topel();
					postfix[j]=popped;
					j++;
					pret=psd(ele);

				}
				push(element);
			}
		}
	}
	while((popped=pop())!='#')
	{
	postfix[j]=popped;
	j++;
	postfix[j]='\0';
	}
	printf("\nPostfix Expession : %s\n",postfix);
	getch();


}
int psd(char ch)
{
	switch(ch)
	{
		case '^':	return 3;
		case '/':	return 2;
		case '*':	return 2;
		case '+':	return 1;
		case '-':	return 1;
		default:	return 0;
	}

}
 char pop()
 {
	char ch;

	if(top!=-1)
	{
		ch=stack[top];
		top--;
		return ch;
	}
	else
		return '#';
 }

 char topel()
 {
	char ch;
	if(top!= -1)
	{
		ch=stack[top];
	}

	else
	ch='#';
	return ch;
 }
 int braces(char *s)
 {
	int leftbr,rightbr;
	leftbr=rightbr=0;
	for(int i=0;s[i];i++)
	{
		if(s[i]=='(')
		leftbr++;
		else if(s[i]==')')
		rightbr++;
	}
	if(leftbr==rightbr)
	   return 0;
	else
	     if(leftbr<rightbr)
		return 1;
	     else
		return -1;
 }


