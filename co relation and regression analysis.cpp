/* karl pearsons method*/
#include <iostream>
#include <math.h>
using namespace std;
void print_value (int N,float a[],float sum)
{
    int i;
    for (i=1;i<=N;i++)
    {
        cout << a[i] << " ";
    }
    cout << "Sum: " << sum << "\n";
}
int main ()
{
    cout << "Input N: \n";
    int N;
    cin >> N;
    float x[N],y[N],sum_x=0,sum_y=0,x_squre[N],y_squre[N],sum_x_squre=0,sum_y_squre=0;
    int i;
    cout << "Input x: \n";
    for (i=1;i<=N;i++)
    {
        cout << ">>> \n";
        cin >> x[i];
        sum_x=sum_x+x[i];
        x_squre[i]=x[i]*x[i];
        sum_x_squre=sum_x_squre+x_squre[i];
    }
    cout << "Input y: \n";
    for (i=1;i<=N;i++)
    {
        cout << ">>> \n";
        cin >> y[i];
        sum_y=sum_y+y[i];
        y_squre[i]=y[i]*y[i];
        sum_y_squre=sum_y_squre+y_squre[i];
    }
    float xy[N],sum_xy=0;
    for (i=1;i<=N;i++)
    {
        xy[i]=x[i]*y[i];
        sum_xy=sum_xy+xy[i];
    }

    float r,temp1,temp2,temp2_1,temp2_2,temp3;
    /*r= (sum_xy - ((sum_x*sum_y) / N) ) / (sqrt((sum_x_squre - ((sum_x*sum_x)/N))*(sum_y_squre - ((sum_y*sum_y)/N))));*/
    temp1=sum_xy - ((sum_x*sum_y)/N);
    temp2_1=sum_x_squre - ((sum_x*sum_x)/N);
    temp2_2=sum_y_squre - ((sum_y*sum_y)/N);
    temp3=temp2_1*temp2_2;
    temp2=sqrt(temp3);
    r=temp1/temp2;
    cout << "x: \n";
    print_value(N , x, sum_x);
    cout << "y: \n";
    print_value (N , y , sum_y);
    cout << "x squre: \n";
    print_value (N , x_squre , sum_x_squre);
    cout << "y squre: \n";
    print_value (N , y_squre , sum_y_squre);
    cout << "xy: \n";
    print_value (N , xy , sum_xy);
    cout << "\nr = " << r << endl;
    return 0;
}
