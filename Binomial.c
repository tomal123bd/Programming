#include <stdio.h>
#include <math.h>
void binomial_distribution (float terms[], float a, float x, int n)
{
    int i,r=1;
    float temp=0;
    terms[1]=pow(a,n);
    printf ("%f ",terms[1]);
    for (i=2;i<=n;i++,r++)
    {
        terms[i]=(nCr(n,r)) * (pow(a,n-r)) * (pow(x,r));
        printf(" %f ",terms[i]);
    }
    terms[n+1]=pow(x,n);
    printf ("%f ",terms[n+1]);
    for (i=1;i<=n+1;i++)
    {
        temp=temp+terms[i];
    }
    printf ("\n%f\n",temp);
}

int nCr (int n, int r)
{
    return factorial(n)/(factorial(r)*(factorial(n-r)));
}

int factorial (int n)
{
    int i,f=1;
    for (i=1;i<=n;i++)
    {
        f=f*i;
    }
    return f;
}

int main ()
{
    float a,x;
    int n;
    printf ("Input a: ");
    scanf ("%f",&a);
    printf ("intput x: ");
    scanf ("%f",&x);
    printf ("Input n: ");
    scanf ("%d",&n);
    float terms[n+1];
    binomial_distribution(terms,a,x,n);
    return 0;
}
