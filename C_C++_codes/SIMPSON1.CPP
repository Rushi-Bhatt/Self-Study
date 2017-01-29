#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
void main()
{


float x[100],y[100],h,ll,ul,sum1=0,sum2=0,ans;
int t,i,n;
clrscr();
cout<<"\nenter how many entries u want:";
cin>>t;
cout<<"\nenter x and y=f(x) respectively";
for(i=0;i<t;i++)
{

 cin>>x[i]>>y[i];

}
h=x[1]-x[0];
cout<<"\nstep size:"<<h;
cout<<"\nenter lower and higher limits::";
cin>>ll>>ul;
n=(x[ul]-x[ll])/h;
if((n%2)!=0)
 {
  cout<<"cant be done with simpsons 1/3 method";
  exit(0);

 }


for(i=ll+1;i<ul;i++)
{
if(i%2==0)
sum1=sum1+y[i];
else
sum2=sum2+y[i];

}
cout<<"sum1 is:"<<sum1<<"\n";
cout<<"sum2 is:"<<sum2<<"\n";

ans=h*(((y[ll]+y[ul])+2*sum1+4*sum2))/3;
cout<<"ans is:"<<ans;

 getch();
}




