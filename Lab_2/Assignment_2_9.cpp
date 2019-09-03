#include <bits/stdc++.h>
#define loo(i,a,b) for(i=a;i<b;i++) 
using namespace std; 
void forward_subs(int n, double a[][4], double b[], double x[])
{
	// Function to do forward subsitution
	float sum=0;
	int i,j,k;
	x[0]=b[0]/a[0][0];
	for(i=1;i<n;i++)
	{
		sum=b[i];
		for(j=0;j<i;j++)
		{
			sum=sum-a[i][j]*x[j];
		}
		x[i]=sum/a[i][i];
	}
}
void back_subs(int n, double a[][4], double b[], double x[])
{
	// Function to do backward substitution
	int i,j;
	double sum=0;
	x[n-1]=b[n-1]/a[n-1][n-1];
	for(i=n-2;i>=0;i--)
	{
		sum=b[i];
		for(j=i+1;j<n;j++)
		{
			sum=sum-a[i][j]*x[j];								
		}
	x[i]=sum/a[i][i];
	}
} 

int ludecomp(double a[][4], double lower[][4], double upper[][4],int n) 
{ 
	// Function to perform LU Decomposition
	int i,j,k;
	double sum=0;
	loo(i,0,n)
		loo(j,0,n)
			{
			lower[i][j]=0;
			upper[i][j]=0;			
			}
	// Initializing the matrices to be zero 
	// Calculating the lower and upper matrices 
    loo(i,0,n)
	{ 
        loo(k,i,n)
		{ 
		sum=0;            
		loo(j,0,i)
                sum+=(lower[i][j]*upper[j][k]); 	
            upper[i][k]=a[i][k]-sum; 
	        } 
	loo(k,i,n)
		{ 
		    if (i == k) 
		        lower[i][i] = 1; 	// Initialzing the diagonal of Lower matrix to be 1 
		    else { 
			sum=0;
			loo(j,0,i)                
			    sum+=(lower[k][j]*upper[j][i]); 
		        lower[k][i]=(a[k][i]-sum)/upper[i][i]; 
		    } 
		} 
	}
	// Printing the upper triangular matrix 
	cout<<"\nUpper triangular matrix : \n";
	loo(i,0,n)
	{
		loo(j,0,n)
			cout<<upper[i][j]<<' ';
		cout<<'\n';
	}
	// Printing the lower triangular matrix 
	cout<<"\nLower triangular matrix : \n";
	loo(i,0,n)
	{
		loo(j,0,n)
			cout<<lower[i][j]<<' ';
		cout<<'\n';
	}
	// Finding the inverse of the matrix using LU Decomposition
 	double Identity[4][4];
	loo(i,0,n)
	{
		loo(j,0,n)
			{
			if(i==j)
				Identity[i][j]=1;
			else
				Identity[i][j]=0; 
			}
	}
	int x;
	double b[n],col[n],val[n];
	double inverse[4][4];
	// The idea is obtain the A inverse row wise and final construct the A inverse matrix 
	// Forward substitution is performed on Lower matrix and backward substitution is performed on upper matrix
	// A inverse matrix is constructed from the back substitution  
	loo(x,0,n)
	{
		loo(i,0,n)
			b[i]=Identity[x][i];
		forward_subs(4,lower,b,col);
		back_subs(4,upper,col,val);
		loo(i,0,n)
			inverse[i][x]=val[i];
	}
	// Printing the Inverse Matrix 
	cout<<"\nInverse matrix : \n";
	loo(i,0,n)
	{
		loo(j,0,n)
			cout<<inverse[i][j]<<' ';
		cout<<'\n';
	}
	cout<<'\n';
}
int main() 
{ 
int n,i,j,k;
n=4;
double a[4][4]={{3,2,1,5},{2,3,2,7},{1,2,2,6},{4,5,6,5}};
cout<<"\nThe given matrix is : \n";
loo(i,0,n)
	{
	loo(j,0,n)
		cout<<a[i][j]<<' ';
	cout<<'\n';	
	}
double lower[4][4],upper[4][4];
ludecomp(a,lower,upper,4); 
return 0; 
}