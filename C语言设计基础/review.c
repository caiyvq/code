#include<stdio.h>
#include<stdlib.h>
#include "review.h"

void ptr(node h)
{
	node p=h;
	for(;p;p=p->next)
	{
		printf("%d ",p->data);
	}
	printf("\n");
}

node cre_nega()
{
	node head;
	head=(node)malloc(sizeof(node));
	head->next=NULL;
	scanf("%d",&head->data);
	
	int n;
	scanf("%d",&n);
	while(n!=-1)
	{
		node p;
		p=(node)malloc(sizeof(node));
		p->next=head;
		p->data=n;
		head=p;
		scanf("%d",&n);
	}
	
	return head;
}

node cre_posi()
{
	node head,tail;
	head=(node)malloc(sizeof(node));
	head->next=NULL;
	scanf("%d",&head->data);
	tail=head;
	
	int n;
	scanf("%d",&n);
	while(n!=-1)
	{
		node p;
		p=(node)malloc(sizeof(node));
		p->data=n;
		p->next=NULL;
		tail->next=p;
		tail=p;
		scanf("%d",&n);
	}
	
	return head;
}

void appand(node h,int n)
{
	node p,q=h;
	p=(node)malloc(sizeof(node));
	p->data=n;
	p->next=NULL;
	if(!q)
	{
		h->data=n;
	}
	while(q->next)
	{
		q=q->next;
	}
	q->next=p;
}

void insert(node *h,int n)
{
	node *p;
	p=(node*)malloc(sizeof(node));
	(*p)->data=n; 
	(*p)->next=(*p);
	(*h)=(*p);
}

node reverse(node h)
{
	node h1,p,q;
	h1=(node)malloc(sizeof(node));
	(h1)->data=(h)->data;
	(h1)->next=NULL;
	
	(q)=(h)->next;
	while(q)
	{
		p=(node)malloc(sizeof(node));
		(p)->data=(q)->data;
		(p)->next=(h1);
		(h1)=(p);
		(q)=(q)->next;
	}
	
	free(h);
	return h1;
}