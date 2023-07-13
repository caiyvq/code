#include<stdio.h>
#include<stdlib.h>
typedef struct stack *stackint;
struct stack
{
	int data;
	int base;
	int top;
	stackint next;
};

void push(stackint s,int n)
{
	if(s->base==s->top)
	{
		s->data=n;
		s->top++;
	}
	else
	{
		stackint p=s;
		for(;p->next;p=p->next)
		{
		}
		stackint q;
		q=(stackint)malloc(sizeof(stackint));
		p->next=q;
		q->data=n;
		q->next=NULL;
		s->top++;
	}
	
	
}

void pop(stackint s)
{
	if(s->top>s->base)
	{
		stackint p=s;
	    for(;p->next;p=p->next)
		{
			
		}
		p=NULL;
		s->top--;
	}
	
}
int main()
{
	stackint s1,top,base;
	s1=(stackint)malloc(sizeof(stackint));
	s1->next=NULL;
	s1->base=0;
	s1->top=0;
	push(s1,1);
	push(s1,2);
	push(s1,2);
	pop(s1);
	pop(s1);
	pop(s1);
	printf("%d",s1->top);
}