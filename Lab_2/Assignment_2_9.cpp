#include <bits/stdc++.h>
#define loo(i,a,b) for(i=a;i<b;i++) 
using namespace std; 
int ludecomp(float a[][4], float lower[][4], float upper[][4],int n) 
{ 
	int i,j,k;
	float sum=0;
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
		
} 
int main() 
{ 
int n,i,j,k;
//float a[1024][1024];
/*cout<<"Enter the size of the matrix : ";
cin>>n;
loo(i,0,n)
	loo(j,0,n)
		a[i][j]=pow(i+1,j+1);
*/
n=4;
float a[4][4]={{3,2,1,5},{2,3,2,7},{1,2,2,6},{4,5,6,5}};
cout<<"\nThe given matrix is : \n";
loo(i,0,n)
	{
	loo(j,0,n)
		cout<<a[i][j]<<' ';
	cout<<'\n';	
	}
float lower[4][4],upper[4][4];
ludecomp(a,lower,upper,4); 

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
return 0; 
} 
