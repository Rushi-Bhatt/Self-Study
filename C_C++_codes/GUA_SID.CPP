#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
float a[100][101];
int n;
void out()
{
  for(int i=0;i<n;i++)
  {
   cout<<"\n";
   for(int j=0;j<=n;j++)
   {
    cout<<a[i][j]<<" ";
   }
  }
}
void main ()
{
 clrscr();
 cout<<"Input no of variables: ";
 cin>>n;
 for(int j=0;j<n;j++)
 {
   cout<<"\nEquation "<<j+1<<"\n";
   for(int i=0;i<n;i++)
   {
	cout<<"Input x"<<i+1<<" coeff : ";
	cin>>a[j][i];
   }
   cout<<"Input constant: ";
   cin>>a[j][i];
 }
 float sum=0,tmp;
 for(int k=0;k<n;k++)
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
 //  cout<<sum<<" ";
   if(fabs(a[k][i])>sum)
   {
    for(j=0;j<=n;j++)
    {
     tmp=a[i][j];
     a[i][j]=a[k][j];
     a[k][j]=tmp;
    }
    goto A;
   }
 }
 cout<<"\nThis equation cant be solved by this method";
 getch();
 exit(0);
 A:
 }

 double itr[100];
 out();
 int acc;
 for(int i=0;i<n;i++)
 {
  itr[i]=0;
 }
 cout<<"\nInput accuracy: ";
 cin>>acc;
 int test=1,tt,cnt=0;
 double ik;
 double t1,t2,fr;
 while(test==1)
{
  tt=0;
 for(int i=0;i<n;i++)
 {

  sum=0;
  for(j=0;j<n;j++)
  {
    if(i!=j)
    sum=sum+a[i][j]*itr[j];
  }
  ik=(a[i][n]-sum)/a[i][i];
  fr=modf(itr[i]*pow(10,acc),&t1);
  fr=modf(ik*pow(10,acc), &t2);
  if(fabs(t1)==fabs(t2))
  tt++;
  itr[i]=ik;
 }
 cnt++;
  if(tt==n)
  test=0;
}
 cout<<"\n"<<"No of iterations: "<<cnt;
 cout<<"\nAnswers:\n";
 for(i=0;i<n;i++)
 {
  fr=modf(itr[i]*pow(10,acc),&t1);

  cout<<"\nx"<<i+1<<": "<<t1/pow(10,acc);
 }

 getch();
}