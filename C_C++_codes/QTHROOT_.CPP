#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream.h>
struct pol
{

int pow_x;
float coeff;

}t[8],c[8],d[8];

int n=2,i;

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
float Q;
int nr;
clrscr();
float ini=0,int1=0,int2=0;
float w=0,z=0,q=0;
int k=0;

clrscr();
cout<<"enter the value of Q:";
cin>>Q;
cout<<"\nenter the value of n so dat it will find nth root::\n";
cin>>nr;


t[0].coeff=1;
t[0].pow_x=nr;
t[1].coeff=-Q;
t[1].pow_x=0;



printf("\npolynomial is:::::: ");
for(i=0;i<=n-1;i++)

{
printf("%fx^%d",t[i].coeff,t[i].pow_x);
printf("+");
}

while(find_val(t,k)<=0)
{

k++;
}
x[0]=k;
cout<<"\nx0 is :"<<x[0]<<".\n";
ini=find_val(t,x[0]);
diff(t,c);

int1=find_val(c,x[0]);
diff(c,d);
int2=find_val(d,x[0]);

cout<<"\nf[x]="<<ini<<", "<<"f1[x]="<<int1<<" ,"<<"f2[x]="<<int2<<".";
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
      cout<<"\n"<<x[j]<<" is the "<<nr<<" th root of "<<Q<<".";
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

cout<<"\nenter some other val of xo which satisfy d convergent condition:::::try nxt time.";
exit(0);
}

getch();
}