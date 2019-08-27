#include <bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++) 
using namespace std; 
int ludecomp(float a[][4], float lower[][4], float upper[][4],int n) 
{ 
	int i,j,k;
	float sum=0;
	loop(i,0,n)
		loop(j,0,n)
			{
			lower[i][j]=0;
			upper[i][j]=0;			
			}

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
		        lower[i][i] = 1; 
		    else { 
			sum=0;
			loop(j,0,i)                
			    sum+=(lower[k][j]*upper[j][i]); 
		        lower[k][i]=(a[k][i]-sum)/upper[i][i]; 
		    } 
		} 
	} 
} 
int back_subs(int n, float a[][1024], float b[], float x[])
{
	int i,j,k;
	float sum=0;
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
int forward_subs(int n, float a[][1024], float b[], float x[])
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
int matrix_mult(int n, float a[][1024], float b[][1024],float c[][1024])
{
	int i,j,k;
	loop(i,0,n)
	{
		loop(j,0,n)
		{
			c[i][j]=0;
			loop(k,0,n)
				c[i][j]+=a[i][k]*b[k][i];
		}
	}
	return 1;
}
int main() 
{ 
int n,i,j,k;
//float a[1024][1024];
/*cout<<"Enter the size of the matrix : ";
cin>>n;
loop(i,0,n)
	loop(j,0,n)
		a[i][j]=pow(i+1,j+1);
*/
n=4;
float a[4][4]={{3,2,1,5},{2,3,2,7},{1,2,2,6},{4,5,6,5}};
cout<<"\nThe given matrix is : \n";
/*
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)*/
loop(i,0,n)
	{
	loop(j,0,n)
		cout<<a[i][j]<<' ';
	cout<<'\n';	
	}
float lower[4][4],upper[4][4];
ludecomp(a,lower,upper,4); 

	cout<<"\nUpper triangular matrix : \n";
	loop(i,0,n)
	{
		loop(j,0,n)
			cout<<upper[i][j]<<' ';
		cout<<'\n';
	}
	cout<<"\nLower triangular matrix : \n";
	loop(i,0,n)
	{
		loop(j,0,n)
			cout<<lower[i][j]<<' ';
		cout<<'\n';
	}
return 0; 
} 