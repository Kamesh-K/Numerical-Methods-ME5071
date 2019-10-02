#include<bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)
#define iter_max 10
using namespace std;

double f_x(double x)
{
	double fx;
	fx=cos(M_PI*(x+1)/8)+0.148*x-0.9062;
	return fx;
}

double df_x(double x)
{
	double dfx;
	dfx=-M_PI/8*sin(M_PI*(x+1)/8)+0.148;
	return dfx;
}

double NewtonRaphson(double x)
{
	int i;
	double fx,dfx,x_1;
	loop(i,0,iter_max)
	{
		fx=f_x(x);
		dfx=df_x(x);
		x_1=x-(fx/dfx);
		x=x_1;
		cout<<"Iteration = "<<i+1<<"\tx = "<<setprecision(6)<<x<<'\n';
	}
	cout<<"X after "<<iter_max<<" iterations = "<<x_1<<'\n';
	return x_1;
}

int main()
{
	double x=-1;
	NewtonRaphson(x);
	return 0;
}
