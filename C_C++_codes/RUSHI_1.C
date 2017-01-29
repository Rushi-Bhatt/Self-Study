#include<stdio.h>
#include<conio.h>
struct pol
{
int pow_x;
int coeff;

};
int n=0,i=0;
float pow(float x,int y)
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

q=pow(a,i);
val=val+b[i].coeff*q;
}
return val;


}


void main()
{


struct pol t[8];
float a=0,b=0,c=0,r=0,ctr=0;
float ans=0,w;

clrscr();
printf("how many terms r der in your polynomial::");
scanf("%d",&n);
printf("enter your polynomial.....\n");
for(i=0;i<=n-1;i++)
{
printf("enter pow_x::\n");
scanf("%d",&t[i].pow_x);
printf("enter coeff::\n");
scanf("%d",&t[i].coeff);
}

printf("\npolynomial is:::::: ");
for(i=0;i<=n-1;i++)

{
printf("%dx^%d",t[i].coeff,t[i].pow_x);
printf("+");
}

//ans=find_val(t,2);
//printf("\n ans is::%f",ans);
printf("\nfor finding a,b....");

if(find_val(t,0)==0)
{
printf("\none of the iz 0");

}
while(ctr==0)
{
if(find_val(t,r)>0);
{
a=r;
ctr=1;
break;

}

r=r+0.1;

}

ctr=0;

r=0;
while(ctr==0)
{
if(find_val(t,r)<0)
{
b=r;
ctr=1;
break;

}
else if(find_val(t,0)==0)
{
printf("\none root iz zero..");

}
r=r-0.1;
}
ctr=0;

printf("\n%f %f",a,b);
c=(a+b)/2;
w=find_val(t,c);
while(w!=0)
{


if(w>0)
{
 a=c;

}
if(w<0)
{
 b=c;
}
c=(a+b)/2;

if(ctr==1000)
{
 break;
}
ctr++;
}

printf("\n task complete...");
printf("\n root iz %f",c);
getch();
}

