#include <stdio.h>

void date_create (int month[400][400],int year)
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

void calculate_age (int age[],int days)
{
    while (365<days)
    {
        days=days-365;age[0]++;
    }
    while (30<days)
    {
        days=days-30;age[1]++;
    }
    age[2]=days;
}

int main ()
{
    int month[400][400],age[3];
    //char week[8][4]={"err","sat","sun","mon","tue","wed","thu","fri"};
    int i,j=1,week_2=3,week_rem=7;
    //int start_year=1900,year=2099;
    int days=0,flag=0;
    int inp_date,inp_month,inp_year;
    int inp_date_end,inp_month_end,inp_year_end;
    scanf("%d %d %d",&inp_date,&inp_month,&inp_year);
    scanf("%d %d %d",&inp_date_end,&inp_month_end,&inp_year_end);
    int start_year=inp_year,year=inp_year_end;
    int temp_year=0,temp_month=0,temp_date=0,temp_flag=0;
    /*for (i=1;i<=8;i++)
    {
        printf("%s\t",week[i]);
    } printf("\n");printf("\t\t");*/
    for (;year>=start_year;start_year++)
    {
        date_create(month,start_year);
        for (i=1;i<=12;i++)
        {
            for (j=1;month[i][j]!=100;j++,week_2++)
            {
                //printf ("%d\t",month[i][j]);
                if (j==inp_date && i==inp_month && start_year==inp_year){flag=1;}
                if (j==inp_date_end && i==inp_month_end && start_year==inp_year_end){flag=2;}
                if (flag==2){ break; }
                if (flag==1) {days++;}
                /*if (week_2==7)
                {
                    printf("\n");
                    week_2=0;
                }*/
            }//week_rem=week_2;
            //printf("\n\n");
            /*while (week_rem!=1){
                printf("\t");
                week_rem--;
            }*/
        }
    }
    /* ********* */
    /*printf("\n");
    for (i=1;i<=8;i++)
    {
        printf("%s\t",week[i]);
    }*/
    printf("\n%d\n",days);
    age[0]=0;age[1]=0;age[2]=0;
    //printf("years\tmonths\tdays\n");
    //calculate_age (age,days);
    /*for (i=0;i<3;i++)
    {
        if (age[i]!=0)
        {
            printf("%d\t",age[i]);
        }
    }*/
    //getch();
    return 0;
}
