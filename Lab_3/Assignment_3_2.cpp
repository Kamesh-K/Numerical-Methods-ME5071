#include <bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)
using namespace std;
#define N_MAX 60
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
void pivoting(int n, double a[][N_MAX],double b[])
{
	int flag=1,i,j,k,max_indx;
	double temp,max_val;
	// The function swaps the rows suitably so that the final matrix has a[i][i] as the maximum value in the i-th row
	loop(i,0,n-1)
	{
		// Initializing the initial values for maximum index and its corresponding value
	    max_indx=i;
	    max_val=abs(a[i][i]);
		// Finding the index of the maximum value element
		loop(j,i+1,n)
		{
			if(abs(a[j][i])>max_val)
			{
				// Changing the max_indx and max_val if some other element is greater than a[i][i]
				max_indx=j;
				max_val=abs(a[j][i]);
			}
		}
		// Checking whether the a[i][i] is the maximum or not, if not swap it with the maximum
    if(max_indx!=i)
    {
		// Swapping of i-th and max_indx row
		// Corresponding changes are made in the b vector as well
 		loop(k,0,n)
		{
			temp=a[max_indx][k];
			a[max_indx][k]=a[i][k];
			a[i][k]=temp;
		}
		temp=b[max_indx];
		b[max_indx]=b[i];
		b[i]=temp;
    }
	}
	// Printing the pivoted A matrix
	cout<<"Pivoted Matrix A - \n";
	loop(i,0,n)
	{
		loop(j,0,n)
			cout<<a[i][j]<<' ';
		cout<<'\n';
	}
	cout<<"\nPivoted B Vector - \n";
	loop(i,0,n)
		cout<<b[i]<<' ';
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
	pivoting(n,a,b);
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
int main()
{
int n,i,j,k;
n=N_MAX;
double a[N_MAX][N_MAX],b[N_MAX],x[N_MAX];
loop(i,0,N_MAX)
	loop(j,0,N_MAX)
	{
		if (j==n-1 || i==j)
		a[i][j]=1; 	
		else if(i>j)
			a[i][j]=-1;
		else 
		a[i][j]=0;
	}
cout<<"\nThe given matrix is : \n";
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
cout<<"Growth factor : "<<upper[n-1][n-1]<<'\n';
return 0;
}
