#include <stdio.h>
#define MAX 100
int par[MAX];
int size = 5;

/*void mrk(int n)
{
    par[n]=n;
}*/

int f(int v)
{
    /*if (par[v]==v) return v;
    return f(par[v]);*/
    while(1){
        if (par[v]==v) return v;
        v=par[v];
    }
}

void U(int x,int y)
{
    int a=f(x);
    int b=f(y);
    if (a==b) printf("Already friends \n");
    else par[a]=b;
}

int main ()
{
    int i;
    for (i=0;i<size;i++) par[i]=i;// mrk(i);
    U(2,3);U(2,3);U(2,4);U(2,4);
    //for (i=0;i<size;i++) printf("%d ",par[i]);
}
