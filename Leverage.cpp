#include <iostream>
#include <windows.h>
using namespace std;

double sales_f(float unit)
{
    double sales_price_unit,sales_amount;
    if (unit==0)
    {
        cout << "Sales : ";
        cin >> sales_amount;
        return sales_amount;
    }
    else
    {
        cout << "Sales Price Unit : ";
        cin >> sales_price_unit;
        return sales_price_unit * unit;
    }
}

float vc_f(float unit)
{
    float vc;
    if (unit==0)
    {
        cout << "Variable Cost : ";
        cin >> vc;
        return vc;
    }
    else
    {
        cout << "Variable Cost Per Unit: ";
        cin >> vc;
        return vc * unit;
    }
}

float contribution_f(float sales, float vc)
{
    return sales-vc;
}

float fc_f()
{
    float fc;
    cout << "Fixed Cost: ";
    cin >> fc;
    return fc;
}

float EBIT_f(float contribution, float fc)
{
    return contribution-fc;
}

float interest_f()
{
    float interest_amount,interest_rate;
    cout << "Interest Amount: ";
    cin >> interest_amount;
    cout << "Interest Rate: ";
    cin >> interest_rate;
    if (interest_rate==0)
    {
        return interest_amount;
    }
    else
    {
        return interest_amount * (interest_rate/100);
    }
}

float EBT_f (float EBIT,float interest)
{
    return EBIT - interest;
}

float tax_f(float EBT)
{
    float tax_rate;
    cout << "Tax Rate: ";
    cin >> tax_rate;
    return EBT * (tax_rate / 100);
}

float EAT_f(float EBT,float tax)
{
    return EBT - tax;
}

float DOL_f(float contribution, float EBIT)
{
    return contribution / EBIT;
}

float DFL_f(float EBIT, float EBT)  //PD pending
{
    return EBIT / EBT;
}

float DTL_f(float DOL,float DFL)
{
    return DOL * DFL;
}

int main ()
{
    cout << "Input Unit (Put 0 if not available) : ";
    float unit;
    cin >> unit;
    double sales;
    sales=sales_f(unit);
    cout << sales << endl;

    float vc;
    vc=vc_f(unit);
    cout << vc << endl;

    float contribution;
    contribution=contribution_f(sales,vc);
    cout << contribution << endl;

    float fc;
    fc=fc_f();
    cout << fc << endl;

    float EBIT;
    EBIT=EBIT_f(contribution,fc);
    cout << EBIT << endl;

    float interest;
    interest=interest_f();
    cout << interest << endl;

    float EBT;
    EBT=EBT_f(EBIT,interest);
    cout << EBT << endl;

    float tax;
    tax=tax_f(EBT);
    cout << tax << endl;

    float EAT;
    EAT=EAT_f(EBT,tax);
    cout << EAT << endl;

    float DOL;
    DOL=DOL_f(contribution,EBIT);
    cout << "DOL : " << DOL <<endl;

    float DFL;
    DFL=DFL_f(EBIT,EBT);
    cout << "DFL : " << DFL <<endl;

    float DTL;
    DTL=DTL_f(DOL,DFL);
    cout << "DTL : " << DTL <<endl;
    system("pause");
    return 0;
}
