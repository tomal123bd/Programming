#include <stdio.h>

void date_create (int month[35][35],int year)
{
    int i,j=1;
    for (i=1;i<=7;i++)
    {
        if (i==2){
            if (leap_year(year)==1){
                for (j=1;j<=29;j++){
                    month[2][j]=j;
                } month[2][j]=100;
            }else{
                for (j=1;j<=28;j++){
                    month[2][j]=j;
                } month[2][j]=100;
            }
        } if (i==2) continue;
        if (i%2!=0){
        for (j=1;j<=31;j++)
        {
            month[i][j]=j;
        } month[i][j]=100;
        }else{
        for (j=1;j<=30;j++)
        {
            month[i][j]=j;
        }month[i][j]=100;}
    }
    for (i=8;i<=12;i++)
    {
        if (i%2==0){
        for (j=1;j<=31;j++)
        {
            month[i][j]=j;
        }month[i][j]=100;
        }else{
        for (j=1;j<=30;j++)
        {
            month[i][j]=j;
        }month[i][j]=100;}
    }
}

int leap_year(int year)
{
    if (year%400==0 || (year%100!=0 && year%4==0)){
        return 1;
    }
    return 0;
}

int main ()
{
    int month[35][35];
    int terget_date,terget_month,terget_year;
    int birth_date,birth_month,birth_year;
    int days,months,years;
    int i,j,re_days=0,flag=0;
    printf("Date Month Year\n");
    printf ("Input Terget Date : ");
    scanf ("%d %d %d",&terget_date,&terget_month,&terget_year); printf ("\n");
    printf ("Input Date of Birth : ");
    scanf ("%d %d %d",&birth_date,&birth_month,&birth_year); printf ("\n");
    if (terget_date<birth_date){
        date_create (month,terget_year);
        for (i=1;month[birth_month][i]!=100;i++){
            re_days++;
        }
        terget_date=terget_date+re_days;
        days=terget_date-birth_date;
        flag=1;
    }
    else {
        days=terget_date-birth_date;
    }
    if (flag==1){
        birth_month++;
    }
    if (terget_month<birth_month){
        months=(terget_month+12)-birth_month;
        flag=2;
    }
    else {
        months=terget_month-birth_month;
    }
    if (flag==2) {
        birth_year++;
    }
    years=terget_year-birth_year;
    printf ("Days\tMonths\tYears\n");
    printf("%d\t",days);
    printf ("%d\t",months);
    printf ("%d\n",years);
    return 0;
}
