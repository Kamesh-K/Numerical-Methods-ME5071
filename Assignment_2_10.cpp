#include <bits/stdc++.h>
#define loo(i,a,b) for(i=a;i<b;i++) 
using namespace std; 
int main()
{
	int i,n;
	// Obtaining the input from the user for calculating the u(n)
	cout<<"Enter the value of N : ";
	cin>>n;
	// Initializing the variables 
	double u[n+1];
	// Base conditions
	u[0]=2.9689;
	u[1]=2.9689;
	// Calculating u(n) by the expression u(n)= (3 * u(n-1)) - (2 * u(n-2)) 
	loo(i,2,n+1)
		u[i]=3*u[i-1]-2*u[i-2];
	// Printing the output (Values of u(i))
	loo(i,0,n+1)
	cout<<"i = "<<i<<" and U(i) = "<<u[i]<<'\n';
	return 0;
}
