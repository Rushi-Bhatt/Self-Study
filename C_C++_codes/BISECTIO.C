#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct pol
{

int pow_x;
float coeff;

}t[8];

int n,i;

float power(float x,int y)
{
int j;
float s=1;
 for(j=0;j<y;j++)
 {

  s=s*x;
 }
 return s;
}

float find_val(struct pol b[],float a)
{
float val=0;
float q=0;

for(i=0;i<=n;i++)
{

q=power(a,b[i].pow_x);
val=val+b[i].coeff*q;
}
return val;


}


void main()
{


float a=0,b=0,c=0,r=0,ctr=0;
float w=0;

clrscr();
cout<<"how many terms r der in your polynomial::";
cin>>n;
cout<<"enter your polynomial.....\n";
for(i=0;i<=n-1;i++)
{
printf("enter pow_x::\n");
scanf(" %d",&t[i].pow_x);
printf("enter coeff::\n");
scanf(" %f",&t[i].coeff);
}

printf("\npolynomial is:::::: ");
for(i=0;i<=n-1;i++)

{
printf("%fx^%d",t[i].coeff,t[i].pow_x);
printf("+");
}


printf("\nfor finding a,b....");

if(find_val(t,0)==0)
{
printf("\n one of the root iz 0");

}
while(r<=32767)
{
if(find_val(t,r)>0);
{
a=r;
//ctr=1;
goto Y;

}

r=r+0.1;

}

while(r>=-32767)
{
if(find_val(t,r)>0);
{
a=r;
//ctr=1;
goto Y;

}

r=r-0.1;

}

//ctr=0;
Y:
r=0;
while(r<=32767)
{
if(find_val(t,r)<0)
{
b=r;
//ctr=1;
goto Z;

}
r=r+0.1;
}
r=0;
while(r>=-32767)
{
if(find_val(t,r)<0)
{
b=r;
//ctr=1;
goto Z;

}
r=r-0.1;
}

Z:

printf("\n%f %f",a,b);
c=(a+b)/2;
w=find_val(t,c);
while(ctr<=32767)
{

if(find_val(t,c)==0)
 {
   break;
 }

if(w>0)
{
 a=c;

}
if(w<0)
{
 b=c;
}
c=(a+b)/2;


ctr++;
}

printf("\n task complete...");
printf("\napprox root iz %f",c);
getch();
}

