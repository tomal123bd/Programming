#include <stdio.h>
int main ()
{
    int a[100][100]={{1,2,3},{2,3,2},{3,3,4}};
    int b[100][100],c[100][100],z[100][100],s=0,t=0;
    int i,j,k,l,m,n,o,p,q,r,x=0,y=0,count=1;
    for (k=0;k<3;k++)
    {
        for (l=0;l<3;l++)
        {
            for (i=0,m=0;i<3;i++)
            {
                if (i==k)
                {
                    continue;
                }
                for (j=0,n=0;j<3;j++)
                {
                    if (j==l)
                    {
                        continue;
                    }
                    else
                    {
                        b[m][n]=a[i][j];
                        printf("%d ",b[m][n]);
                        n++;
                    }
                }
                m++;
                printf ("\n");
            }
            for (o=0,q=1;o<2;o++,q--)
            {
                for (p=0,r=1;p<2;p++,r--)
                {
                    /*printf("%d\t",b[o][p]);*/
                    c[o][p]=b[o][p]*b[q][r];
                    printf("%d\t",c[o][p]);
                }
                break;
            }
            printf( " \n " );
            for (o=0;o<1;o++)
            {
                for (p=0;p<2;p++)
                {
                        x=c[o][p];
                        y=-y-x;
                }printf("%d",y);
                z[s][t]=y;t++;
            }x=0;y=0;
            printf ("\n\n\n");
        }t=0;s++;
    }
    for (i=0;i<3;i++)
    {
        for (j=0;j<3;j++)
        {
            if (count%2!=0)
            {
                printf ("%d\t",z[i][j]);
            }
            else
            {
                printf ("%d\t",-1*z[i][j]);
            }
            count++;
        }
        printf ("\n");
    }
    getch();
    return 0;
}
