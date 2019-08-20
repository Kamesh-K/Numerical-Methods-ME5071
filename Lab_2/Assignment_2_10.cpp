#include <bits/stdc++.h>
#define loo(i,a,b) for(i=a;i<b;i++) 
using namespace std; 
float u(int n)
{
	if(n==0 || n==1)
		return (float) 2.9689;
	return 3*u(n-1)-2*u(n-2);
}
int main()
{
int i,n;
cout<<"Enter the value of N : ";
cin>>n;
double u[n];
u[0]=2.9689;
u[1]=2.9689;
loo(i,2,n+1)
	u[i]=3*u[i-1]-2*u[i-2];
loo(i,0,n+1)
cout<<"i = "<<i<<" and U(i) = "<<u[i]<<'\n';
return 0;
}
