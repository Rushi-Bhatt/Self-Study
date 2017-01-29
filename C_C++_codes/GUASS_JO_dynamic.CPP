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

//MAKING ONLY DIAGONAL ELEMENTS
for(i=n-1;i>=0;i--)
{


		for(q=n-2;q>=0;q--)
		{
		  u=a[q][i];
		 for(k=i;k>0;k--)
		 {

		 a[q][k]=a[q][k]-(u*a[i][k]);


		 }

		}



} //comp of main for
disp();
cout<<"task completed\n";
for(i=0;i<n;i++)
{
  ans[i]=a[i][n];

}
cout<<"roots are:\n";
for(i=0;i<n;i++)
{
  cout<<"X"<<i<<"="<<ans[i]<<"\n";

}

getch();
}