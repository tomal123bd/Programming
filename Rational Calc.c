#include <stdio.h>
typedef struct {
    int p;
    int q;
} rational;

void frac_div(rational *result)
{
    int x=result->p;
    int y=result->q;
    if (x==0 || y==0) return;
    if (x<0 || y<0){
        printf ("(Minus) ");
        if(x<0) x=(x*-2)+x;
        if(y<0) y=(y*-2)+y;
    }
    int i,d=2;
    while (1){
        if (d>=x || d>=y){
            if (y%x==0){
                y=y/x;
                x=x/x;
            }else if (x%y==0){
                x=x/y;
                y=y/y;
            }
            result->p=x;
            result->q=y;
            break;
        }
        if (x%d==0 && y%d==0){
            x=x/d;
            y=y/d;
        }else {
            d++;
        }
    }
}

void mul(rational n1,rational n2,rational *result)
{
    result->p=n1.p*n2.p;
    result->q=n1.q*n2.q;
    frac_div(result);
}

void div(rational n1,rational n2,rational *result)
{
    int swap;
    swap=n2.q;
    n2.q=n2.p;
    n2.p=swap;
    result->p=n1.p*n2.p;
    result->q=n1.q*n2.q;
    frac_div(result);
}

int lcd(int num1,int num2)
{
    int i,div=2,x=1;
    while (1){
        if (div>num1 && div>num2){
            x=x*num1*num2;
            break;
        }else if (num1%div==0 && num2%div==0){
                x=x*div;
                num1=num1/div;
                num2=num2/div;
        }
        else div++;
    }
    return x;
}



void add(rational n1,rational n2,rational *result)
{
    result->q= lcd(n1.q,n2.q);
    n1.p=(result->q/n1.q)*n1.p;
    n2.p=(result->q/n2.q)*n2.p;
    result->p=n1.p+n2.p;
    frac_div(result);
}


void sub(rational n1,rational n2,rational *result)
{
    result->q= lcd(n1.q,n2.q);
    n1.p=(result->q/n1.q)*n1.p;
    n2.p=(result->q/n2.q)*n2.p;
    result->p=n1.p-n2.p;
    frac_div(result);
}
int main ()
{
    rational n1,n2,result;
    /*n1.p=10,n1.q=20;
    n2.p=30,n2.q=40;*/
    printf ("Input p and q for first rational number (space for each num): ");
    scanf ("%d %d",&n1.p,&n1.q);
    printf ("Input p and q for second rational number (space for each num): ");
    scanf ("%d %d",&n2,&n2.q);
    printf("%d , %d\n",n1.p,n2.p);
    printf("--   --\n");
    printf("%d , %d\n\n",n1.q,n2.q);
    mul(n1,n2,&result);
    printf("Multiply: %d/%d = %f\n",result.p,result.q,(float)result.p/result.q);
    div(n1,n2,&result);
    printf("Divide: %d/%d = %f\n",result.p,result.q,(float)result.p/result.q);
    add(n1,n2,&result);
    printf("Add: %d/%d = %f\n",result.p,result.q,(float)result.p/result.q);
    sub(n1,n2,&result);
    printf("Subtract: %d/%d = %f\n",result.p,result.q,(float)result.p/result.q);
    return 0;
}
