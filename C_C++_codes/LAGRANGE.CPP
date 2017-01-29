#include<conio.h>
#include<stdio.h>
#include<iostream.h>

void main()
{
	float x[50];
	float sum=0;
	float z,i,j,f,a;
	float y[50];
	float mul=1,mul2=1;
	cout<<"enter the frequency:";
	cin>>f;
	cout<<"enter the values of x:";
	for(i=0;i<f;i++)
	{
		cin>>x[i];
	}
	cout<<"enter the values of y:";
	for(i=0;i<f;i++)
	{
		cin>>y[i];
	}
for(i=0;i<f;i++)
	{
		cout<<x[i]<<" "<<y[i]<<"\n";
	}

cout<<"Enter the value of x:";
cin>>a;

for(i=0;i<f;i++)
{
	mul=mul2=1;
	for(j=0;j<f;j++)
	{
		if(i!=j)
		{
			mul=(a-x[j])*mul;
			mul2=(x[i]-x[j])*mul2;
		}

	}
	z=mul/mul2;
	sum=sum+(z*y[i]);
}
cout<<sum;

getch();
}