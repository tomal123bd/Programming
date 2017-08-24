#include <stdio.h>//aibohphobia
#include <string.h>
int main()
{
    printf ("Input word : ");
    char word[1000];
    gets(word);
    int a=strlen(word)-1; int b=0;
    int c=a;
    char palindrome[1000];
    int i,j;
    for (i=0;word[i]!='\0';i++,c--)
    {
        palindrome[i]=word[c];
        //printf("%c,%c,%d,%d\n",palindrome[c],word[i],i,c);
        /*if (palindrome[a]==word[i])
        {
            printf("ok\n");
        }*/
    }
    palindrome[i]='\0';
    printf ("\n%s\n\n",palindrome);
    for (i=0;i<=a;i++)
    {
        if (palindrome[i]!=word[i])
        {
            b++;
        }
    }
    if (b!=0)
    {
        printf("not palindrome ");
    }
    else
    {
        printf("palindrome");
    }
}
