#include <stdio.h>
int main ()
{
    int n=15,i,j,value;
    int x[n];
    for (i=1;i<=n;i++) x[i]=0;
    for (i=1;i<=n;i++) {
        scanf ("%d",&value);
        x[value]=x[value]+1;
    }
    for (i=1;i<=n;i++){
        if (x[i]!=0){
            for (j=1;j<=x[i];j++) printf ("%d ",i);
        }
    }
    return 0;
}
