#include<bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)
#define iter_max 20
#define N_MAX 50
using namespace std;
double biot=7;
double fun_u(double x)
{
	return biot-x*tan(x);
}
double fdiff_1(double x1,double h)
{
	double f_diff;
	f_diff=(fun_u(x1+h)-fun_u(x1))/h;
	return f_diff;
}
void fdiffvec1(double x1, double x2, double h)
{
	int i,j,k;
	int num = (x2-x1)/h;
	vector<int> diff_1(num+1,0);
	double x=x1;	
	loop(i,0,num+1)
	{
		diff_1[i]=fdiff_1(x,h);
		x+=h;	
	}
	ofstream file;
	file.open("Forward_1.txt");
	x=x1;		
	loop(i,0,num+1)
	{
		file<<x<<' '<<diff_1[i]<<'\n';
		x+=h;	
	}
}
double fdiff_2(double x1,double h)
{
	double f_diff;
	f_diff=(fdiff_1(x1+h,h)-fdiff_1(x1,h))/h;
	return f_diff;
}
void fdiffvec2(double x1, double x2, double h)
{
	int i,j,k;
	int num = (x2-x1)/h;
	vector<int> diff_1(num+1,0);
	double x=x1;	
	loop(i,0,num+1)
	{
		diff_1[i]=fdiff_2(x,h);
		x+=h;	
	}
	ofstream file;
	file.open("Forward_2.txt");
	x=x1;		
	loop(i,0,num+1)
	{
		file<<x<<' '<<diff_1[i]<<'\n';
		x+=h;	
	}
}
double fdiff_3(double x1,double h)
{
	double f_diff;
	f_diff=(fdiff_2(x1+h,h)-fdiff_2(x1,h))/h;
	return f_diff;	
}
double fdiff_4(double x1,double h)
{
	double f_diff;
	f_diff=(fdiff_3(x1+h,h)-fdiff_3(x1,h))/h;
	return f_diff;
}
void fdiffvec4(double x1, double x2, double h)
{
	int i,j,k;
	int num = (x2-x1)/h;
	vector<int> diff_1(num+1,0);
	double x=x1;	
	loop(i,0,num+1)
	{
		diff_1[i]=fdiff_4(x,h);
		x+=h;	
	}
	ofstream file;
	file.open("Forward_4.txt");
	x=x1;		
	loop(i,0,num+1)
	{
		file<<x<<' '<<diff_1[i]<<'\n';
		x+=h;	
	}
}
int main()
{
fdiffvec1(-1,1,0.1);
fdiffvec2(-1,1,0.1);
fdiffvec4(-1,1,0.1);
return 0;
}
