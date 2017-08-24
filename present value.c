#include <stdio.h>
#include <math.h>
int main ()
{
     //freopen("input.txt","r",stdin);
     //printf ("%f\n",(float)1 / pow((1 + i),n));
     //printf ("%f\n",((float)1-((float)1/pow(((float)1+i),x)))/i);
     float i,cal;
     int e,n,x;
     printf ("Input 0 for exit any time...\n");
     while (1){
     printf ("Input Rate: \n");
     scanf ("%f",&i); if (i==0) return 0;
     i=i/(float)100;
     printf ("Input Time: \n");
     scanf ("%d",&n); if (n==0) return 0;
     printf ("Input 1 for equal,Input 2 for not equal: \n");
     scanf ("%d",&e); if (e==0) return 0;
     if (e==1){
        cal=pow(((float)1+i),n);
        cal=(float)1/cal;
        cal=(float)1-cal;
        cal=cal/i;
        printf ("%.4f\n",cal);
     }else if (e==2){
        for (x=1;x<=n;x++){
            printf ("%.4f\n",(float)1 / pow((1 + i),x));
        }
     }
     else printf ("Error !\nPlease Try Again\n");
     }
     return 0;
}
