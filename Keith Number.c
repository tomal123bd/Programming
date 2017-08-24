#include <stdio.h>
#include <string.h>
void n_to_s(long long num,char str[]) /*convert number to string*/
{
    //int num=1;
    long long dev,re,i=0,j;
    //char str[100];
    char temp;
    while (1){
        if (num<10){
            str[i]=num+48;
            str[i+1]='\0';
            break;
        }
        re=num%10;
        str[i]=re+48;
        num=num/10;
        i++;
    }
    for (i=0,j=strlen(str)-1;i<strlen(str)/2;i++,j--){
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
    }
    //printf ("%s\n",str);
}

long long str_sum (char str[],long long ar[]) /*string to sum*/
{
    long long sum=0;
    int i;
    for (i=0;str[i]!='\0';i++){
        ar[i]=(str[i]-48);
        sum=sum+(str[i]-48);
        //printf ("%lld",sum);
    }//ar[0]=sum;
    return sum;
}

long long sum (long long ar[],long long ar_len)
{
    long long i,total=0;
    for (i=0;i<ar_len;i++){
        total=total+ar[i];
    }
    return total;
}

int main ()
{
    long long n=1362353777290081176;
    char str[100];
    n_to_s(n,str);
    long long temp_n,ar_len=strlen(str),i,total=0;
    long long temp2,temp;
    long long ar[ar_len];
    str_sum(str,ar);
    while (total<=n){
        total=sum(ar,ar_len);//printf ("\ntotal %lld\n",total);
        if (total==n){
            printf ("\nok\n");
            break;
        }
        else{
            for (i=0;i<ar_len;i++){
                ar[i]=ar[i+1];
            }
            ar[ar_len-1]=total;
        }
    }
    //n_to_s(n,str);
    //temp_n=str_sum(str);
    //printf ("%lld",str_sum(str));
    //if (n==temp_n)printf ("\nok!!!\n");
}
