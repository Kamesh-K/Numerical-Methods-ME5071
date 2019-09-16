#include<bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)
using namespace std;
#define N_MAX 4
int forward_elim(int n, double a[][N_MAX], double b[], double x[])
{
	// Function to perform Forward Elimination
	int i,j,k;
	double x_mult;	// X Mult is the multiplication factor
	loop(k,0,n-1)
	{
		loop(i,k+1,n)
		{
			x_mult=a[i][k]/a[k][k];
			if(a[k][k]==0) x_mult=0;
			loop(j,k,n)
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
	loop(i,0,n)
	{
		loop(j,0,n)
			cout<<a[i][j]<<' ';
		cout<<'\n';
	}
}
int back_subs(int n, double a[][N_MAX], double b[], double x[])
{
	// Function to perform backward substitution
	int i,j,k;
	double sum=0;
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
void GaussElim(int n, double a[][N_MAX], double b[], double x[])
{
	pivoting(n,a,b);
	forward_elim(n,a,b,x);	// Forward Elimination
	back_subs(n,a,b,x);		// Backward Substitution
}
int main()
{
	// Initializing the required variables
	// Populating the A matrix
	double A[][N_MAX]={{0,2,-1,0},{1,-4,4,7},{2,1,1,4},{2,-3,2,-5}};
	// Populating B vector
	double b[]={5,4,2,9},x[N_MAX];
	int n=N_MAX;
	clock_t t1;
	t1=clock();
	int i,j,k;
	// Printing A matrix
	cout<<"Matrix A - \n";
	loop(i,0,n)
	{
		loop(j,0,n)
			cout<<A[i][j]<<' ';
		cout<<'\n';
	}
	// Printing B Vector
	cout<<"\nB Vector - \n";
	loop(i,0,n)
		cout<<b[i]<<' ';
	cout<<endl;
	GaussElim(n,A,b,x);
	cout<<endl;
	// Printing the transformed RHS
	cout<<"Transformed RHS : \n";
	loop(i,0,n)
		cout<<b[i]<<' ';
	cout<<'\n';
	// Printing the Result Matrix
	cout<<"\nResult Matrix X : \n";
	loop(i,0,n)
		cout<<x[i]<<' ';
	cout<<'\n';
	cout<<endl;
	clock_t t2;
	t2=clock();
	// Printing the time taken for the calculation
	cout<<"Total time taken : "<<t2-t1<<" microseconds"<<'\n';
return 0;
}
