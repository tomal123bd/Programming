/*
      1
     1 1
    1 2 1
   1 3 3 1
  1 4 6 4 1   */


#include <stdio.h>
int main ()
{
    int N;
    printf ("Input Row: ");
    scanf ("%d",&N);
    int triangle[N];
    int temp[N];
    int i,k,l,s;
    for (s=0;s<N;s++)
    {
        printf (" ");
    }
    printf ("1\n");
    for (i=1;i<N;i++)
    {
        temp[1]=1;
        for (k=1;k<i;k++)
        {
            temp[k+1]=triangle[k]+triangle[k+1];
        }
        temp[k+1]=1;
        for (s=N-1;s>=i;s--)
        {
            printf (" ");
        }
        for (l=1;l<=k+1;l++)
        {
            triangle[l]=temp[l];
            printf ("%d ",triangle[l]);
        }
        printf ("\n");
    }
    getch();
    return 0;
}
