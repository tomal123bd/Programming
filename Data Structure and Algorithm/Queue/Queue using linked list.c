#include <stdio.h>
#include <stdlib.h>
struct q {
    int value;
    struct q *next;
};
struct q *head=NULL,*tail=NULL;
void enqueue(int val)
{
    struct q *temp=(struct q*)malloc(sizeof (struct q));
    temp->value=val;
    temp->next=NULL;
    if (head==NULL) {
        head=temp;
        tail=temp;
    }
    else {
        tail->next=temp;
        tail=temp;
    }
    printf ("%d successfully inserted\n",temp->value);
}
void dequeue()
{
    if (head==NULL) {
        printf ("Queue is empty\n");
        return;
    }
    printf ("%d successfully removed\n",head->value);
    head=head->next;

}
void prnt()
{
    struct q *temp=head;
    if (head==NULL) {
        printf ("Queue is empty\n");
        return;
    }
    printf("Values: ");
    while (temp!=NULL){
        printf("%d ",temp->value);
        temp=temp->next;
    }
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
