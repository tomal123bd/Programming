#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
int random_num(char condition)
{
    int r;
    if (condition=='l'){
        while (1){
            r=rand()%123;
            if (r>=97 && r<=122) return r;
        }
    }else if (condition=='u'){
        while (1){
            r=rand()%91;
            if (r>=65 && r<=90) return r;
        }
    }else if (condition=='m') {
        while (1){
            r=rand()%123;
            if (r>=65 && r<=90 || r>=97 && r<=122) return r;
        }
    }
}

void letters_generator(char letter[],int num,char condition)
{
    int i;
    for (i=0;i<num;i++) {
        letter[i]=random_num(condition);
    }
    letter[i]='\0';
}

int check_input(char input[])
{
    int i;
    for (i=0;i<strlen(input);i++){
        if (input[i]>=48 && input[i]<=57) continue;
        else return 0;
    }
    return 1;
}

int main ()
{
    printf("\nContact: tomal123bd@gmail.com facebook.com/tomal123\n");
    printf("Developed by Ashikur Rahman Tomal\n\n");
    srand(time(0));
    char letter[100],input[100],num_input[100],condition_input[100],condition,c,t_input[100];
    int i,t,time_elapsed,r,num;
    int right,wrong,point,count;float accuracy;
    b:{
    right=0,wrong=0,point=0,count=0,accuracy=0;
    while (1){
    printf ("How many letters? : ");
    gets(num_input);
    if (check_input(num_input) && num_input[0]!=NULL){
        num=atoi(num_input);
        if (num<=99 && num>0)break;
        printf("\nError !\nLetters must be less then 99 and more then 0. Try again...\n");
    }else printf("\nInvalid Input\n");
    }
    while (1){
    printf("Input l for lowercase,u for uppercase,m for mixed: ");
    gets (condition_input);
    if (strcmp(condition_input,"l")==0 || strcmp(condition_input,"u")==0 || strcmp(condition_input,"m")==0){
         condition=condition_input[0];
         break;
    }
    printf("\nError input !\nTry again...\n");
    }
    while(1){
        printf("(enter 0 to skip) Timer sec : ");
        gets(t_input);
        if (check_input(t_input) && t_input[0]!=NULL){
            t=atoi(t_input);break;
        }
        printf("\nInvalid input\n");
    }
    system("cls");
    while (1){
        letters_generator(letter,num,condition);
        a:{
        printf(">>> %s (0 to exit)\n",letter);
            clock_t start_time , end_time;
            start_time = clock();
            gets(input);
            end_time = clock();
            time_elapsed = (double) (end_time-start_time)/CLOCKS_PER_SEC;
            count++;system("cls");
            if (strcmp(input,"0")==0) break;
            if (strcmp(input,letter)!=0 || (time_elapsed>t && t!=0)){
                wrong++;
                point=count-wrong;
                accuracy=100*((float)right/count);
                printf ("\nPoint = %d Accuracy = %.2f%% Total Try = %d Correct = %d Incorrect = %d\n",point,accuracy,count,right,wrong);
                if (time_elapsed>t && t!=0) printf("\nTime Over\n");
                else printf("\nWrong\n");
                goto a;
            }
            else {
                right++;
                point=count-wrong;
                accuracy=100*((float)right/count);
                printf ("\nPoint = %d Accuracy = %.2f%% Total Try = %d Correct = %d Incorrect = %d\n",point,accuracy,count,right,wrong);
                printf("\nRight\n");

            }
        }
    }
    }
    c:{
        count--;
        point=count-wrong;
        if (count!=0){
            accuracy=100*((float)right/count);
        }
        printf ("\nPoint = %d Accuracy = %.2f%% Total Try = %d Correct = %d Incorrect = %d\n",point,accuracy,count,right,wrong);
    }
    printf("\nPractice again? y/n : ");
    char y_n;
    scanf ("%c",&y_n);
    if (y_n=='y'){
        scanf("%c",&c); goto b;
    }
    else {
        printf("\n\nThanks For Using.........\n");
        getch();
        return 0;
    }
}
