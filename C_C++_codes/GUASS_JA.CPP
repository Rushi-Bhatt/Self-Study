#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<math.h>
#include<iostream.h>
float a[6][7],x[6][7],ans[10];
int n;
void main()
{

float t,u;
int i,j,k,c;
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

 float sum=0,tmp;
 for(k=0;k<n;k++)
 {
 for(int i=0;i<n;i++)
 {sum=0;
  for(j=0;j<n;j++)
  {
   if(k!=j)
   {
    sum=sum+fabs(a[i][j]);
   }
  }

   if(fabs(a[i][k])>sum)
   {
    for(j=0;j<=n;j++)
    {
     tmp=a[i][j];
     a[i][j]=a[k][j];
     a[k][j]=tmp;
    }
    goto A;
   }



 cout<<"\nThis equation cant be solved by this method";
 for(i=0;i<n;i++)
{
 cout<<"\n";
 for(j=0;j<n+1;j++)
 {
  cout<<a[i][j]<<" ";
 }

}

 getch();
 exit(0);
 A:
}
//printf("enter initial value of x,y,z:\n");
for(i=0;i<n;i++)
{
x[0][i]=0;
}
for(k=0;k<4000;k++)
{

for(j=0;j<n;j++)
{
	for(i=0;i<n;i++)
	{
		if(i!=j)
		{
		sum=sum+a[j][i]*x[k][i];
		x[k+1][j]=(a[j][n]-sum)/a[j][i];
		}
	}
}
		c=0;
	for(int z=0;z<n;z++)
	{
	if(fabs(x[k+1][z]-x[k][z])<0.0001)
	 {
	    c++;
	 }      }

	 if(c==n)
	 {
	  cout<<"task completed\n";
	  for(i=0;i<n;i++)
	  {
	  cout<<x<<"i"<<"="<<x[k+1][i];
	  }
	  break;
	 }
}
}
getch();

}