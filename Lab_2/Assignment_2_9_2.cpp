#include <bits/stdc++.h>
#define loo(i,a,b) for(i=a;i<b;i++) 
using namespace std; 
int matrix_mult(int n, double a[][4], double b[][4],double c[][4])
{
	int i,j,k;
	loo(i,0,n)
	{
		loo(j,0,n)
		{
			c[i][j]=0;
			loo(k,0,n)
				c[i][j]+=a[i][k]*b[k][j];
		}
	}
	return 1;
}
int L_inverse(int n,double a[][4], double b[][4])
{
int i,j,k;
double Identity[n][n],product=1,sum=0;
loo(i,0,n)
	loo(j,0,n)
		b[i][j]=0;
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

loo(i,0,n)
{
	loo(j,0,i+1)
	{
   		sum=0;
		loo(k,j,i)
		sum=sum+a[i][k]*b[k][j];
		b[i][j]=(Identity[i][j]-sum)/a[i][j];	
	}
}
}
int forward_subs(int n, double a[][4], double b[], double x[])
{
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
int back_subs(int n, double a[][4], double b[], double x[])
{
	int i,j,k;
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
	int i,j,k;
	double sum=0;
	loo(i,0,n)
		loo(j,0,n)
			{
			lower[i][j]=0;
			upper[i][j]=0;			
			}

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
		        lower[i][i] = 1; 
		    else { 
			sum=0;
			loo(j,0,i)                
			    sum+=(lower[k][j]*upper[j][i]); 
		        lower[k][i]=(a[k][i]-sum)/upper[i][i]; 
		    } 
		} 
	}

	cout<<"\nUpper triangular matrix : \n";
	loo(i,0,n)
	{
		loo(j,0,n)
			cout<<upper[i][j]<<' ';
		cout<<'\n';
	}
	cout<<"\nLower triangular matrix : \n";
	loo(i,0,n)
	{
		loo(j,0,n)
			cout<<lower[i][j]<<' ';
		cout<<'\n';
	}
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
	double b[n],col[n],val[n],for_sub[4][4];
	double U_trans[4][4],inverse[4][4];
	loo(x,0,n)
	{
		loo(i,0,n)
			b[i]=Identity[x][i];
		forward_subs(4,lower,b,col);
		loo(i,0,4)		
			for_sub[x][i]=col[i];
	}	
	loo(x,0,n)
	{
		loo(i,0,n)
			col[i]=for_sub[x][i];
		back_subs(4,upper,col,val);
		loo(i,0,n)
			inverse[x][i]=val[i];
	}
	cout<<"\n Inverse matrix : \n";
	loo(i,0,n)
	{
		loo(j,0,n)
			cout<<inverse[i][j]<<' ';
		cout<<'\n';
	}

/*
	double L_inv[4][4];
	L_inverse(n,lower,L_inv);

	cout<<"\n L Inverse matrix : \n";
	loo(i,0,n)
	{
		loo(j,0,n)
			cout<<L_inv[i][j]<<' ';
		cout<<'\n';
	}		
	
	double U_trans[4][4],inverse[4][4];
	loo(i,0,n)
		loo(j,0,n)
			U_trans[i][j]=upper[j][i];
	L_inverse(n,U_trans,upper);
	loo(i,0,n)
		loo(j,0,n)
			U_trans[i][j]=upper[j][i];
	cout<<"\n U Inverse matrix : \n";
	loo(i,0,n)
	{
		loo(j,0,n)
			cout<<U_trans[i][j]<<' ';
		cout<<'\n';
	}		
	matrix_mult(n,U_trans,L_inv,inverse);
	cout<<"\n Inverse matrix : \n";
	loo(i,0,n)
	{
		loo(j,0,n)
			cout<<inverse[i][j]<<' ';
		cout<<'\n';
	}		*/
}
int main() 
{ 
int n,i,j,k;
//double a[1024][1024];
/*cout<<"Enter the size of the matrix : ";
cin>>n;
loo(i,0,n)
	loo(j,0,n)
		a[i][j]=pow(i+1,j+1);
*/
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
