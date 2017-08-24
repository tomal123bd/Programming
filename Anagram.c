#include <stdio.h>
#include <string.h>
void letters(char word[],int alp_count[])
{
    int i,j,count=0;
    char alp[26];
    for (i=0;i<26;i++){
        alp_count[i]=0;alp[i]=97+i;
    }
    for (i=0;i<strlen(word);i++){
        for (j=0;j<26;j++){
            if (word[i]==alp[j]){
                alp_count[j]++;
            }
        }
    }
}

int array_check(int word1[],int word2[])
{
    int i;
    for (i=0;i<26;i++){
        if (word1[i]!=word2[i]){
            return 0;
        }
    }
    return 1;
}

int main ()
{
    char word1[]="cinema",word2[]="iceman";
    int i,j,alp_count1[26],alp_count2[26];
    if (strlen(word1)!=strlen(word2)){
        printf("Not anagram\n");
        return 0;
    }else {
        letters(word1,alp_count1);
        letters(word2,alp_count2);
        if (array_check(alp_count1,alp_count2)==1){
            printf ("Anagram\n");
        }else {
            printf("Not anagram\n");
        }
    }
    return 0;
}
