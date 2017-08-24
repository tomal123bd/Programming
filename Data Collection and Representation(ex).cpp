#include <iostream>
#include <math.h>
#include <windows.h>
using namespace std;

void input_data (int value[],int N)
{
    int i;
    for (i=1;i<=N;i++)
    {
        cout << ">>> ";
        cin >> value[i];
    }
    cout << endl;
}

int u_l (int data[],int N)
{
    int i;
    int _upper_limit=data[1];
    for (i=1;i<=N;i++)
    {
        if (_upper_limit<data[i])
        {
            _upper_limit=data[i];
        }
    }
    return _upper_limit;
}

int l_l (int data[],int N)
{
    int i;
    int _lower_limit=data[1];
    for (i=1;i<=N;i++)
    {
        if (_lower_limit>data[i])
        {
            _lower_limit=data[i];
        }
    }
    return _lower_limit;
}

int cal_of_range (int u_l,int l_l)
{
    return u_l-l_l;
}

float cal_of_num_of_cls (int N)
{
    float k=1+(3.322*log10(N));
    return k;
}

float cal_of_cls_interval (int range ,float k)
{
    return range/k;
}

float final_cls_int (float cls_int)
{
    int n=cls_int,temp=0;
    while (temp<=n)
    {
        temp=temp+5;
    }
    //cout << "\ntemp " << temp << endl;
    /*if (temp-cls_int < abs (temp-5)-cls_int)
    {
        return temp;
    }*/
    //return temp+5;
    return temp;
}

int temp_cls (int upper,int lower,int interval)
{
    int count=0,start,i;
    start=lower/5;
    start=start*5;
    for (i=start;i<upper;i=i+interval)
    {
        count++;
    }
    return count+1;
}

void _class_value (int cls[] , int interval , int upper , int lower)
{
    int i,start,count=1;
    start=lower/5;
    start=start*5;
    cout << "Class:" << endl;
    for (i=start;i<upper;i=i+interval,count++)
    {
        cls[count]=i;
        cout << " " << cls[count];
    }
    cls[count]=i;cout << " " << cls[count] << endl;
}

void _tally_frequency (int cls[],int data[],int _tally_frequency[],int N,int _int)
{
    int i,j;
    for (i=1;i<=_int;i++)
    {
        _tally_frequency[i]=0;
    }
    for (i=1;i<=N;i++)
    {
        for (j=1;j<_int;j++)
        {
            if (data[i]>=cls[j] && data[i]<cls[j+1])
            {
                _tally_frequency[j]=_tally_frequency[j]+1;
            }
        }
    }
}
void cal_of_mid_point (float midpoint[],int cls[],int temp_cls)
{
    int i;
    for (i=1;i<temp_cls;i++)
    {
        midpoint[i]=((float) cls[i]+(float) cls[i+1])/2;
        cout << " " << midpoint[i];
    }
}

void cal_of_frequency_density (float fre_den[],int fre[],int temp_cls,int interval)
{
    int i;
    for (i=1;i<temp_cls;i++)
    {
        fre_den[i]=(float)fre[i]/interval;
        cout << " " << fre_den[i];
    }
}

void cal_of_p_of_fre (float p_f[],int fre[],int temp_cls,int N)
{
    int i;
    for (i=1;i<temp_cls;i++)
    {
        p_f[i]=((float)fre[i]/N)*100;
        cout << " " << p_f[i];
    }
}

void cal_of_ucf (int ucf[],int fre[],int temp_cls)
{
    int i,count=1;
    ucf[1]=fre[1];
    cout << " " << ucf[1];
    for (i=2;i<temp_cls;i++,count++)
    {
        ucf[i]=ucf[count]+fre[i];
        cout << " " << ucf[i];
    }
}

void cal_of_lcf (int lcf[],int fre[],int temp_cls)
{
    int i,count=temp_cls-1;
    lcf[temp_cls-1]=fre[temp_cls-1];
    for (i=temp_cls-2;i>0;i--,count--)
    {
        lcf[i]=lcf[count]+fre[i];
    }
    for (i=1;i<temp_cls;i++)
    {
        cout << " " << lcf[i];
    }
}
int main ()
{
    int N;
    cout << "Input total number of data and press enter: \n";
    cin >> N;
    /*int data[]={0,88,191,104,144,136,198,142,149,129,104,123,108,160,127,105,
                102,96,87,118,149,131,94,101,93,89,194,148,146,183,187,
                195,92,93,119,132,108,68,172,97,108};
    int data[]={0,46,32,20,43,48,52,33,66,24,16,41,27,13,31,55,36,14,33,21,44,26,53,
                24,67,29,19,42,69,50,32,58,45,15,40,22,37,30,54,35,28};*/
    int data[N];
    cout << "Input Data (press enter for next): \n";
    input_data(data,N);
    int range,upper_limit,lower_limit;
    upper_limit=u_l(data,N);
    lower_limit=l_l(data,N);
    cout << "Upper limit: " << upper_limit << " Lower limit: " << lower_limit << endl;
    range=cal_of_range (upper_limit,lower_limit);
    float k,class_interval;
    k=cal_of_num_of_cls(N);
    class_interval=cal_of_cls_interval(range,k);
    cout << "Range: " << range << "\nk: " << k << "\nClass interval: " << class_interval << endl;
    int final_class_interval;
    final_class_interval=final_cls_int(class_interval);
    cout << "Final class interval: " << final_class_interval;
    int temp_class=temp_cls(upper_limit,lower_limit,final_class_interval);
    cout << "\nNumber of class: " << temp_class-1 << endl;
    int _class[temp_class];
    _class_value(_class,final_class_interval,upper_limit,lower_limit);
    int tally_frequency[temp_class];
    _tally_frequency(_class,data,tally_frequency,N,temp_class);
    int i;cout << "Tally & Frequency: " << endl;
    for (i=1;i<temp_class;i++)
    {
        cout << " " << tally_frequency[i];
    }
    float mid_point[temp_class];
    cout << "\nMid point: \n";
    cal_of_mid_point (mid_point,_class,temp_class);
    float frequency_density[temp_class];
    cout << "\nFrequency density: " << endl;
    cal_of_frequency_density (frequency_density,tally_frequency,temp_class,final_class_interval);
    float percentage_of_frequency[temp_class];
    cout << "\nPercentage of frequency: " << endl;
    cal_of_p_of_fre(percentage_of_frequency,tally_frequency,temp_class,N);
    int u_c_f[temp_class],l_c_f[temp_class];
    cout << "\nU C F: " << endl;
    cal_of_ucf (u_c_f,tally_frequency,temp_class);
    cout << "\nL C F: " << endl;
    cal_of_lcf(l_c_f,tally_frequency,temp_class);
    float location_on_median,location_on_q1,location_on_q3;
    location_on_median=N/2;cout << "\nLocation on median: " << location_on_median;
    location_on_q1=(N*1)/4;cout << "\nLocation on q1: " << location_on_q1;
    location_on_q3=(N*3)/3;cout << "\nLocatin on q3: " << location_on_q3;
    cout << endl << endl;
    system("pause");
    return 0;
}
