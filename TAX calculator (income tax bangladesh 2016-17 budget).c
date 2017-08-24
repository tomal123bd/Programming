#include <stdio.h>
int main ()
{
    double income,remaining,tax=0,diff[6];
    scanf ("%lf",&income);
    if (income>=0 && income<=250000) {
        printf("No Tax.\n");
        return 0;
    }
    diff[0]=250000;
    if (income>250000){
        diff[1]=400000-250000;
        if (income>400000){
            tax=tax+(diff[1]*.10);
        }
        else {
            remaining=income-(diff[0]);
            tax=tax+(remaining*.10);
        }
    }
    if (income>400000){
        diff[2]=500000-400000;
        if (income>500000){
            tax=tax+(diff[2]*.15);
        }
        else {
            remaining=income-(diff[0]+diff[1]);
            tax=tax+(remaining*.15);
        }
    }
    if (income>500000){
        diff[3]=600000-500000;
        if (income>600000){
            tax=tax+(diff[3]*.20);
        }
        else {
            remaining=income-(diff[0]+diff[1]+diff[2]);
            tax=tax+(remaining*.20);
        }
    }
    if (income>600000){
        diff[4]=3000000-600000;
        if (income>3000000){
            tax=tax+(diff[3]*.25);
        }
        else {
            remaining=income-(diff[0]+diff[1]+diff[2]+diff[3]);
            tax=tax+(remaining*.25);
        }
    }
    /*bug in next calculation,need to check actual budget calculation manually*/
    if (income>3000000){
        remaining=income-(diff[0]+diff[1]+diff[2]+diff[3]+diff[4]);
        tax=tax+(remaining*.30);
    }
    /*---*/
    printf("TK %.2lf\n",tax);
    return 0;
}
