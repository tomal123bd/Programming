//MA kalam. page > 1126 , problem -43
#include <stdio.h>
//Function of APRc (Annual Percentage Rate)
float APRc (float CD , float CP , float DP)
{
    float APRc;
    APRc=(CD/(100-CD))*(360/(CP-DP))*100;
    return APRc;
}

//Function of EAR
float EAR (float loan,float interest_rate,float CB_rate)
{
    //printf("%f %f %f",loan,interest_rate, CB_rate);
    float total_interest=loan*(interest_rate/100);
    //printf("%f\n",total_interest);
    float CB=loan*(CB_rate/100);
    //printf("%f\n",CB);
    float EAR=(total_interest/(loan-CB))*100;
    return EAR;
}
int main ()
{

    //EAR
    printf ("---EAR---\n\n");
    float E_A_R,loan,interest_rate,CB_rate;
    printf ("Input Loan : ");
    scanf("%f",&loan);
    printf ("Input Interest Rate : ");
    scanf ("%f",&interest_rate);
    printf ("Input CB Rate : ");
    scanf ("%f",&CB_rate);
    E_A_R=EAR(loan,interest_rate,CB_rate);
    //EAR(loan,interest_rate,CB_rate);
    printf (">>> EAR = %.2f\n",E_A_R);
    //printf("%f,%f,%f",loan,interest_rate,CB_rate);
}
    /*//APRc (Annual Percentage Rate)
    printf ("---APRc (Annual Percentage Rate)---\n\n");
    float APRC;
    int CD,CP,DP;
    printf ("Input CD ( Credit Discount ) : ");
    scanf ("%d",&CD);
    printf ("Input CP ( Credit Preiod ) : ");
    scanf ("%d",&CP);
    printf ("Input DP ( Discount Preiod ) : ");
    scanf ("%d",&DP);
    APRC=APRc(CD,CP,DP);
    printf (">>> APRc = %.2f\n",APRC);*/
