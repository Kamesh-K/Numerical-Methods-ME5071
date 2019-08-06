#include<bits/stdc++.h>
#define loo(i,a,b) for(i=a;i<b;i++)
using namespace std;
/* 	Code to explain the non-commutative property of matrices 
	Two matrices A and B are generated randomly 
	And the multiplication of A * B and B * A is calculated 
	The computed matrix is shown as output and we infer that multiplication is not commutative 
	Command to execute and run the code - 
	g++ Assignment_1.cpp -o a.out && ./a.out 
*/
int main()
{
	int n;
// 	Getting the input value of N 
	cout<<"Enter the Number N : ";
	cin>>n;
	int a[n][n],b[n][n],c[n][n],i,j,k;
// 	Populating the Matrix A 
	loo(i,0,n)
		loo(j,0,n)
			a[i][j]=rand()%10;
// 	Populating the Matrix B 
	loo(i,0,n)
		loo(j,0,n)
			b[i][j]=rand()%10;
// 	Output the generated matrix A 	
	cout<<"Matrix A : \n";
	loo(i,0,n)
	{
		loo(j,0,n)
		{
			cout<<a[i][j]<<' ';
		}
		cout<<'\n';
	}
//	Output the generated matrix B
	cout<<"Matrix B : \n";
	loo(i,0,n)
	{
		loo(j,0,n)
		{
			cout<<b[i][j]<<' ';
		}
		cout<<'\n';
	}
//	Computing the matrix multiplication 
	loo(i,0,n)
	{
		loo(j,0,n)
		{
		c[i][j]=0;
			loo(k,0,n)
			{
				c[i][j]+=a[i][k]*b[k][j]; // Matrix multiplication
			}
		}
	}
//	Output the generated matrix A * B 
	cout<<"The matrix A*B : \n";
	loo(i,0,n)
	{
		loo(j,0,n)
		{
			cout<<c[i][j]<<' ';
		}
		cout<<'\n';
	}

	loo(i,0,n)
	{
		loo(j,0,n)
		{
		c[i][j]=0;
			loo(k,0,n)
			{
				c[i][j]+=b[i][k]*a[k][j];
			}
		}
	}

// 	Output the generated matrix B * A 
	cout<<"The matrix B*A : \n";

	loo(i,0,n)
	{
		loo(j,0,n)
		{
			cout<<c[i][j]<<' ';
		}
		cout<<'\n';
	}
return 0;
}
