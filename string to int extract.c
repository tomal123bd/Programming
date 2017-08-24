#include <stdio.h>
#include <string.h>
int extract_int_values (char input_string[],int int_values[])
{
    int i,j=0,f=0,flag=0;
    char temp[10];
    for (i=0;i<=strlen(input_string);i++){
        if (input_string[i]>=48 && input_string[i]<=57){
            temp[j]=input_string[i]; j++; flag=1;
            continue;
        }
        if (flag==1){
            temp[j]='\0'; j=0;
            int_values[f]=atoi(temp); f++; flag=0;
        }
    }
    return f;
}

int main ()
{
    char input_string[1000];
    gets(input_string);
    int int_values[10];
    int found=extract_int_values(input_string,int_values);
    printf("found %d\n",found);
    int i;
    for (i=0;i<found;i++){
        printf ("%d\n",int_values[i]);
    }
}
