/*a program to fiend out GCD (Greater Common Divisor)
#
fiend out 2 numbers M & N 's GCD
ex: 51 & 15 's GCD is 3 . 51 divided by 15 then reminder is 6. now 15 divided by 6 then reminder is 3. again 6 bivided by 3 then reminder is 0. so last number is 3 , it is GCD*/
#include <stdio.h>
int main ()
{
    int M,N,reminder;
    printf("Input M: ");
    scanf("%d",&M);
    printf("Input N: ");
    scanf("%d",&N);
    while (M<=N)
    {printf("N must be smaller then M.\nInput M: ");
    scanf("%d",&M);
    printf("Input N: ");
    scanf("%d",&N);}
    reminder=M%N;
    while (reminder!=0)
    {
        M=N;
        N=reminder;
        reminder=M%N;
    }
    printf("-----\n");
    printf("GCD: %d",N);
    getch();
    return 0;
}
