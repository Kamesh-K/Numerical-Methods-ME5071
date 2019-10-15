#include<bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)
#define iter_max 20
#define N_MAX 3
using namespace std;
double func(double lamda, double t, double y)
{
	double f;
	if(t==0)
		return 10.00;
	f= (-1*lamda*(y - exp(-1*t)))-exp(-1*t);
	return f;
}
double explicit_euler(double a, double b, double h)
{
	int n;
	int i,j;
	n = ceil((b-a)/(h));
	cout<<n<<endl;
	double y=10;
	double x=a,lamda=10;	
	loop(i,0,n)
	{
		y= y+h*func(lamda,x,y);
		x = x+h;
	}
	return y;	
}
double implicit_euler(double a, double b, double h)
{
	int n;
	int i,j;
	n = ceil((b-a)/(h));
	cout<<n<<endl;
	double y=10;
	double x=a,lamda=10;	
	loop(i,0,n)
	{
		y_1=y+h*func(lamda,x,y)
		y=y_1;
		x = x+h;
	}
	return y;	
}
int main()
{
	double x,y,z,h;
	x=0,y=0.8,h=0.1;
	cout<<explicit_euler(x,y,h)<<'\n';		
}
