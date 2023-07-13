struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode *h,*t,*p=list1,*q=list2;
    h=malloc(sizeof(struct ListNode));
    t=h;
    while(p&&q)
    {
        if(p->data<q->data)
        {
            t->next=p;
            p=p->next;
            t=t->next;
        }
        else 
        {
            t->next=q;
            q=q->next;
            t=t->next;
        }
    }
    if(p)t->next=p;
    else t->next=q;

    return h->next;
}