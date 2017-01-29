#include<stdio.h>
#include<conio.h>
#include<iostream.h>
void main()
{

float a[3][4],t,u;
int i,j,k,x,y,z;
clrscr();
cout<<"enter the augumented matrix: row wise:\n";
for(i=0;i<=2;i++)
{
  for(j=0;j<=3;j++)
  {
   cin>>a[i][j];

  }

}

cout<<"you have entered:\n";

for(i=0;i<=2;i++)
{
  for(j=0;j<=3;j++)
  {
   cout<<a[i][j]<<"   ";
  }
cout<<"\n";
}
t=a[0][0];
//making a11=1

for(k=0;k<=3;k++)
{
 a[0][k]=a[0][k]/t;
}

 //making 2 and 3 rd row first column 0

for(i=1;i<=2;i++)
{
 u=a[i][0];
 for(j=0;j<=3;j++)
 {
 a[i][j]=a[i][j]-(u*a[0][j]);
 }
}

cout<<"\n";



for(i=0;i<=2;i++)
{
  for(j=0;j<=3;j++)
  {
   cout<<a[i][j]<<"   ";
  }
cout<<"\n";
}



//making a22 =1
t=a[1][1];

for(k=0;k<=3;k++)
{
 a[1][k]=a[1][k]/t;
}

//making a23=0


 u=a[2][1];
 for(j=0;j<=3;j++)
 {
 a[2][j]=a[2][j]-(u*a[1][j]);
 }
cout<<"\n";


for(i=0;i<=2;i++)
{
  for(j=0;j<=3;j++)
  {
   cout<<a[i][j]<<"   ";
  }
cout<<"\n";
}

//making a22=1

t=a[2][2];

for(k=0;k<=3;k++)
{
 a[2][k]=a[2][k]/t;
}


cout<<"\n";
for(i=0;i<=2;i++)
{
  for(j=0;j<=3;j++)
  {
   cout<<a[i][j]<<"   ";
  }
cout<<"\n";
}

cout<<"task completed";
z=a[2][3];
y=a[1][3]-(a[1][2]*z);
x=a[0][3]-(a[0][2]*z)-(a[0][1]*y);
cout<<"roots are\n";
cout<<"x:"<<x<<"\n";
cout<<"y:"<<y<<"\n";
cout<<"z:"<<z<<"\n";
getch();
}