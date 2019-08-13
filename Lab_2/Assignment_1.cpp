#include<bits/stdc++.h>
#define loo(i,a,b) for(i=a;i<b;i++)
using namespace std;
int forward_elim(int n, float a[][1024], float b[], float x[])
{
	int i,j,k;
	float x_mult;
	loo(k,0,n-1)
	{
		loo(i,k+1,n)
		{
			x_mult=a[i][k]/a[k][k];
			if(a[k][k]==0) x_mult=0;
		//	loo(j,0,k) a[i][j]=0;
			loo(j,k,n)
			{
				a[i][j]=a[i][j]-x_mult*a[k][j];
				if(abs(a[i][j])<pow(10,-5))
					a[i][j]=0;					
			}
			b[i]=b[i]-x_mult*b[k];
		}
	}
	cout<<"Matrix after forward substitution : \n";
	loo(i,0,n)
	{
		loo(j,0,n)
			cout<<a[i][j]<<' ';
		cout<<'\n';
	}
}
int back_subs(int n, float a[][1024], float b[], float x[])
{
	int i,j,k;
	float sum=0;
	loo(i,0,n)	
	if(a[i][i])
	x[i]=b[i]/a[i][i];
	for(i=n-2;i>=0;i--)
	{
		sum=x[i];
		for(j=i+1;j<n;j++)
		{
			sum=sum-a[i][j]*x[j];			
		}
		if(a[i][j]!=0)
		x[i]=sum/a[i][j];
	}
}
void GaussElim(int n, float a[][1024], float b[], float x[])
{
	int i,j,k;
	forward_elim(n,a,b,x);
	back_subs(n,a,b,x);
}
int main()
{
float A[1024][1024];
float b[1024],x[1024];
int n=10;
cout<<"Enter the maximum size: ";
cin>>n;
int i,j,k;
loo(i,0,n)
	loo(j,0,n)
		A[i][j]=rand()%17;
cout<<"Matrix A - \n"; 
loo(i,0,n)
{
	loo(j,0,n)
		cout<<A[i][j]<<' ';
	cout<<'\n';
}
cout<<"\nB Vector - \n";
loo(i,0,n)	
	b[i]=1.00;
loo(i,0,n)
	cout<<b[i]<<' ';
cout<<endl;
GaussElim(n,A,b,x);
cout<<endl;
cout<<"Result Matrix X : \n";
loo(i,0,n)
	cout<<x[i]<<' ';
cout<<'\n';
cout<<endl;
return 0;
}
