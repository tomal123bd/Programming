#include <stdio.h>
int size=100;
int t=-1;
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
    if (t==0){
        printf ("Queue is empty\n");
        return;
    }
    int i,temp=q[0];
    for (i=0;i<=t;i++) q[i]=q[i+1];
    t--;
    printf ("%d successfully removed\n",temp);
}
void enqueue_front(int value)
{
    if (t==size){
        printf ("Queue is full\n");
        return;
    }
    int i;
    for (i=t;i>=0;i--) q[i+1]=q[i];
    q[0]=value;
    t++;
    printf ("%d successfully inserted into the front\n",q[0]);
}
void dequeue_back()
{
    if (t==0){
        printf ("Queue is empty\n");
        return;
    }
    printf ("%d successfully removed from the back\n",q[t]);
    t--;
}
void prnt()
{
    if (t==0){
        printf ("Queue is empty\n");
        return;
    }
    int i;
    printf ("Values: ");
    for (i=0;i<=t;i++) printf ("%d ",q[i]);
    printf ("\n");
}
int main ()
{
    int x=1;
    enqueue(x++);enqueue(x++);enqueue(x++);enqueue(x++);enqueue(x++);
    prnt();
    dequeue();dequeue();dequeue();
    prnt();
    enqueue_front(x++);enqueue_front(x++);
    prnt();
    dequeue_back();dequeue_back();
    prnt();
    return 0;
}
