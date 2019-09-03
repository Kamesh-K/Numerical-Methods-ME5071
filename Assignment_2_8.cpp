#include<bits/stdc++.h>
#define loo(i,a,b) for(i=a;i<b;i++)
using namespace std;
int forward_elim(int n, float a[][1024], float b[], float x[])
{
	// Function to perform Forward Elimination	
	int i,j,k;
	float x_mult;	// X Mult is the multiplication factor
	loo(k,0,n-1)
	{
		loo(i,k+1,n)
		{
			x_mult=a[i][k]/a[k][k];
			if(a[k][k]==0) x_mult=0;
			loo(j,k,n)
			{
				a[i][j]=a[i][j]-x_mult*a[k][j];	// Substracting the rows to make the first element 0 
				if(abs(a[i][j])<pow(10,-5))
					a[i][j]=0;					
			}
			b[i]=b[i]-x_mult*b[k]; 	// Performing the same operation in b, RHS of equation
		}
	}
	// Printing the matrix after forward elimination 
	cout<<"\nMatrix after forward elimination : \n";
	loo(i,0,n)
	{
		loo(j,0,n)
			cout<<a[i][j]<<' ';
		cout<<'\n';
	}
}
int back_subs(int n, float a[][1024], float b[], float x[])
{
	// Function to perform backward substitution				
	int i,j,k;
	float sum=0;
	x[n-1]=b[n-1]/a[n-1][n-1]; // Initializing the last element directly 
	for(i=n-2;i>=0;i--)
	{
		sum=b[i];
		for(j=i+1;j<n;j++)
		{
			sum=sum-a[i][j]*x[j];	// Back-substituting the values to obtain X[i]					
		}
	x[i]=sum/a[i][i];	// Storing the values of X[i]
	}
}
void GaussElim(int n, float a[][1024], float b[], float x[])
{
	forward_elim(n,a,b,x);	// Forward Elimination
	back_subs(n,a,b,x);		// Backward Substitution
}
int main()
{
	// Initializing the required variables 	
	float A[1024][1024];
	float b[1024],x[1024];
	int n=10;
	cout<<"Enter the maximum size: ";
	cin>>n;
	clock_t t1;
	t1=clock();
	int i,j,k;
	// Populating the A matrix 
	loo(i,0,n)
		loo(j,0,n)
			A[i][j]=max(i+1,j+1);
	// Printing A matrix 
	cout<<"Matrix A - \n"; 
	loo(i,0,n)
	{
		loo(j,0,n)
			cout<<A[i][j]<<' ';
		cout<<'\n';
	}
	// Populating B vector
	loo(i,0,n)	
		b[i]=1.00;
	// Printing B Vector
	cout<<"\nB Vector - \n";
	loo(i,0,n)
		cout<<b[i]<<' ';	
	cout<<endl;
	GaussElim(n,A,b,x);
	cout<<endl;
	// Printing the transformed RHS 
	cout<<"Transformed RHS : \n";
	loo(i,0,n)
		cout<<b[i]<<' ';
	cout<<'\n';
	// Printing the Result Matrix 
	cout<<"\nResult Matrix X : \n";
	loo(i,0,n)
		cout<<x[i]<<' ';
	cout<<'\n';
	cout<<endl;
	clock_t t2;
	t2=clock();
	// Printing the time taken for the calculation
	cout<<"Total time taken : "<<t2-t1<<" microseconds"<<'\n';
return 0;
}
