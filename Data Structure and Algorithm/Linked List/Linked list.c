#include <stdio.h>
#include <stdlib.h>
struct node {
    int value;
    struct node *next;
};
struct node *head=NULL,*tail=NULL;
void insert(int val)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof (struct node));
    temp->value=val;
    temp->next=NULL;
    if (head==NULL){
        head=temp;
        tail=temp;
    }
    else {
        tail->next=temp;
        tail=temp;
    }
}
void p()
{
    struct node *temp;
    temp=head;
    while (temp!=NULL){
        printf ("%d ",temp->value);
        temp=temp->next;
    }
    printf ("\n");
}
void ins_head(int val)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof (struct node));
    temp->value=val;
    temp->next=head;
    head=temp;
}
void ins_tail(int val)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof (struct node));
    temp->value=val;
    temp->next=NULL;
    tail->next=temp;
    tail=temp;
}
void ins_ByKey(int key,int val)
{
    struct node *temp,*new_node;
    temp=head;
    while (temp!=NULL){
        if (temp->value==key){
            new_node=(struct node*)malloc(sizeof (struct node));
            new_node->value=val;
            new_node->next=temp->next;
            temp->next=new_node;
            break;
        }
        temp=temp->next;
    }
}
void del(int val)
{
    struct node *temp,*prev=NULL;
    temp=head;
    while (temp!=NULL){
        if (temp->value==val){
            if (prev==NULL){
                head=temp->next;
            }
            else {
                prev->next=temp->next;
            }
            break;
        }
        prev=temp;
        temp=temp->next;
    }
}
int main ()
{
    int x=1;
    insert(x++);insert(x++);insert(x++);insert(x++);insert(x++);
    p();
    ins_head(0);
    p();
    ins_tail(x++);
    p();
    ins_ByKey(5,10);
    p();
    del(10);
    p();
    return 0;
}
