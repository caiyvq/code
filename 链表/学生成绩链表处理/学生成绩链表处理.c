#include <stdio.h>
#include <stdlib.h>

struct stud_node {
     int    num;
     char   name[20];
     int    score;
     struct stud_node *next;
};

struct stud_node *createlist();
struct stud_node *deletelist( struct stud_node *head, int min_score );

int main()
{
    int min_score;
    struct stud_node *p, *head = NULL;

    head = createlist();
    scanf("%d", &min_score);
    head = deletelist(head, min_score);
    for ( p = head; p != NULL; p = p->next )
        printf("%d %s %d\n", p->num, p->name, p->score);

    return 0;
}

#include<string.h>
struct stud_node *createlist()
{
    struct stud_node *h,*p,*t;
    h=NULL;
    t=h;
    int num;
    scanf("%d",&num);
    while(num)
    {
        p=(struct stud_node*)malloc(sizeof(struct stud_node));
        p->num=num;
        scanf("%s %d\n",p->name,&p->score);
        if(h==NULL)h=p;
        else t->next=p;
        t=p;
        scanf("%d",&num);
    }
    return h;
}
struct stud_node *deletelist( struct stud_node *head, int min_score )
{
    struct stud_node *h,*p,*t,*q=head;
    h=NULL;
    t=h;
    while(q)
    {
        if(q->score>=min_score)
        {
            p=(struct stud_node*)malloc(sizeof(struct stud_node));
            strcpy(p->name,q->name);
            p->num=q->num;
            p->score=q->score;
            p->next=NULL;
            if(h==NULL)h=p;
            else t->next=p;
            t=p;
            q=q->next;
        }
        else q=q->next;
    }
    free(head);
    return h;
}