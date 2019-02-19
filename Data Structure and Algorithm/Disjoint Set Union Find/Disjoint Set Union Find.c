#include <stdio.h>
#define Max 100

int par[Max];
int size=6;
void makeSet(int n)
{
    par[n]=n;
}

int Find(int r)
{
    //printf("\n%d %d\n",r,par[r]);
    if (par[r] == r)
    {
        return r;
    }
    return Find(par[r]);
    //return par[r] = Find(par[r]);
}
void Union(int a,int b)
{
    int u = Find(a);
    int v = Find(b);
    if(u == v)
    {
        printf("They are already friends\n");
    }
    else par[u]=v;
}
int main()
{
    int i;
    for (i=0; i < size; i++)
    {
        makeSet(i);
    }
    for (i=0;i<size;i++) printf ("%d",par[i]);
    printf ("\n");
    Union(2,3);
    for (i=0;i<size;i++) printf ("%d",par[i]);
    printf ("\n");
    Union(2,3);
    for (i=0;i<size;i++) printf ("%d",par[i]);
    printf ("\n");
    Union(3,4);
    for (i=0;i<size;i++) printf ("%d",par[i]);
    printf ("\n");
    Union(3,4);
    for (i=0;i<size;i++) printf ("%d",par[i]);
    printf ("\n");
    return 0;
}
