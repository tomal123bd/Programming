#include<bits/stdc++.h>
#include <math.h>
using namespace std;
int priority_check(char c);
string change_equ(string ini_equ,string final_equ)
{
    char c;
    int i,p;
    final_equ="";
    stack <char> stk_value;
    for (i=0;ini_equ[i];i++){
        c=ini_equ[i];
        if (c=='(') stk_value.push(c);
        else if (c==')'){
            while (!stk_value.empty() && stk_value.top()!='('){
                final_equ=final_equ+stk_value.top();
                stk_value.pop();
            }
            if (!stk_value.empty() && stk_value.top()=='(') stk_value.pop();
        }
        else {
           p=priority_check(c);
           if (p==0) final_equ=final_equ+c;
           else {
                if (stk_value.empty()) stk_value.push(c);
                else {
                    while (!stk_value.empty() && stk_value.top()!='(' && p<=priority_check(stk_value.top())){
                        final_equ=final_equ+stk_value.top();
                        stk_value.pop();
                    }
                    stk_value.push(c);
                }
           }
        }
    }
    while (!stk_value.empty()){
        final_equ+=stk_value.top();
        stk_value.pop();
    }
    return final_equ;
}
int priority_check(char c)
{
    if (c=='^') return 3;
    if (c=='/' || c=='*') return 2;
    if (c=='+' || c=='-') return 1;
    return 0;

}
int calculate_value(int a,int b,char c)
{
    if (c=='^') return pow(a,b);
    if (c=='/') return a/b;
    if (c=='*') return a*b;
    if (c=='-') return a-b;
    if (c=='+') return a+b;
}
int equ_evaluation(string final_equ)
{
    stack <int> stk_value;
    int i,x,y;
    char c;
    for (i=0;final_equ[i];i++){
        c=final_equ[i];
        if (c>='0' && c<='9') stk_value.push(c-'0');
        else {
            x=stk_value.top();
            stk_value.pop();
            y=stk_value.top();
            stk_value.pop();
            stk_value.push(calculate_value(y,x,c));
        }
    }
    return stk_value.top();
}
int main()
{
    string ini_equ="(1+(2^3)*4)/3",final_equ;
    final_equ=change_equ(ini_equ,final_equ);
    cout<< ini_equ << endl;
    cout<< final_equ << endl;
    int equ_result=equ_evaluation(final_equ);
    cout<< "Result: " << equ_result << endl;
    return 0;
}
