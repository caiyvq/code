#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main()
{
    Stack s1 = CreateStack(10);
    int x;
    scanf("%d", &x);
    while (x != -1 && !IsFull(s1))
    {
        Push(x, s1);
        scanf("%d", &x);
    }

    while (!IsEmpty(s1))
    {
        printf("%d ",TopAndPop(s1));
    }
    printf("\n");
    system("pause");
    return 0;
}