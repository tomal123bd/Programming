#include <stdio.h>
int main ()
{
    int a[100][100],b[100][100];
    int c,d,e;
    int i,j,k;
    int f=0,g;
    printf("Input total number of row of first matrix : ");
    scanf ("%d",&c);
    printf("Input total number of column of first matrix : ");
    scanf ("%d",&d);
    printf("Input the elements of first matrix according to row respectively . (press enter for per entry): \n");
    for (i=0;i<c;i++)
    {
        for (j=0;j<d;j++)
        {
            printf(">>> ");
            scanf ("%d",&a[i][j]);
        }
    }
    printf("Input total number of column of second matrix : ");
    scanf ("%d",&e);
    printf("Input the elements of first matrix according to row respectively . (press enter for per entry) : \n");
    for (i=0;i<d;i++)
    {
        for (j=0;j<e;j++)
        {
            printf(">>> ");
            scanf ("%d",&b[i][j]);
        }
    }
    /*-------------*/
    FILE *fp;
    fp=fopen("myfile.txt","w");
    printf("\n******\n\n");
    for (i=0;i<c;i++)
    {
        for (j=0;j<e;j++)
        {
            for (k=0;k<d;k++)
            {
                g=a[i][k]*b[k][j];
                f=f+g;
            }
            printf ("%d\t",f);
            fprintf (fp,"%d\t",f);
            f=0;
        }
        printf ("\n");
        fprintf (fp,"\n");
    }
    getch();
    return 0;

}
