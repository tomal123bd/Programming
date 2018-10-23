#include <stdio.h>
long long factorial(int value)
{
    long long i,f=1;
    for (i=1;i<=value;i++) f=f*i;
    return f;
}
long long nCr_f(int n,int r)
{
    return factorial(n)/(factorial(r)*factorial(n-r));
}
long long nPr_f(int n,int r)
{
    return factorial(n)/factorial(n-r);
}
int main ()
{
    int n,r;
    long long nCr,nPr;
    while (1){
        printf ("Input n 0 to exit\n");
        printf ("Input n space/enter r : ");
        scanf ("%d %d",&n,&r);
        if (n==0) break;
        if (n>=r){
            nCr=nCr_f(n,r);
            nPr=nPr_f(n,r);
            printf ("nCr: %lld\nnPr: %lld\n",nCr,nPr);
        }
        else printf ("n must be greater then r.\n");
    }
    return 0;
}
