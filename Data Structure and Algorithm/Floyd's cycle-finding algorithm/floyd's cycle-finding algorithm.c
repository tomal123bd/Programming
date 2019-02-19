struct linked_list {
    int value;
    linked_list *next;
}
linked_list cycle_find(linked_list* list)
{
    if (!list->next) return NULL;
    linked_list *h=list;
    linked_list *t=list;
    while(h){
        if (h->next && h->next->next) h=h->next->next;
        else return NULL;
        t=t->next;
        if (h==t) break;
    }
    linked_list *t2=list;
    while(t2!=t){
        t2=t2->next;
        t=t->next;
    }
    return t;
}
