#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();
struct ListNode *deletem( struct ListNode *L, int m );
void printlist( struct ListNode *L )
{
     struct ListNode *p = L;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    int m;
    struct ListNode *L = readlist();
    scanf("%d", &m);
    L = deletem(L, m);
    printlist(L);

    return 0;
}

struct ListNode *readlist()
{
    struct ListNode *p,*head,*tail;
    head=(struct ListNode*)malloc(sizeof(struct ListNode));
    head->next=NULL;
    tail=head;

    int data;
    scanf("%d",&data);
    while(data!=-1)
    {
        p=(struct ListNode*)malloc(sizeof(struct ListNode));
        p->data=data;
        tail->next=p;
        p->next=NULL;
        tail=p;
        scanf("%d",&data);
    }
    return head->next;

}
struct ListNode *deletem( struct ListNode *L, int m )
{
    struct ListNode *h1,*p1,*h2,*p2,*t1,*t2,*q=L;
    h1=(struct ListNode*)malloc(sizeof(struct ListNode));
    h2=(struct ListNode*)malloc(sizeof(struct ListNode));
    h1->next=NULL;
    h2->next=NULL;
    t1=h1;t2=h2;
    while(q)
    {
        if(q->data==m)
        {
            p1=(struct ListNode*)malloc(sizeof(struct ListNode));
            p1->data=(q)->data;
            t1->next=p1;
            p1->next=NULL;
            t1=p1;
            q=q->next;
        }
        else
        {
            p2=(struct ListNode*)malloc(sizeof(struct ListNode));
            p2->data=(q)->data;
            t2->next=p2;
            p2->next=NULL;
            t2=p2;
            q=q->next;
        }
    }
    return h2->next;
}