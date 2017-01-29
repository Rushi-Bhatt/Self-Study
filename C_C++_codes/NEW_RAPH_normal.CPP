#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream.h>
struct pol
{

int pow_x;
float coeff;

}t[8],c[8],d[8];

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

for(i=0;i<n;i++)
{

q=power(a,b[i].pow_x);
val=val+b[i].coeff*q;
}
return val;


}

void diff(struct pol b[],struct pol c[])
{
 for(i=0;i<n;i++)
 {
  c[i].coeff=b[i].coeff*(b[i].pow_x);
  if(b[i].pow_x==0)
  {

  c[i].pow_x=0;
  c[i].coeff=0;
  }
  else
  {
  c[i].pow_x=(b[i].pow_x)-1;
  }
 }


}

void main()
{
float x[100];
clrscr();
float ini=0,int1=0,int2=0;
float w=0,z=0,q=0;

clrscr();
cout<<"how many terms r der in your polynomial::";
cin>>n;
cout<<"enter your polynomial.....\n";
for(i=0;i<=n-1;i++)
{
printf("enter pow_x::\n");
cin>>t[i].pow_x;
printf("enter coeff::\n");
cin>>t[i].coeff;
}

printf("\npolynomial is:::::: ");
for(i=0;i<=n-1;i++)

{
printf("%fx^%d",t[i].coeff,t[i].pow_x);
printf("+");
}

cout<<"\nenter the val of xo initially::";
cin>>x[0];
ini=find_val(t,x[0]);
diff(t,c);

int1=find_val(c,x[0]);
diff(c,d);
int2=find_val(d,x[0]);

cout<<ini <<int1 <<int2;
w=ini*int2;
q=int1;

if(w<0)
{
 w=-w;
}
if(q<0)
{
 q=-q;
}
z=q*q;

if(w<z)
{

  cout<<"\nconvergent condition satisfied\n";
  int j=1;
  while(j<2000)
  {

     ini=find_val(t,x[j-1]);
     diff(t,c);

     int1=find_val(c,x[j-1]);
     diff(c,d);

     int2=find_val(d,x[j-1]);

     x[j]=x[j-1]-(ini/int1);
     float g=x[j]-x[j-1];
     if(g<0)
     {
      g=-g;
     }
     if(g<0.0001)
     {
      cout<<"\napprox root is:"<<x[j];
      break;
     }
     else
     {
      j++;
     }
  }

}
else
{

cout<<"\nenter some other val of xo which satisfy d convergent condition:::::";
exit(0);
}

getch();
}