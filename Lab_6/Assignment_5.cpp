#include<bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)
#define iter_max 20
#define N_MAX 50
using namespace std;
int main()
{
int i,k;
double u[90000],v[90000],h=0.1;
u[0]=1;
v[0]=0;
u[1]=1;
v[1]=-1.6;
double x=0;
i=0;
cout<<x<<'\t'<<u[i]<<'\t'<<v[i]<<endl; 
i++,x+=h;
cout<<x<<'\t'<<u[i]<<'\t'<<v[i]<<endl; 
loop(i,0,90)
{	
	x+=h;
	v[i+2] = v[i] - 32*h*u[i+1];
	u[i+2] = u[i] + 2*h*v[i+1];
	cout<<x<<'\t'<<u[i+2]<<'\t'<<v[i+2]<<endl;
}

}
