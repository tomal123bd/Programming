#include <stdio.h>
#define max_size 100
int stack[max_size] , last_in=-1;
void push(int value)
{
    if (last_in>=max_size) printf ("Stack Full\n");
    else {
        last_in++;
        stack[last_in]=value;
        printf ("%d successfully inserted\n",stack[last_in]);
    }
}
void pop()
{
    if (last_in<0) printf ("Stack Empty\n");
    else {
        printf ("%d successfully removed\n",stack[last_in]);
        last_in--;
    }
}
void peek()
{
    if (last_in<0) printf ("Stack Empty\n");
    else printf ("Peek : %d\n",stack[last_in]);
}
void print_stack_values()
{
    if (last_in<0) printf ("Stack Empty\n");
    else {
        int i;
        printf ("Values: ");
        for (i=last_in;i>=0;i--) printf ("%d ",stack[i]);
        printf ("\n");
    }
}
int main ()
{
    int x=1;
    push(x++);push(x++);push(x++);push(x++);push(x++);
    print_stack_values();
    peek();
    pop();pop();pop();pop();pop();
    print_stack_values();
    return 0;
}
