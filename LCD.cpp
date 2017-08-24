#include <iostream>
using namespace std;

int div (int number[],int divides,int n)
{
    int i,count=0;
    for (i=0;i<n;i++)
    {
        if (number[i]==1)
        {
            count++;
        }
    }
    if (count==n)
    {
        return 1;
    }
    while (true) {
        for (i=0;i<n;i++)
        {
            if (number[i]%divides==0 && number[i]!=1)
            {
                return divides;
            }
        } divides++;
    }
}

int calculate_LCD (int num[],int j)
{
    int i,temp_LCD=1;
    for (i=1;i<j;i++)
    {
        temp_LCD=temp_LCD*num[i];
    }
    return temp_LCD;
}

int main ()
{

    int n,i;
    cout << "How many numbers ? : ";
    cin >> n;
    int num[n],num2[n],div_num[100];
    cout << "Input the numbers : \n";
    for (i=0;i<n;i++)
    {
        cout << ">>> ";
        cin >> num[i];
    }
    int j=1,divides=2;
    int LCD;
    cout << "Values: \n" << endl;
    while (true){
        divides=div(num,divides,n);
        if (divides==1){
            LCD=calculate_LCD(div_num,j);
            break;
        }
        div_num[j]=divides;
        cout << divides << "\t";
        for (i=0;i<n;i++)
        {
            if (num[i]%divides==0)
            {
                num2[i]=num[i]/divides;
            }
            else
            {
                num2[i]=num[i];
            }
        }
        for (i=0;i<n;i++)
        {
            num[i]=num2[i];
        }
        j++;
    }
    cout << "\n\nLCD=" << LCD << endl;
    return 0;
}
