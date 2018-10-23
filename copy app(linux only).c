/* this app does not work if there have other file with same name , this problem will be fixed soon */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <dirent.h>
#include <string.h>

void extract_file_name(char input_file[],char file_name[])
{
    int i,j,len=strlen(input_file),count;
    for (i=len-1,count=0;input_file[i]!='/';i--){
        count++;
    }
    for (i=0,j=len-count-1;i<=count;i++,j++){
        file_name[i]=input_file[j];
        //printf("%c",file_name[i]);
    }
    file_name[i]='\0';
}

void default_name_change(char file_name[],char input_name[])
{
    /* need to be finished */
}

int main ()
{
    FILE *file_in,*file_out;
    char input_file[1000];
    char output_file[1000];
    printf ("File name with full file path: ");
    gets(input_file);
    printf ("File destination path: ");
    gets(output_file);
    printf("%s \n %s \n",input_file,output_file);
    char file_name[1000],temp_output_file[1000];
    strcpy(temp_output_file,output_file);
    int x,flag=1;
    clock_t start_time,end_time;
    double time_elapsed,total_time=0;
    file_in=fopen(input_file,"rb");
    if (file_in==NULL){
        printf("Error opening file\n");
        return 0;
    }
    DIR *d=opendir(output_file);
    if(!d){
        printf("Invalid targeted directory\n");
        return 0;
    }
    extract_file_name(input_file,file_name);
    strcat(output_file,file_name);
    file_out=fopen(output_file,"rb");
    if (file_out!=NULL){
        printf("File already exists with this name. Do you still want to copy?\nc (copy)\nr (rename and copy)\nd (default name with a number)\nn (no)\n");
        char choice,input_name[1000];
        scanf ("%c",&choice);
        if (choice=='n'){
            return 0;
        }
        else if(choice=='r'){
            printf("Please input a different name with extension: ");
            scanf ("%s",input_name);
            //gets(input_name);
            int len=strlen(temp_output_file);
            temp_output_file[len]='/';
            temp_output_file[len+1]='\0';
            strcat(temp_output_file,input_name);
            strcpy(output_file,temp_output_file);
        }
        else if (choice=='d'){
            default_name_change(file_name,input_name);
        }
        else {
            printf("Wrong input\n");
            return 0;
        }
    }
    /*fclose(file_out);*/ /* creates segmentation fault*/
    file_out=fopen(output_file,"wb");
    fseek(file_in,0,SEEK_END);
    long int input_file_size=ftell(file_in),percent_size=input_file_size/100,percent=percent_size,count=0;
    fseek(file_in,0,SEEK_SET);
    while (1){
        if (flag==1){
            start_time=clock();
            flag=0;
        }
        x=fgetc(file_in);
        if (x==EOF){
            printf("Finished\n Size: %ld kB Time: %.0lfm",ftell(file_in)/1024,1+total_time);
            break;
        }
        fputc(x,file_out);
        if (ftell(file_out)==percent){
            count++;
            percent=percent+percent_size;
            end_time=clock();
            flag=1;
            time_elapsed=(double)((end_time-start_time)/CLOCKS_PER_SEC)/60;
            total_time=total_time+time_elapsed;
            printf ("coping... %ld%%     remaining time: %.0lf m\n",count,1+time_elapsed*((double)100-(double)count));
        }
    }
    /*duplicate checking*/
    fclose(file_in);
    fclose(file_out);
}
