#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表 */

List Insert( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    L = Read();
    scanf("%d", &X);
    L = Insert(L, X);
    Print(L);
    return 0;
}

/* 你的代码将被嵌在这里 */
List Insert( List L, ElementType X )
{
    struct Node *p,*h=L;
    p=(struct Node*)malloc(sizeof(struct Node));
    p->Data=X;
    p->Next=NULL;
    while(h->Next&&h->Next->Data<=X)
    {
        h=h->Next;
    }
    p->Next=h->Next;
    h->Next=p;
    return L;
}