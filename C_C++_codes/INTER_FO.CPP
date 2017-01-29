#include<iostream.h>
#include<conio.h>
#include<math.h>

 fact(int y)
 {
  if(y==0)
  {
   return 1;
  }
  else return y*fact(y-1);
 }
 void main()
 {
 clrscr();
 float mat[10][10];
 int i,j,k,freq;
  cout<<"enter the no. of frequencies:";
  cin>>freq;

  cout<<"enter values of x and y:\n";

   for(i=0;i<freq;i++)
   {
    for(j=0;j<2;j++)
    {
     cin>>mat[i][j];

    }
   }



   //finding differences

  for(j=2;j<=freq;j++)
  {

   for(i=0;i<=freq-j;i++)
   {
    mat[i][j]=(mat[i+1][j-1])-(mat[i][j-1]);

   }
  }
  for(i=0;i<freq;i++)
  {
   cout<<"\n";
   for(j=0;j<=freq-i;j++)
   {
    cout<<mat[i][j]<<" ";
   }
  }




     float p,x,h;
     h=mat[1][0]-mat[0][0];
     cout<<"\n enter the x for which you want y::";
     cin>>x;
     p=(x-mat[0][0])/h;


     float y,mul,mul2,sum;
     int d=1;
     mul=1;
     sum=0;



	for(i=0;i<freq-2;i++)
	 {
	   mul=(p-i)*mul;
	   //cout<<mul<<" ";
	   mul2=(mul*mat[0][i+2])/fact(i+1);
	   //cout<<mul2<<" ";
	   sum=mul2+sum;
	 }
       y=mat[0][1]+sum;
      cout<<"\n"<<y;


 getch();

 }






























