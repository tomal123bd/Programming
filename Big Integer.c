#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "Big_Integer_Define.h"
#define array_declare char n1[10000];char n2[10000];char n3[10000];char n4[10000];char n5[10000]; \
char m_n[10000][10000];char num_strcmp_n1[10000];char num_strcmp_n2[10000]; \
char div_temp[10000];char div_re[10000];char div_quo[10000];char div_point[10000];char div_n2_temp[10000];char n3_temp[10000];
#define check_point 1

array_declare

/* Function Prototype */
int add_point(char n1[],char n2[]);
void add(char n1[],char n2[],char n3[]);
void zero_omit (char n3[]);
void sub(char n1[],char n2[],char n3[]);
void sign_sub(char n1[],char n2[],char n3[]);
void sign_add(char n1[],char n2[],char n3[]);
/*---*/
void mul(char n1[],char n2[],char n3[])
{
    zero_omit(n1);zero_omit(n2); /*omit zero if any zero found in left in the array */
    int i,j,k,l,carry=0,n1_int,n2_int,result,re,temp,flag=0;
    int point_location=-1,n1_point_location=1,n2_point_location=1,count;
    int n1_sign=0,n2_sign=0,sign_flag=0;;
    /*sign checking and flagging*/
    if (n1[0]=='-'){
        j=strlen(n1);
        for (i=0;i<=j;i++) n1[i]=n1[i+1];
        n1_sign=1;
    }
    if (n2[0]=='-'){
        j=strlen(n2);
        for (i=0;i<=j;i++) n2[i]=n2[i+1];
        n2_sign=1;
    }
    /*if only one array have negative sign then n3 will be negative*/
    if (n1_sign==1 ^ n2_sign==1) sign_flag=1;
    /*point checking, point location calculation and point erase(define 0 if having no point)*/
    if (check_point){
        /*if point location in 0 th index, add extra zero before the point*/
        if (n1[0]=='.'){
            j=strlen(n1);
            for (i=j;i>=0;i--){
                n1[i+1]=n1[i];
            }
            n1[0]='0';
        }
        if (n2[0]=='.'){
            j=strlen(n2);
            for (i=j;i>=0;i--){
                n2[i+1]=n2[i];
            }
            n2[0]='0';
        }
        /*counting point location*/
        for (i=strlen(n1),count=0;i>=0;i--,count++){
            if (n1[i]=='.'){
                n1_point_location=count;
                flag=1;
                k=strlen(n1);
                /*point erase*/
                for (j=i;j<=k;j++){
                    n1[j]=n1[j+1];
                }
                break;
            }
        }
        for (i=strlen(n2),count=0;i>=0;i--,count++){
            if (n2[i]=='.'){
                n2_point_location=count;
                flag=1;
                k=strlen(n2);
                /*point erase*/
                for (j=i;j<=k;j++){
                    n2[j]=n2[j+1];
                }
                break;
            }
        }
        if (flag==1) point_location=n1_point_location+n2_point_location;
    }
    /*normal multiply*/
    for (i=strlen(n2)-1,k=0;i>=0;i--,k++) {
        flag=0;
        for (j=strlen(n1)-1,l=0;j>=0;j--,l++) {
            /*insert zero form left side*/
            for (temp=0;temp<k && flag==0;temp++) {
                m_n[k][l]='0';l++;
            }flag=1;

            n1_int=(n1[j]-48);
            n2_int=(n2[i]-48);
            result=(n1_int*n2_int)+carry;
            if (result>=10) {
                m_n[k][l]=(result%10)+48;
                carry=result/10;
            }
            else {
                m_n[k][l]=result+48;
                carry=0;
            }
        }
        if (carry>0) {
            m_n[k][l]=carry+48;l++;
            m_n[k][l]='\0';
        }
        else {
            m_n[k][l]='\0';
        }
        carry=0;
    }
    /*reverse each array*/
    for (i=0;i<strlen(n2);i++) {
        strrev(m_n[i]);
    }
    /*addition each string array*/
    strcpy(m_n[strlen(n2)],m_n[0]);
    strcpy(n3,m_n[strlen(n2)]);
    for (i=1;i<strlen(n2);i++) {
        add(m_n[strlen(n2)],m_n[i],n3);
        strcpy(m_n[strlen(n2)],n3);
    }
    /*point checking*/
    j=strlen(n3);
    if (point_location!=-1){
        for (i=j,count=0;count<point_location-1;i--,count++){
            n3[i+1]=n3[i];
        }
        n3[i+1]='.';
    }
    /*sing checking*/
    if (sign_flag){
        for (i=strlen(n3);i>0;i--) n3[i]=n3[i-1];
        n3[i]='-';
    }
}

void ar_eql(char n1[],char n2[]) /*function for equal both array by adding zero in left for add function*/
{
    int n1_length=strlen(n1);
    int n2_length=strlen(n2);
    int length_re,i;
    if (n1_length>n2_length){
        length_re=n1_length-n2_length;
        for (i=(strlen(n2));i>=0;i--){
            n2[n1_length]=n2[i];
            n1_length--;
        }
        for (i=0;i<length_re;i++){
            n2[i]='0';
        }
    }
    else if (n1_length<n2_length) {
        length_re=n2_length-n1_length;
        for (i=(strlen(n1));i>=0;i--){
            n1[n2_length]=n1[i];
            n2_length--;
        }
        for (i=0;i<length_re;i++){
            n1[i]='0';
        }
    }
}

int add_point(char n1[],char n2[])
{
    int n1_point_location=-1,n2_point_location=-1,i,j,count=0,return_point;
    int n1_length=strlen(n1),n2_length=strlen(n2),n1_point_length,n2_point_length;
    /*find out point location*/
    for (i=0;i<n1_length;i++){
        if (n1[i]=='.'){
            n1_point_location=i;
            break;
        }
    }
    for (i=0;i<n2_length;i++){
        if (n2[i]=='.'){
            n2_point_location=i;
            break;
        }
    }
    /*add point if no point found in a array*/
    if (n1_point_location==-1){
        n1[n1_length]='.';
        n1[n1_length+1]='\0';
        n1_point_location=n1_length;
    }
    if (n2_point_location==-1){
        n2[n2_length]='.';
        n2[n2_length+1]='\0';
        n2_point_location=n2_length;
    }
    /*point length form end of the array*/
    for (i=strlen(n1)-1;i>n1_point_location;i--) count++;
    n1_point_length=count;
    count=0;
    for (i=strlen(n2)-1;i>n2_point_location;i--) count++;
    n2_point_length=count;

    n1_length=strlen(n1);
    n2_length=strlen(n2);
    /*add zero form the point based on the other array*/
    if (n1_point_length>n2_point_length){
        for (i=0;i<n1_point_length-n2_point_length;i++){
            n2[n2_length+i]='0';
        }
        n2[n2_length+i]='\0';
    }
    if (n2_point_length>n1_point_length){
        for (i=0;i<n2_point_length-n1_point_length;i++){
            n1[n1_length+i]='0';
        }
        n1[n1_length+i]='\0';
    }
    /*reserve point location for return*/
    for (i=strlen(n1),count=0;i>=0;i--,count++){
        if (n1[i]=='.'){
            return_point=count;
            break;
        }
    }
    /*erase point*/
    n1_length=strlen(n1);
    n2_length=strlen(n2);
    for (i=n1_point_location;i<=n1_length;i++){
        n1[i]=n1[i+1];
    }
    for (i=n2_point_location;i<=n2_length;i++){
        n2[i]=n2[i+1];
    }
    /*normal addition*/
    return return_point;
}

void sign_adding(int n1_sign,int n2_sign,int n1_big,int n2_big) /*sing adding function according to big number*/
{
    /*if the small number have minus sign or big number have no sign then do nothing*/
    int i;
    if (n1_sign==1 && n1_big==1){
        for (i=strlen(n3);i>0;i--) n3[i]=n3[i-1];
        n3[i]='-';
    }
    else if (n2_sign==1 && n2_big==1){
        for (i=strlen(n3);i>0;i--) n3[i]=n3[i-1];
        n3[i]='-';
    }
}

void add(char n1[],char n2[],char n3[])
{
    zero_omit(n1);zero_omit(n2); /*omit zero if any zero found in left in the array */
    int i,j,carry=0,n1_int,n2_int,result,re,point_location=-1,count; /*return value will return 0 if point location found in 0 index in the array*/
    char  temp,temp2;
    int n1_sign,n2_sign,n1_big,n2_big,sign_flag=0;
    /*sign calculation. if n1 or n2 any only one have negative sign then subtraction*/
    if (n1[0]=='-' ^ n2[0]=='-'){
        if (n1[0]=='-'){
            for (i=0;i<=strlen(n1);i++) n1[i]=n1[i+1];
            n1_sign=1;
            n2_sign=0;
            n1_big=num_strcmp(n1,n2);
        }
        if (n2[0]=='-'){
            for (i=0;i<=strlen(n2);i++) n2[i]=n2[i+1];
            n2_sign=1;
            n1_sign=0;
            n2_big=num_strcmp(n2,n1);
        }
        sign_sub(n1,n2,n3);
        /*sign add according to the big number*/
        sign_adding(n1_sign,n2_sign,n1_big,n2_big);
        return; /*no more addition process required*/
    }
    /*if n1 or n2 both have negative sign then normal addition with minus sign*/
    if (n1[0]=='-' && n2[0]=='-'){
        for (i=0;i<=strlen(n1);i++) n1[i]=n1[i+1];
        for (i=0;i<=strlen(n2);i++) n2[i]=n2[i+1];
        sign_flag=1;
    }
    /*turn off this if there have no possibility having point in array*/
    if (check_point){
        for (i=0;i<strlen(n1);i++){
            if (n1[i]=='.'){
                point_location=add_point(n1,n2);
                break;
            }
        }
        for (i=0;i<strlen(n2) && point_location==-1;i++){
            if (n2[i]=='.'){
                point_location=add_point(n1,n2);
                break;
            }
        }
    }
    /*normal addition*/
    if (strlen(n1)!=strlen(n2)) ar_eql(n1,n2);
    for (i=strlen(n1)-1,j=0;i>=0;i--,j++){
        n1_int=(n1[i]-48)+carry;
        n2_int=n2[i]-48;
        result=n1_int+n2_int;
        if (result>=10){
            n3[j]=(result%10)+48;
            carry=1;
        }
        else {
            n3[j]=result+48;
            carry=0;
        }
    }
    if (carry==1) {
        n3[j]=carry+48;j++;
        n3[j]='\0';
    }
    else n3[j]='\0';
    strrev(n3);
    /*point checking*/
    j=strlen(n3);
    if (point_location!=-1){
        for (i=j,count=1;count<=point_location;i--,count++){
            n3[i+1]=n3[i];
        }
        n3[i+1]='.';
    }
    /*sign checking*/
    if (sign_flag){
        for (i=strlen(n3);i>0;i--) n3[i]=n3[i-1];
        n3[i]='-';
    }
}

void sub(char n1[],char n2[],char n3[])
{
    zero_omit(n1);zero_omit(n2); /*omit zero if any zero found in left in the array */
    int i,j,carry=0,n1_int,n2_int,result,re,point_location=-1,count; /*return value will return 0
    if point location found in 0 index in the array*/
    int n1_sign,n2_sign,n1_big,n2_big,sign_flag=0;
    /*turn off this if there have no possibility having point in array*/
    /*point checking start*/
    if (!check_point){
        /*this method would not work in subtraction because
        when it add extra zero in add_point function and equal the array and
        it does not produce correct result in num_strcmp*/
        for (i=0;i<strlen(n1);i++){
            if (n1[i]=='.'){
                point_location=add_point(n1,n2);
                break;
            }
        }
        for (i=0;i<strlen(n2) && point_location==-1;i++){
            if (n2[i]=='.'){
                point_location=add_point(n1,n2);
                break;
            }
        }
    }
    /*point checking end and sign checking start*/
    /*n2 sign change*/
    if (n2[0]=='-'){
        j=strlen(n2);
        for (i=0;i<=j;i++) n2[i]=n2[i+1];
    }
    else {
        j=strlen(n2);
        for (i=j;i>=0;i--) n2[i+1]=n2[i];
        n2[0]='-';
    }
    /*addition if both array have negative sign*/
    if (n1[0]=='-' && n2[0]=='-'){
        for (i=0;i<=strlen(n1);i++) n1[i]=n1[i+1];
        for (i=0;i<=strlen(n2);i++) n2[i]=n2[i+1];
        sign_add(n1,n2,n3);
        sign_flag=1;
        goto jump_a;
    }
    /*addition if both array have no negative sign after calculating erasing sign*/
    if (n1[0]!='-' && n2[0]!='-'){
        sign_add(n1,n2,n3);
        /*calculating sing if both have no sign then addition and no more process required */
        return;
    }
    /*sign calculation. if n1 or n2 any only one have negative sign then subtract*/
    if (n1[0]=='-' ^ n2[0]=='-'){
        if (n1[0]=='-'){
            for (i=0;i<=strlen(n1);i++) n1[i]=n1[i+1];
            /*check which number has sign and calculation for big number for adding sign*/
            n1_sign=1;
            n2_sign=0;
            n1_big=num_strcmp(n1,n2);
        }
        if (n2[0]=='-'){
            for (i=0;i<=strlen(n2);i++) n2[i]=n2[i+1];
            /*check which number has sign and calculation for big number for adding sign*/
            n2_sign=1;
            n1_sign=0;
            n2_big=num_strcmp(n2,n1);
        }
        sign_sub(n1,n2,n3);/*need to edit (omit this)*/
        /*sign add according to the big number and no need to sign check bottom of this function */
        sign_adding(n1_sign,n2_sign,n1_big,n2_big);
        return; /*no more subtraction process required*/
    }
    /*normal subtraction if in main function have no negative sign*/
    if (num_strcmp(n1,n2)==0){
        strcpy(n3,"0");
        return;
    }
    else if (num_strcmp(n1,n2)==-1) {
        strcpy(n3,n1);
        strcpy(n1,n2);
        strcpy(n2,n3);
    }
    if (strlen(n1)!=strlen(n2)) ar_eql(n1,n2);
    strcpy(n3,n1); /*need to equal n3 for adding null*/
    for (i=strlen(n1)-1,j=0;i>=0;i--,j++) {
        n1_int=(n1[i]-48);
        n2_int=n2[i]-48+carry;
        if (n2_int>n1_int) {
            n1_int=n1_int+10;
            result=n1_int-n2_int;
            n3[j]=result+48;
            carry=1;
        }
        else {
            result=n1_int-n2_int;
            n3[j]=result+48;
            carry=0;
        }
    }
    strrev(n3);
    /*omit zero form left*/
    zero_omit(n3);
    /*normal subtraction end*/

    /*point checking*/
    j=strlen(n3);
    if (point_location!=-1){
        for (i=j,count=1;count<=point_location;i--,count++){
            n3[i+1]=n3[i];
        }
        n3[i+1]='.';
    }
jump_a:
    /*sign checking*/
    if (sign_flag){
        for (i=strlen(n3);i>0;i--) n3[i]=n3[i-1];
        n3[i]='-';
    }
}

void zero_omit (char n3[])
{
    int i,j,len=strlen(n3),count=0;
    for (i=0,count=0;i<strlen(n3);i++){
        if (n3[i]=='0') count++;
        else break;
    }
    for (i=count,j=0;i<=len;i++,j++){
        n3[j]=n3[i];
    }
}

void Div(char n1[],char n2[],char n3[])
{
    char increment[]="1";
    strcpy(div_temp,increment);
    while (1){
        mul(n1,div_temp,n3);
        if (num_strcmp(n3,n2)==0){
            sub(n2,div_quo,div_re);
            strcpy(n3,div_temp);
            //strcat(n3,".00");
            return;
        }
        if (num_strcmp(n3,n2)==1){
            strcpy(increment,"1"); /*n2 (increment) will change for ar_eql function*/
            sub(div_temp,increment,n3);
            mul(n1,n3,div_quo);
            strcpy(div_temp,n3);
            sub(n2,div_quo,div_re);
            strcpy(n3,div_temp);
            break;
        }
        if (num_strcmp(n3,n2)==-1) {
            strcpy(increment,"1"); /*n2 (increment) will change for ar_eql function*/
            add(div_temp,increment,n3);
            strcpy(div_temp,n3);
        }
    }
    /*point calculation*/

    /*strcat(n3,".");
    int i=10,j;
    strcpy(increment,"1");
    strcpy(div_n2_temp,div_re);
    strcat(div_n2_temp,"0");
    strcpy(div_temp,increment);
    while (i--){
        strcpy(increment,"1");
        strcpy(div_temp,increment);
        while (1){
            mul(n1,div_temp,div_point);
            if (num_strcmp(div_point,div_n2_temp)==0){
                sub(div_n2_temp,div_quo,div_re);
                strcpy(div_point,div_temp);
                //strcpy(div_re,"00");
                //flag=1;
                break;
            }
            if (num_strcmp(div_point,div_n2_temp)==1){
                strcpy(increment,"1"); //n2 will change for ar_eql function
                sub(div_temp,increment,div_point);
                mul(n1,div_point,div_quo);
                strcpy(div_temp,div_point);
                sub(div_n2_temp,div_quo,div_re);
                strcpy(div_point,div_temp);
                break;
            }
            if (num_strcmp(div_point,div_n2_temp)==-1) {
                strcpy(increment,"1"); //n2 will change for ar_eql function
                add(div_temp,increment,div_point);
                strcpy(div_temp,div_point);
            }
        }
        //j=strlen(n3);
        strcat(n3,div_point);
        //n3[j]=div_point[strlen(div_point)-1]; n3[j+1]='\0';
        strcat(div_n2_temp,"0");
        //if (flag==1) break;
    }*/
    /*--*/
    /*int i;
    for (i=0;i<10;i++){
        while (1){
            mul(n1,div_temp,div_quo);
            if (num_strcmp(div_n2_temp,div_quo)==1){
                strcpy(increment,"1");
                add(div_temp,increment,div_re);
                strcpy(div_temp,div_re);
            }
            if (num_strcmp(div_n2_temp,div_quo)==-1) {
                strcpy(increment,"1");
                sub(div_temp,increment,div_re);
                strcpy(div_temp,div_re);
                mul(n1,div_temp,div_quo);
                //strcat(n3,div_temp);
                break;
            }
            if (num_strcmp(div_n2_temp,div_quo)==0) break;
        }
        strcat(n3,div_temp);
        sub(div_n2_temp,div_quo,div_re);
        strcpy(div_n2_temp,div_re);
        strcat(div_n2_temp,"0");
        strcpy(increment,"1");
        strcpy(div_temp,increment);
        printf("%s\n",n3);
    }*/

    /*int i=5,j;
    strcpy(div_n2_temp,div_re);
    strcat(div_n2_temp,"0");
    strcpy(increment,"1");
    strcpy(div_temp,increment);
    while (i--){
        while(1){
            mul(n1,div_temp,div_quo);
            if (num_strcmp(div_quo,div_n2_temp)==-1){
                add(div_temp,increment,div_re); //temp use div_re just for putting value
                strcpy(div_temp,div_re);
            }
            if (num_strcmp(div_quo,div_n2_temp)==1){
                strcpy(increment,"1");
                sub(div_temp,increment,div_re); //temp use div_re just for putting value
                strcpy(div_temp,div_re);
                mul(n1,div_temp,div_quo);
                break;
            }
        }
        strcat(n3,div_temp);
        sub(div_n2_temp,div_quo,div_re);
        strcpy(div_n2_temp,div_re);
        strcat(div_n2_temp,"0");
        strcpy(increment,"1");
        strcpy(div_temp,increment);
    }*/
}

void mod (char n1[],char n2[],char n3[])
{
    char increment[]="1";
    strcpy(div_temp,increment);
    while (1){
        mul(n1,div_temp,n3);
        if (num_strcmp(n3,n2)==0){
            strcpy(n3,"0");
            return;
        }
        if (num_strcmp(n3,n2)==1){
            strcpy(increment,"1"); /*n2 (increment) will change for ar_eql function*/
            sub(div_temp,increment,n3);
            mul(n1,n3,div_quo);
            strcpy(div_temp,n3);
            sub(n2,div_quo,div_re);
            strcpy(n3,div_temp);
            break;
        }
        if (num_strcmp(n3,n2)==-1) {
            strcpy(increment,"1"); /*n2 (increment) will change for ar_eql function*/
            add(div_temp,increment,n3);
            strcpy(div_temp,n3);
        }
    }
    strcpy(n3,div_re);
}

void div2(char n1[],char n2[],char n3[])
{
    int l=strlen(n2);
    int i=0;
    char increment[]="1";
    strcpy(div_n2_temp,"");
    strcat(div_n2_temp,n2[i]);
    strcpy(n3,"");
    while (i<l){
        if (num_strcmp(n1,div_n2_temp)==1){
            i++;
            strcat(div_n2_temp,n2[i]);
        }
        if (num_strcmp(n1,div_n2_temp)==-1){
            char increment[]="1";
            strcpy(div_temp,increment);
            while (1){
                mul(n1,div_temp,n3_temp);
                if (num_strcmp(n3_temp,div_n2_temp)==0){
                    sub(n2,div_quo,div_re);
                    strcpy(n3_temp,div_temp);
                    strcpy(div_n2_temp,"");
                    //strcat(n3,".00");
                    return;
                }
                if (num_strcmp(n3_temp,div_n2_temp)==1){
                    strcpy(increment,"1"); /*n2 (increment) will change for ar_eql function*/
                    sub(div_temp,increment,n3_temp);
                    mul(n1,n3_temp,div_quo);
                    strcpy(div_temp,n3_temp);
                    sub(n2,div_quo,div_re);
                    strcpy(n3_temp,div_temp);
                    strcpy(div_n2_temp,div_re);
                    break;
                }
                if (num_strcmp(n3_temp,div_n2_temp)==-1) {
                    strcpy(increment,"1"); /*n2 (increment) will change for ar_eql function*/
                    add(div_temp,increment,n3_temp);
                    strcpy(div_temp,n3_temp);
                }
            }
            strcat(n3,n3_temp);
        }
        if (num_strcmp(n1,div_n2_temp)==0){
            i++;
            strcat(div_n2_temp,n2[i]);
            strcat(n3,"0");
        }
    }
}

int main ()
{
    strcpy(n1,"11111111111111111111");
    strcpy(n2,"11111111111111111111");
    strcpy(n3,"1");
    strcpy(n4,"");
    strcpy(n5,"");
    /*while (1){
        gets(n1);
        gets(n2);
        add(n1,n2,n3);
        printf ("%s\n\n",n3);
    }*/

    //printf("%d\n",strcmp("2","10"));
    //add(n1,n2,n3);
    //sub(n1,n2,n3);
    //mul(n1,n2,n3);
    //Div(n1,n2,n3);
    //printf("\n%s\n\n",n3);
    //mod(n1,n2,n3);
    //printf("\n%s\n\n",n3);
    //printf ("\n%s.%s\n",n3,div_re);
    //printf("\n%s\n\n",n3);

    mod(n1,n2,n3);
    printf("\n%s\n\n",n3);




    /*-------------*/
}

void sign_add(char n1[],char n2[],char n3[]) /*this function is only for "sub" function*/
{
    zero_omit(n1);zero_omit(n2); /*omit zero if any zero found in left in the array */
    int i,j,carry=0,n1_int,n2_int,result,re,point_location=-1,count; /*return value will return 0 if point location found in 0 index in the array*/
    char  temp,temp2;
    int n1_sign,n2_sign,n1_big,n2_big,sign_flag=0;
    /*turn off this if there have no possibility having point in array*/
    if (check_point){
        for (i=0;i<strlen(n1);i++){
            if (n1[i]=='.'){
                point_location=add_point(n1,n2);
                break;
            }
        }
        for (i=0;i<strlen(n2) && point_location==-1;i++){
            if (n2[i]=='.'){
                point_location=add_point(n1,n2);
                break;
            }
        }
    }
    if (strlen(n1)!=strlen(n2)) ar_eql(n1,n2);
    for (i=strlen(n1)-1,j=0;i>=0;i--,j++){
        n1_int=(n1[i]-48)+carry;
        n2_int=n2[i]-48;
        result=n1_int+n2_int;
        if (result>=10){
            n3[j]=(result%10)+48;
            carry=1;
        }
        else {
            n3[j]=result+48;
            carry=0;
        }
    }
    if (carry==1) {
        n3[j]=carry+48;j++;
        n3[j]='\0';
    }
    else n3[j]='\0';
    strrev(n3);
    /*point checking*/
    j=strlen(n3);
    if (point_location!=-1){
        for (i=j,count=1;count<=point_location;i--,count++){
            n3[i+1]=n3[i];
        }
        n3[i+1]='.';
    }
}

void sign_sub(char n1[],char n2[],char n3[]) /*this function is only for "add" function*/
{
    int i,j,carry=0,n1_int,n2_int,result,re,point_location=-1,count; /*return value will return 0 if point location found in 0 index in the array*/
    /*turn off this if there have no possibility having point in array*/
    if (!check_point){ /*does not work*/
        for (i=0;i<strlen(n1);i++){
            if (n1[i]=='.'){
                point_location=add_point(n1,n2);
                break;
            }
        }
        for (i=0;i<strlen(n2) && point_location==-1;i++){
            if (n2[i]=='.'){
                point_location=add_point(n1,n2);
                break;
            }
        }
    }
    if (num_strcmp(n1,n2)==0) {
        strcpy(n3,"0");
        return;
    }
    else if (num_strcmp(n1,n2)==-1) {
        strcpy(n3,n1);
        strcpy(n1,n2);
        strcpy(n2,n3);
    }
    if (strlen(n1)!=strlen(n2)) ar_eql(n1,n2);
    strcpy(n3,n1); /*need to equal n3 for adding null*/
    for (i=strlen(n1)-1,j=0;i>=0;i--,j++) {
        n1_int=(n1[i]-48);
        n2_int=(n2[i]-48)+carry;
        if (n2_int>n1_int) {
            n1_int=n1_int+10;
            result=n1_int-n2_int;
            n3[j]=result+48;
            carry=1;
        }
        else {
            result=n1_int-n2_int;
            n3[j]=result+48;
            carry=0;
        }
    }
    strrev(n3);
    /*omit zero form left*/
    zero_omit(n3);
    /*point checking*/
    j=strlen(n3);
    if (point_location!=-1){
        for (i=j,count=1;count<=point_location;i--,count++){
            n3[i+1]=n3[i];
        }
        n3[i+1]='.';
    }
}

int num_strcmp(char n1[],char n2[]) /*number string comparing, works only for positive pointless number*/
{
    strcpy(num_strcmp_n1,n1);strcpy(num_strcmp_n2,n2); /*copy arrays for omitting zeros form left*/
    zero_omit(num_strcmp_n1);zero_omit(num_strcmp_n2); /*omit zero form left*/
    int i,len=strlen(num_strcmp_n1);
    if (strlen(num_strcmp_n1)>strlen(num_strcmp_n2)) return 1;
    if (strlen(num_strcmp_n1)<strlen(num_strcmp_n2)) return -1;
    for (i=0;i<len;i++){
        if (num_strcmp_n1[i]>num_strcmp_n2[i]) return 1;
        if (num_strcmp_n1[i]<num_strcmp_n2[i]) return -1;
    }
    return 0;
}
