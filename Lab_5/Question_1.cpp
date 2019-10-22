#include<bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)
#define iter_max 20
#define N_MAX 50
using namespace std;
// To compile and run and generate the plot g++ Assign_5.cpp -o Assign_5.out && ./Assign_5.out && gnuplot line_plot.gnu 
double lambda = 10.0;
double yi = 10, t0 = 0, tf = 0.8;
double h = 0.1;

double f(double y, double t)
{
	double value;
	value = -lambda * (y - exp(-t)) - exp(-t);
	return value;
}

double yexact(double t)
{
    double value;
    value = exp(-t) + (yi - 1) * exp(-lambda * t);
    return value;
}

double rk4(double t, double h, double y)
{
    double k1,k2,k3,k4,k,ynext;
    k1 = f(y,t);
    k2 = f(y + k1 * h/2 , t + h/2);
    k3 = f(y + k2 * h/2 , t + h/2);
    k4 = f(y + k3 * h , t + h);
    k = (k1 + 2*k2 + 2*k3 + k4) / 6;
    ynext = y + h * k;
    return ynext;
}
double euler(double t, double h, double y)
{
    double k , ynext;
    k = f(y,t);
    ynext = y + h * k;
    return ynext;
}

double heun(double t, double h, double y)
{
    double k1 , k2 , k , ynext;
    k1 = f(y,t);
    k2 = f(y + k1*h, t+h);
    k = (k1 + k2) / 2;
    ynext = y + h * k;
    return ynext;
}

double function(double y_next,double t,double h,double y)
{
    double value;
    value = y_next - y - h * (-lambda * (y_next - exp(-(t + h)) - exp(-(t + h))));
    return value;
}
double euler_b(double t, double h, double y)
{
    double y_next;
    y_next = (y + (lambda-1)*exp(-(t+h))*h)/(1+lambda*h);
    //for(i = 0; i < 10;i++)
    //    y_next = NR(y_next , t , h , y);
    //return y_next;
}

void ensemble(double h)
{
    double error[4];
    int n = ( tf - t0 ) / h;
    double t[n+1] , y[n+1][4];
	ofstream f_euler,f_b_euler,f_heun,f_rk4,f_act;
	f_euler.open("euler.txt");
	f_b_euler.open("b_euler.txt");
	f_heun.open("heun.txt");
	f_rk4.open("rk4.txt");
	f_act.open("act.txt");

    int i,j;
    t[0] = t0;
    t[n] = tf;
    for(j = 0; j < 4 ; j++)
        y[0][j] = yi;
    for(i = 1; i < n ; i++)
        t[i] = t[i-1] + h;
    cout<<"Step size = "<< h << endl;
		j=0,i=0;
		    f_euler<<t[i]<<'\t'<<y[i][j]<<'\n';
		    f_b_euler<<t[i]<<'\t'<<y[i][j+1]<<'\n';
		    f_heun<<t[i]<<'\t'<<y[i][j+2]<<'\n';
    		    f_rk4<<t[i]<<'\t'<<y[i][j+3]<<'\n';
		f_act<<t[i]<<'\t'<<yexact(t[i])<<'\n';
    cout << "t" << '\t'<<"Euler" << '\t'<< "Euler-b" << '\t'<< "Heun's" << '\t'<< "RK4" << '\t' << "exact" << endl;
    cout <<setprecision(5)<< t0 <<'\t'<<setprecision(5)<< yi <<'\t'<<setprecision(5)<< yi <<'\t'<<setprecision(5)<< yi <<'\t'<<setprecision(5)<<yi<<'\t'<<setprecision(5)<< yexact(t0) <<endl;
    for(i = 0; i < n; i++)
        for(j = 0;j < 6; j++)
        {
            switch(j)
            {
                case 0:
                    y[i+1][j] = euler(t[i],h,y[i][j]);
                    cout <<setprecision(5)<< t[i+1] << '\t';
                    cout <<setprecision(5)<< y[i+1][j] << '\t';
		    f_euler<<t[i+1]<<'\t'<<y[i+1][j]<<'\n';
                    break;
                case 1:
                    y[i+1][j] = euler_b(t[i],h,y[i][j]);
                    cout <<setprecision(5)<< y[i+1][j] << '\t';
		    f_b_euler<<t[i+1]<<'\t'<<y[i+1][j]<<'\n';
                    break;
                case 2:
                    y[i+1][j] = heun(t[i],h,y[i][j]);
                    cout <<setprecision(5)<< y[i+1][j] << '\t';
		    f_heun<<t[i+1]<<'\t'<<y[i+1][j]<<'\n';
		break;
                case 3:
                    y[i+1][j] = rk4(t[i],h,y[i][j]);
                    cout <<setprecision(5)<< y[i+1][j] << '\t';
    		    f_rk4<<t[i+1]<<'\t'<<y[i+1][j]<<'\n';
		break;
                case 4:
                    cout <<setprecision(5)<< yexact(t[i+1]) <<endl;
			f_act<<t[i+1]<<'\t'<<yexact(t[i+1])<<'\n';
                    break;
            }
        }
	cout<<endl;
	for(j = 0;j<4;j++)
	{
		error[j] = abs(y[n][j]-yexact(t[n]));
	}
	cout<<"Error in euler = "<<error[0]<<endl;
	cout<<"Error in backward euler = "<<error[1]<<endl;
	cout<<"Error in heun = "<<error[2]<<endl;
	cout<<"Error in rk4 = "<<error[3]<<endl;
	cout<<endl<<endl;

}

int main()
{
	double h;
	cout<<"Enter the Value of h : ";
	cin>>h;	
	ensemble(h);
	return 0;
}
