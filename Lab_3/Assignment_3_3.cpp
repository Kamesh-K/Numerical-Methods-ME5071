#include <bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)
using namespace std;
#define N_MAX 4
void forward_subs(int n, double a[][N_MAX], double b[], double x[])
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
void back_subs(int n, double a[][N_MAX], double b[], double x[])
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
int ludecomp(double a[][N_MAX], double lower[][N_MAX], double upper[][N_MAX], double b[],double sol[],int n)
{
	// Function to perform LU Decomposition
	int i,j,k;
	double sum=0;
	loop(i,0,n)
		loop(j,0,n)
			{
			lower[i][j]=0;
			upper[i][j]=0;
			}
	// Initializing the matrices to be zero
	// Calculating the lower and upper matrices
    loop(i,0,n)
	{
        loop(k,i,n)
		{
		sum=0;
		loop(j,0,i)
                sum+=(lower[i][j]*upper[j][k]);
            upper[i][k]=a[i][k]-sum;
	        }
	loop(k,i,n)
		{
		    if (i == k)
		        lower[i][i] = 1; 	// Initialzing the diagonal of Lower matrix to be 1
		    else {
			sum=0;
			loop(j,0,i)
			    sum+=(lower[k][j]*upper[j][i]);
		        lower[k][i]=(a[k][i]-sum)/upper[i][i];
		    }
		}
	}
	// Printing the upper triangular matrix
	cout<<"\nUpper triangular matrix : \n";
	loop(i,0,n)
	{
		loop(j,0,n)
			cout<<upper[i][j]<<' ';
		cout<<'\n';
	}
	// Printing the lower triangular matrix
	cout<<"\nLower triangular matrix : \n";
	loop(i,0,n)
	{
		loop(j,0,n)
			cout<<lower[i][j]<<' ';
		cout<<'\n';
	}
	// Finding the inverse of the matrix using LU Decomposition
 	double Identity[N_MAX][N_MAX];
	loop(i,0,n)
	{
		loop(j,0,n)
			{
			if(i==j)
				Identity[i][j]=1;
			else
				Identity[i][j]=0;
			}
	}
	int x;
	double col[n],val[n],temp_sol[n];
	// The idea is obtain the A inverse row wise and final construct the A inverse matrix
	// Forward substitution is performed on Lower matrix and backward substitution is performed on upper matrix
	// A inverse matrix is constructed from the back substitution
	forward_subs(n,lower,b,temp_sol);
	back_subs(n,upper,temp_sol,sol);
	cout<<"The solutions for the given system - \n";
	loop(i,0,n)
		cout<<sol[i]<<'\n';
}
double function_x(float x)
{
	return (double) sin(5*x)
}
void mat_pop(int n,double a[][N_MAX],double b[])
{
	int i,j,k;
// Populating the A matrix
// Initialzing all the values to zero
	loop(i,0,n)
		loop(j,0,n)
			a[i][j]=0;
	// Initialzing the diagonal and off diagonal elements
	loop(i,1,n-1)
		{
			a[i][i-1]=1;
			a[i][i]=4;
			a[i][i+1]=1;
		}
	// Boundary values for i=0 and i=N-1
	a[0][0]=1;
	a[0][1]=2;
	a[n-1][n-1]=1;
	a[n-1][n-2]=2;

	// Populating the B matrix
	loop(i,1,n-1)
	{
		b[i]=n*(function_x((double)3.0*(i+1)/n)-function_x((double)3.0*(i-1)/n));
	}
	// Boundary values for i=0 and i=N-1
	b[0]=(n*(-2.5*function_x(0)+2*function_x((double)3*1/n))+0.5*function_x(3*2/n)/3);
	b[n-1]=(n*(2.5*function_x(1)-2*function_x((double)3*1/n))-0.5*function_x(3*(n-2)/n)/3))
	// Printing the value of A and B matrix
}
int main()
{
int n,i,j,k;
double a[N_MAX][N_MAX],b[N_MAX],x[N_MAX];
n=N_MAX;
mat_pop(n,a,b);
cout<<"\nThe matrix A is : \n";
loop(i,0,n)
	{
	loop(j,0,n)
		cout<<a[i][j]<<' ';
	cout<<'\n';
	}
loop(i,0,n)
		b[i]=1;
cout << "Given B vector - " << '\n';
loop(i,0,n)
	cout<<b[i]<<' ';
cout<<'\n';
double lower[N_MAX][N_MAX],upper[N_MAX][N_MAX];
ludecomp(a,lower,upper,b,x,N_MAX);
return 0;
}
