/*a simple BMI Calculator program.
# BMI (body mass index) = weight/ height: meter*meter ( 1feet=.3048 meter) */
#include <stdio.h>
int main ()
{
    printf("-----BMI (Body Mass Index) Categories-----\n");
    printf("1. Under 18 :- Low.\n");
    printf("2. 18 to 25 :- Normal.\n");
    printf("3. 25 to 30 :- High.\n");
    printf("4. Over 30 :- Very High.\n");
    printf("---\n");
    float weight,height,meter,bmi;
    printf("Input Your Weight (KG): ");
    scanf("%f",&weight);
    printf("Input Your Height (in feet): ");
    scanf("%f",&height);
    meter=height*(float).3048;
    bmi=weight/(meter*meter);
    printf("*****\n");
    printf("Your BMI rate is : %.2f\n",bmi);
    printf("*****\n");
    printf("Your BMI Condition: ");
    if (bmi<18)
    {
        printf("LOW");
    }
    if (bmi>=18 && bmi<=25)
    {
        printf("NORMAL");
    }
    if (bmi>25 && bmi<=30)
    {
        printf("HIGH");
    }
    if (bmi>30)
    {
        printf("VERY HIGH");
    }
    getch();
    return 0;
}
