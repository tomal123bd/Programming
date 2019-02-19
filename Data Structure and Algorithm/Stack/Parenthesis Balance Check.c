#include <stdio.h>
#include <string.h>
#define max_size 100
char stack[max_size] , last_in=-1;
void push(char value)
{
    if (last_in>=max_size) printf ("Stack Full\n");
    else {
        last_in++;
        stack[last_in]=value;
    }
}
void pop()
{
    last_in--;
}
int empty()
{
    if (last_in<0) return 1;
    else return 0;
}
int main ()
{
    char s[]="(()(()))";
    int i,flag=1;
    for (i=0;i<strlen(s);i++){
        if (!empty() && stack[last_in]=='(' && s[i]==')') pop();
        else push(s[i]);
    }
    if (!empty()) printf("Not balanced.\n");
    else printf("Balanced.\n");
    return 0;
}
