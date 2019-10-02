#include<bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)
#define iter_max 20
#define N_MAX 3
using namespace std;
int jacobian(double x, double y, double z, double jacobi[3][3])
{
  jacobi[0][0]=1;
  jacobi[0][1]=1;
  jacobi[0][2]=1;
  jacobi[1][0]=2*x;
  jacobi[1][1]=2*y;
  jacobi[1][2]=2*z;
  jacobi[2][0]=exp(x)+y-z;
  jacobi[2][1]=x;
  jacobi[2][2]=-1*x;
}
int f_val(double x, double y, double z, double fval[3])
{
  fval[0]=x+y+z-3;
  fval[1]=x*x+y*y+z*z-5;
  fval[2]=exp(x)+x*y-x*z-1;
}
void mat_mult(double a[][N_MAX], double b[N_MAX], double c[N_MAX], int n)
{
  int i,j;
  loop(i,0,n)
    c[i]=0;
  loop(i,0,n)
  {
    loop(j,0,n)
    c[i]+=a[i][j]*b[j];
  }
}
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

int ludecomp(double a[][N_MAX], double inverse[][N_MAX],int n)
{
	// Function to perform LU Decomposition
  double lower[3][3],upper[3][3];
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
	/*cout<<"\nUpper triangular matrix : \n";
	loop(i,0,n)
	{
		loop(j,0,n)
			cout<<upper[i][j]<<' ';
		cout<<'\n';
	}*/
	// Printing the lower triangular matrix
	/*cout<<"\nLower triangular matrix : \n";
	loop(i,0,n)
	{
		loop(j,0,n)
			cout<<lower[i][j]<<' ';
		cout<<'\n';
	}*/
	// Finding the inverse of the matrix using LU Decomposition
 	double Identity[3][3];
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
	double b[3],col[3],val[3];
	// The idea is obtain the A inverse row wise and final construct the A inverse matrix
	// Forward substitution is performed on Lower matrix and backward substitution is performed on upper matrix
	// A inverse matrix is constructed from the back substitution
	loop(x,0,n)
	{
		loop(i,0,n)
			b[i]=Identity[x][i];
		forward_subs(n,lower,b,col);
		back_subs(n,upper,col,val);
		loop(i,0,n)
			inverse[i][x]=val[i];
	}
	// Printing the Inverse Matrix
/*	cout<<"\nInverse matrix : \n";
	loop(i,0,n)
	{
		loop(j,0,n)
			cout<<inverse[i][j]<<' ';
		cout<<'\n';
	}
	cout<<'\n';
*/
}

int NonLinearSolver(double x, double y, double z, int iter)
{
  double jacobi[3][3], jacobi_inverse[3][3], x_guess[3], x_diff[3],fval[3];
  int i,j,k;
  x_guess[0]=x;
  x_guess[1]=y;
  x_guess[2]=z;
  k=0;
  loop(k,0,iter)
  {
      jacobian(x_guess[0],x_guess[1],x_guess[2],jacobi);
/*      cout<<"\nJacobian matrix : \n";
      loop(i,0,3)
      {
        loop(j,0,3)
          cout<<jacobi[i][j]<<' ';
        cout<<'\n';
      }
*/
      ludecomp(jacobi,jacobi_inverse,3);
      f_val(x_guess[0],x_guess[1],x_guess[2],fval);
/*      cout<<"Printing F_VAL\n";
      loop(i,0,3)
        cout<<fval[i]<<endl;
*/
      mat_mult(jacobi_inverse,fval,x_diff,3);
/*      cout<<"Printing X_DIFF\n";
      loop(i,0,3)
        cout<<x_diff[i]<<endl;
*/
      loop(i,0,3)
      {
        x_guess[i]-=x_diff[i];
      }
      cout<<"Iteration "<<k+1<<"\t Solutions are - ( "<<setprecision(6)<<x_guess[0]<<" , "<<x_guess[1]<<" , "<<x_guess[2]<<")\n";
  }
}
int main()
{
  double x,y,z;
  x=0.1, y=1.2, z=2.5;
//  x=1, y=0, z=1;
  NonLinearSolver(x,y,z,iter_max);
}
