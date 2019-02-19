#include <stdio.h>
#include <stdlib.h>
struct node {
    int value;
    struct node *right;
    struct node *left;
};
struct node *root=NULL;
void ins(int val)
{
    struct node *temp=(struct node *) malloc(sizeof(struct node));
    temp->right=NULL;
    temp->left=NULL;
    temp->value=val;
    if (root==NULL){
        root=temp;
    }
    else{
        struct node *t=root;
        while (1){
            if (t->value > val){
                if (t->left==NULL){
                    t->left=temp;
                    break;
                }
                else{
                    t=t->left;
                }
            }
            else{
                if (t->right==NULL){
                    t->right=temp;
                    break;
                }
                else{
                    t=t->right;
                }
            }
        }
    }
}
void prnt(struct node *n)
{
    if (n!=NULL){
        prnt(n->left);
        printf ("%d ",n->value);
        prnt(n->right);
    }
}
void srch(int val)
{
    struct node *t=root;
    int flag=0;
    while(1){
        if (val==t->value){
            flag=1;
            break;
        }
        else if (val<=t->value){
            t=t->left;
        }
        else t=t->right;
        if (t==NULL) break;
    }
    if (flag==1) printf("Found\n");
    else printf("Not Found\n");
}
struct node *max_value(struct node *root)
{
    if (root==NULL) return root;
    while (root->right!=NULL){
        root=root->right;
    }
    return root;
}
struct node *min_value(struct node *root)
{
    if (root==NULL) return root;
    while (root->left!=NULL){
        root=root->left;
    }
    return root;
}
int main ()
{
    int x=1;
    ins(5);
    ins(10);
    ins(40);
    ins(9);
    ins(11);
    ins(20);
    ins(16);
    prnt(root);
    srch(11);
    struct node *max,*min;
    max=max_value(root),min=min_value(root);
    printf ("Maximum value: %d\n",max->value);
    printf ("Minimum value: %d\n",min->value);
}
