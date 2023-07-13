#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist(); /*裁判实现，细节不表*/
struct ListNode *reverse( struct ListNode *head );
void printlist( struct ListNode *head )
{
     struct ListNode *p = head;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    struct ListNode  *head;

    head = createlist();
    head = reverse(head);
    printlist(head);
    
    return 0;
}

/* 你的代码将被嵌在这里 */
struct ListNode *reverse( struct ListNode *head )
{
    struct ListNode *h,*p,*q=head;
    h=(struct ListNode*)malloc(sizeof(struct ListNode));
    h=NULL;

    while(q)
    {
        p=(struct ListNode*)malloc(sizeof(struct ListNode));
        p->data=q->data;
        p->next=h;
        h=p;
        q=q->next;
    }
    free(head);
    return h;
}