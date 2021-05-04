#include <stdio.h>
#include <string.h>
int main ()
{
    int num=2;
    int i,len;
    char x[1000]="hello world";
    char y[1000];
    len=strlen(x);
    for (i=0;i<len;i++){
        y[i]=x[i]+num;
    }
    printf ("%s\n",y);
}
