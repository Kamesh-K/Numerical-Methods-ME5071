#include<bits/stdc++.h>
#define loo(i,a,b) for(i=a;i<b;i++)
using namespace std;
/*
	Code to prove that the transpose of a matrix on added to itself will yield a symmetric matrix 
	Matrix A is initialized and the transpose is shown as ouput 
	The Sum of the two matrices is displayed and the matrix is proven to be symmetric
	Command to execute and run - 
	g++ Assignment_2.cpp -o as2.out && ./as2.out	
*/
int main()
{
	int n;
// 	Obtaining the input for calculation 
	cout<<"Enter the Number N : ";
	cin>>n;
// 	Declaration of variables 
	int a[n][n],b[n][n],c[n][n],i,j,k;
// 	Population of the Matrix A 
	loo(i,0,n)
		loo(j,0,n)
			a[i][j]=rand()%10;
// 	Displaying Matrix A 
	cout<<"Matrix A : \n";
	loo(i,0,n)
	{
		loo(j,0,n)
		{
			cout<<a[i][j]<<' ';
		}
		cout<<'\n';
	}
// 	Displaying the transpose of Matrix A 
	cout<<"Matrix A Transpose : \n";
	loo(i,0,n)
	{
		loo(j,0,n)
		{
			cout<<a[j][i]<<' ';
		}
		cout<<'\n';
	}
// 	Calculating the sum of matrix A and matrix A transpose 
	loo(i,0,n)
	{
		loo(j,0,n)
		{
		c[i][j]=a[i][j]+a[j][i];
		}
	}
// 	Displaying the transpose of Matrix A + Matrix A  
	cout<<"The matrix A + A Transpose : \n";
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
