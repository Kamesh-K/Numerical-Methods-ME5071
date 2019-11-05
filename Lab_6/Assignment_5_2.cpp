#include<bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)
#define iter_max 20
#define N_MAX 50
using namespace std;
double biot=7;
double fun_u(double x)
{
	double ans=biot-(x*tan(x));
	return ans;
}
double fdiff_1(double x1,double h)
{
	double f_diff;
	f_diff=(fun_u(x1+h)-fun_u(x1))/h;
	return f_diff;
}
double error_calc(double ans, double x)
{
	double diff,err;
	diff = -tan(x)-(x/(cos(x)*cos(x)));
	err= ans - diff;
	err = abs(err);
	return err;
}
void fdiffvec1(double x1, double x2, double h)
{
	int i,j,k;
	int num = (x2-x1)/h;
	vector<double> diff_1(num+1,0);
	double x=x1,x_h;	
	loop(i,0,num+1)
	{
		x_h=x1+h;
		diff_1[i]=(fun_u(x_h)-fun_u(x1))/h;
		x+=h;	
	}
	cout<<diff_1[0]<<'\n';
	ofstream file;
	file.open("Forward_1.txt");
	x=x1;		
	loop(i,0,num+1)
	{
		file<<x<<' '<<std::setprecision(12)<<log10(error_calc(diff_1[i],x))<<'\n';
		x+=h;	
	}
}
void fdiffvec2(double x1, double x2, double h)
{
	int i,j,k;
	int num = (x2-x1)/h;
	vector<double> diff_1(num+1,0);
	double x=x1;
	double a=2,b=-0.5; 
	loop(i,0,num+1)
	{
		diff_1[i]=(a*fun_u(x+h)+b*fun_u(x+2*h)-(a+b)*fun_u(x))/h;
		x+=h;	
	}
	ofstream file;
	file.open("Forward_2.txt");
	x=x1;		
	loop(i,0,num+1)
	{		
		file<<x<<' '<<std::setprecision(12)<<log10(error_calc(diff_1[i],x))<<'\n';
		x+=h;	
	}
}

void fdiffvec4(double x1, double x2, double h)
{
	int i,j,k;
	int num = (x2-x1)/h;
	vector<double> diff_1(num+1,0);
	double x=x1;
	double a=4,b=-3,c=4/3,d=-0.25; 
	loop(i,0,num+1)
	{
		diff_1[i]=(a*fun_u(x+h)+b*fun_u(x+2*h)+c*fun_u(x+3*h)+d*fun_u(x+4*h)-(a+b+c+d)*fun_u(x))/h;
		x+=h;	
	}
	ofstream file;
	file.open("Forward_4.txt");
	x=x1;		
	loop(i,0,num+1)
	{
		file<<x<<' '<<std::setprecision(12)<<log10(error_calc(diff_1[i],x))<<'\n';
		x+=h;	
	}
	file.close();
	file.open("Value.txt");
	x=x1;		
	loop(i,0,num+1)
	{
		file<<x<<' '<<std::setprecision(12)<<diff_1[i]<<'\n';
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
