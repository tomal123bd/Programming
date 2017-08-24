#include <stdio.h>
#include <string.h>

float point_calc (char grade[])
{
    if (strcmp(grade,"A+")==0 || strcmp(grade,"a+")==0){
        return 4;
    }
    if (strcmp(grade,"A")==0 || strcmp(grade,"a")==0){
        return 3.75;
    }
    if (strcmp(grade,"A-")==0 || strcmp(grade,"a-")==0){
        return 3.50;
    }
    if (strcmp(grade,"B+")==0 || strcmp(grade,"b+")==0){
        return 3.25;
    }
    if (strcmp(grade,"B")==0 || strcmp(grade,"b")==0){
        return 3;
    }
    if (strcmp(grade,"B-")==0 || strcmp(grade,"b-")==0){
        return 2.75;
    }
    if (strcmp(grade,"C+")==0 || strcmp(grade,"c+")==0){
        return 2.50;
    }
    if (strcmp(grade,"C")==0 || strcmp(grade,"c")==0){
        return 2.25;
    }
    if (strcmp(grade,"D")==0 || strcmp(grade,"d")==0){
        return 2;
    }
    if (strcmp(grade,"F")==0 || strcmp(grade,"f")==0){
        return 0;
    }
    printf ("Invalid Input.\nPlease restart the programme...\n");
}

int main ()
{
    int total_num_of_sub;
    printf ("Application Developed by- Ashikur Rahman Tomal...\nEmail: tomal123bd@gmail.com\n\n");
    while (1){
    printf ("(Input 0 for exit) Input Total Number of Subjects: ");
    scanf("%d",&total_num_of_sub);
    if (total_num_of_sub==0){
        printf ("\nThanks for using.\n");
        return 0;
    }
    int i;
    float num=0,result;
    char grade[3],c;
    scanf ("%c",&c);
    for (i=1;i<=total_num_of_sub;i++){
        printf ("%d. Grade: ",i);
        scanf ("%s",&grade);
        num=point_calc(grade) + num;
    }
    result = num/(float)total_num_of_sub;
    printf ("Point: %f\n",result);
    }
}
