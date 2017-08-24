#include <stdio.h>
int main ()
{
    int x[100][100];
    int i,j,row,column;
    printf ("Inpur the total number of row : ");
    scanf ("%d",&row);
    printf ("Input the total number of column : ");
    scanf ("%d",&column);
    printf ("Input the elements of Matrix accroding to row wise one by one : \n");
    for (i=0;i<row;i++)
    {
        for (j=0;j<column;j++)
        {
            printf (">>>");
            scanf ("%d",&x[i][j]);
        }
    }
    int y[100][100];
    for (i=0;i<row;i++)
    {
        for (j=0;j<column;j++)
        {
            y[j][i]=x[i][j];
        }
    }
    for (i=0;i<column;i++)
    {
        for (j=0;j<row;j++)
        {
            printf ("%d\t",y[i][j]);
        }
        printf ("\n");
    }
    getch();
    return 0;
}
