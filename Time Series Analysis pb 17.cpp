#include <iostream>
using namespace std;
void print_value (float sum_y,float sum_x,float sum_x_squre,float sum_xy,float total_year,float y[],float x[],float x_squre[],float xy[])
{
    int i;
    cout << "y" << endl;
    for (i=1;i<=total_year;i++)
    {
        cout << y[i-1] << " ";
    }
    cout << endl;
    cout << sum_y << endl;
    cout << "x" << endl;
    for (i=1;i<=total_year;i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
    cout << "sum: " << sum_x << endl;
    cout << endl;
    cout << "x squre" << endl;
    for (i=1;i<=total_year;i++)
    {
        cout << x_squre[i] << " ";
    }
    cout << endl;
    cout << "sum: " << sum_x_squre << endl;
    cout << endl;
    cout << "xy" << endl;
    for (i=1;i<=total_year;i++)
    {
        cout << xy[i] << " ";
    }
    cout << endl;
    cout << "sum: " << sum_xy << endl;
    cout << endl;
}
int main ()
{
    cout << "Table for calculation of trend using list squre method" << endl;
    int year_start, year_end, total_year;
    cout << "Input starting year: ";
    cin >> year_start;
    cout << "Input ending year: ";
    cin >> year_end;
    year_start--;
    total_year = year_end-year_start;
    float X[total_year], y[total_year];
    int i;
    cout << "Input \"y\" :" << endl;
    year_start++;
    for (i=1;i<=total_year;i++)
    {
        cout << ">>> ";
        cin >> y[i-1];
        X[i]=year_start;
        year_start++;
    }
    cout << endl;
    float x[total_year];  /*x=x-a*/
    int A;
    if (total_year%2!=0)
    {
        A=(total_year/2)+1;
    }
    else
    {
        A=total_year/2;
    }
    for (i=1;i<=total_year;i++)
    {
        if (total_year%2!=0)
        {
            x[i]=X[i]-X[A];
        }
        else
        {
            x[i]=X[i]-((X[A]+X[A+1])/2);
        }
    }
    float x_squre[total_year] , xy[total_year] , yc[total_year];
    for (i=1;i<=total_year;i++)
    {
        x_squre[i]=x[i]*x[i];
        xy[i]=x[i]*y[i-1];
    }
    float N , sum_y=0 , sum_x=0 , sum_x_squre=0 , sum_xy=0;
    N=total_year;
    for (i=1;i<=total_year;i++)
    {
        sum_y=y[i-1]+sum_y;
        sum_x=x[i]+sum_x;
        sum_x_squre=x_squre[i]+sum_x_squre;
        sum_xy=xy[i]+sum_xy;
    }
    cout << "We know , the equation of trend line is: y = a+bx " << endl;
    float a,b;
    a=sum_y/N;
    b=sum_xy/sum_x_squre;
    cout << "Puting the value of a and b in the avobe equation, we get: " << endl;
    cout << "yc = a + bx = "<< a << " + " << b << "x" << endl;
    print_value(sum_y,sum_x,sum_x_squre,sum_xy,total_year,y,x,x_squre,xy);
    cout << "/n";
    for (i=1;i<=total_year;i++)
    {
        cout << "When x = " << x[i] << " then yc = " << a << " + " << b << "(" << x[i] << ")" << " = " << a+ (b*x[i]) << endl;
    }
    return 0;
}
