#include <stdio.h>
int size=100;
int h=0,t=-1;
int q[100];
void enqueue(int value)
{
    if (t==size){
        printf ("Queue is full\n");
        return;
    }
    t++;
    q[t]=value;
    printf ("%d successfully inserted\n",q[t]);
}
int dequeue()
{
    if (h==size){
        printf ("Queue is empty\n");
        return;
    }
    int i,temp=q[0];
    for (i=0;i<=t;i++) q[i]=q[i+1];
    t--;
    printf ("%d successfully removed\n",temp);
}
void prnt()
{
    if (t==0){
        printf ("Queue is empty\n");
        return;
    }
    int i;
    printf ("Values: ");
    for (i=h;i<=t;i++) printf ("%d ",q[i]);
    printf ("\n");
}
int main ()
{
    int x=1;
    enqueue(x++);enqueue(x++);enqueue(x++);enqueue(x++);enqueue(x++);
    prnt();
    dequeue();dequeue();dequeue();
    prnt();
    return 0;
}
