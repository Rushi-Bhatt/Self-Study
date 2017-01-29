#include<stdio.h>
#include<conio.h>
#include<iostream.h>
float a[6][7],ans[10];
int n;
void disp()
{
int i,j;

 cout<<"\n";

for(i=0;i<n;i++)
{
  for(j=0;j<n+1;j++)
  {
   cout<<a[i][j]<<"    ";
  }
cout<<"\n";
}


}
void main()
{

float t,u;
int i,j,k,x,y,z,q;
clrscr();
cout<<"enter how many elements r there in ur equation::\n";
cin>>n;
cout<<"enter the augumented matrix: row wise:\n";
for(i=0;i<n;i++)
{
  for(j=0;j<n+1;j++)
  {
   cin>>a[i][j];

  }

}

cout<<"you have entered:\n";
disp();
for(i=0;i<n;i++)//making a[n][n]=1
{

	t=a[i][i];

	for(k=0;k<n+1;k++)
	{
	a[i][k]=a[i][k]/t;
	}

		for(q=i+1;q<n;q++)
		{
		  u=a[q][i];
		 for(k=i;k<n+1;k++)
		 {

		 a[q][k]=a[q][k]-(u*a[i][k]);

		 }

		}



} //comp of main for
disp();


cout<<"task completed";
 for(i=0;i<n;i++)
 {
  ans[i]=a[i][n];
 }
 for(i=n-2;i>=0;i--)
 {
  for(j=i+1;j<n;j++)
  {
   ans[i]=ans[i]-(a[i][j]*ans[j]);
  }
 }
 cout<<"\n\n ans is ::\n";
 for(i=0;i<n;i++)
 {

  cout<<"x"<<i+1<<"::"<<ans[i]<<"\n";
 }


getch();
}