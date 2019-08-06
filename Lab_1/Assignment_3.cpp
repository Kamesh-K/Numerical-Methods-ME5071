#include<bits/stdc++.h>
#include<omp.h>
#define loo(i,a,b) for(i=a;i<b;i++)
using namespace std;
// Code to study the time taken to do array operations 
/* 	We have considered a simple case of array multiplication
	Array A is multiplied to the vector B and stored in vector C 
	The time taken for the computation is shown in the command line 
	Command to execute and run the code : 
	g++ Assignment_3.cpp -o as3.out -fopenmp && ./as3.out
*/
int main()
{
	int index[5];
	index[0]=256;
	int i;
//	Initializing the values for the array size to compute 
	loo(i,1,5)
		index[i]=index[i-1]*(2);
	int k;		
	loo(k,0,5)
	{
//	Starting the timer for the calculation
	double time=omp_get_wtime();
	int n=index[k];
	int a[n][n],b[n],c[n],i,j;
	loo(i,0,n)
		loo(j,0,n)
			a[i][j]=rand()%10;
	loo(i,0,n)
		b[i]=rand()%10;
	loo(i,0,n)
	{
		c[i]=0;
		loo(j,0,n)
		{
			c[i]+=a[i][j]*b[j];
		}
	}
	double time1=omp_get_wtime();
//	Finishing the timer and output the time taken for the computation
	cout<<"Time taken for "<<n<<" is "<<time1-time<<" seconds\n";
	} 
return 0;
}
