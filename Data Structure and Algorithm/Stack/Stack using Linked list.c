#include <stdio.h>
#include <stdlib.h>
#define max_size 100
struct stack{
    int val;
    struct stack *next;
};
struct stack *head=NULL,*tail=NULL;
void push(int value)
{
    struct stack *temp=(struct stack*)malloc(sizeof (struct stack));
    temp->val=value;
    temp->next=NULL;
    if (head==NULL){
        head=temp;
        tail=temp;
    }
    else {
        tail->next=temp;
        tail=temp;
    }
    printf ("%d successfully inserted\n",tail->val);
}
void pop()
{
    struct stack *temp;
    if (head==NULL) printf ("Stack Empty\n");
    else if (head->next==NULL) {
        printf ("%d successfully removed\n",head->val);
        head=NULL;
    }
    else {
        temp=head;
        while (temp->next->next!=NULL) temp=temp->next;
        printf ("%d successfully removed\n",temp->next->val);
        temp->next=NULL;
        tail=temp;
    }
}
void peek()
{
    if (head==NULL) printf ("Stack Empty\n");
    else{
        struct stack *temp=(struct stack*)malloc(sizeof (struct stack));
        temp=head;
        while (temp!=NULL){
            if (temp->next==NULL) printf("Peek : %d\n",temp->val);
            temp=temp->next;
        }
    }
}
void print_stack_values(struct stack *temp)
{
    if (head==NULL) {
        printf ("Stack Empty. Nothing to print.\n");
        return;
    }
    if (temp==NULL) {
        printf("\nValues: ");
        return;
    }
    print_stack_values(temp->next);
    printf ("%d ",temp->val);
}
int main ()
{
    int x=1;
    push(x++);push(x++);push(x++);push(x++);push(x++);
    print_stack_values(head);
    peek();
    pop();pop();pop();pop();pop();pop();
    peek();
    print_stack_values(head);
    return 0;
}
