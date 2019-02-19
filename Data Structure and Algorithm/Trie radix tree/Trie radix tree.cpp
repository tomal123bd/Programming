#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct node{
    bool e;
    node* n[26+1];
    node()
    {
        e=false;
        for(int i=0;i<26;i++) n[i]=NULL;
    }

    /*bool endmark;
    node* next[26+1];
    node()
    {
        endmark=false;
        for (int i=0;i<26;i++)
            next[i]=NULL;
    }*/
} *root;

void insert(char* str,int len)
{
    node* t=root;
    for (int i=0;i<len;i++){
        int j=str[i]-'a';
        if (t->n[j]==NULL) t->n[j]=new node();
        t=t->n[j];
    }
    t->e=true;
    /*node* curr=root;
    for (int i=0;i<len;i++){
        int id=str[i]-'a';
        if (curr->next[id]==NULL)
            curr->next[id]=new node();
        curr=curr->next[id];
    }
    curr->endmark=1;*/
}


bool search(char* str,int len)
{
    node* curr=root;
    for (int i=0;i<len;i++){
        int id=str[i]-'a';
        if (curr->n[id]==NULL)
            return false;
        curr=curr->n[id];
    }
    return curr->e;
}

int main ()
{
    puts("ENTER NUMBER OF WORDS");
    root=new node();
    int num_word;
    cin>>num_word;
    for (int i=1;i<=num_word;i++){
        char str[50];
        scanf ("%s",str);
        insert(str,strlen(str));
    }
    puts("ENTER NUMBER OF QUERY");
    int query;
    cin>>query;
    for (int i=1;i<=query;i++){
        char str[50];
        scanf ("%s",str);
        if (search(str,strlen(str)))
            puts("FOUND");
        else
            puts("NOT FOUND");
    }
}
