#include<bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)
#define iter_max 10
using namespace std;

double f_x(double x)
{
	double fx;
	fx=2*exp(-x)-(1/(x+1))-(1/(x+2));
	return fx;
}

double secant(double x_1, double x_2)
{
	int i;
	double x_3,dfx;
	loop(i,0,iter_max)
	{
		dfx=(x_2-x_1)/(f_x(x_2)-f_x(x_1));
		if(x_2 - x_1 == 0)
			break;
		x_3=x_2-f_x(x_2)*dfx;
		x_1=x_2;
		x_2=x_3;
		cout<<"Iteration = "<<i+1<<"\tx = "<<setprecision(5)<<x_3<<'\n';
	}
	if (i!=iter_max)
	cout<<"X converges after "<<i<<" iterations to x = "<<x_3<<'\n';
	else
	cout<<"X after "<<i<<" iterations, x = "<<x_3<<'\n';
	return x_3;
}
int main()
{
	double x_1=0.5,x_2=0.6;
	secant(x_1,x_2);
	return 0;
}
