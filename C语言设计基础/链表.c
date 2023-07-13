#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int value;
	struct node *next;
}Node;

typedef struct
{
	Node *head,*tail;
}List;

void prt(List *list)
{
	for(Node *p=list->head;p;p=p->next)
	{
		printf("%d ",p->value);
	}
}
void insert(List *list,int x)
{
	Node *p=(Node *)malloc(sizeof(Node));
	p->value=x;
	p->next=NULL;
	if(list->head==NULL)
	{
		list->head=p;
		list->tail=p;
	}
	else
	{
		p->next=list->head;
		list->head=p;
	}
}
void append(List *list,int x)
{
	Node *p=(Node*)malloc(sizeof(Node));
	p->value =x;
	p->next =NULL;
	if(list->head==NULL){
		list->head=p;
		list->tail=p;
		
	}
	else
	{
		Node *q=(Node*)malloc(sizeof(Node));
		q=list->head ;
		for(;q->next;)
		{
			q=q->next;
		}
		q->next =p;
		list->tail =p;
	}
	
}
int search(List *list,int x)
{
	int ret=0;
	Node *p=list->head;
	for(;p;p=p->next)
	{
		if(p->value==x){
		ret=1;
		break;}
	}
	return ret;
}
void remove(List *list,int x)
{
	Node *p=list->head;
	Node *q=NULL;
	for(;p;)
	{
		if(p->value==x&&!q)
		{
			if(p->next)
			{
				p=p->next;
				free(list->head);
				
				list->head=p;
			}
			else
			{
				list->head =NULL;
				list->tail =NULL;
				p=NULL;
				free(p);
			}
		}
		else if(p->value==x&&q)
		{
			if(p->next)
			{
				q->next=p->next ;
				free(p);
				p=q->next ;
			}
			else
			{
				q->next =NULL;
				list->tail =q;
				p=NULL;
				free(p);
			}
		}
		else 
		{
			q=p;
			p=p->next ;
		}
	}
}
int main()
{
	List list={NULL};
	

	
	for(;1;)
	{
		int x;
		scanf("%d",&x);
		if(x<0){
		break;}
		//insert(&list,x);
		append(&list,x);
	}
	int x;
	scanf("%d",&x);
	remove(&list,x);
	//printf("%d",search(&list,x));
	prt(&list);
	
}
