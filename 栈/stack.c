#include <stdio.h>
#include <stdlib.h>

#ifndef _Stack_h

struct StackRecord;
typedef struct StackRecord *Stack;

int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(int X, Stack S);
int Top(Stack S);
void Pop(Stack S);
int TopAndPop(Stack S);

#endif

#define EmptyTOS -1
#define MinStackSize 2

struct StackRecord
{
    int Capacity;
    int TopOfStack;
    int *Array;
};

int main()
{
    return 0;
}

int IsEmpty(Stack S) //判断栈是否为空
{
    return S->TopOfStack == EmptyTOS;
}

int IsFull(Stack S) //判断栈是否为满
{
    return S->TopOfStack == S->Capacity - 1;
}

Stack CreateStack(int MaxElements) //创建栈
{
    Stack S;

    if (MaxElements < MinStackSize)
        Error("Stack size is too small!");

    S = malloc(sizeof(struct StackRecord));
    if (S == NULL)
        FatalError("Out of space!!!");

    S->Array = malloc(sizeof(int) * MaxElements);
    if (S->Array == NULL)
        FatalError("Out of space!!!");
    S->Capacity = MaxElements;
    MakeEmpty(S);

    return S;
}

void DisposeStack(Stack S) //释放栈
{
    if (S)
    {
        free(S->Array);
        free(S);
    }
}

void MakeEmpty(Stack S) //置空栈
{
    S->TopOfStack = EmptyTOS;
}

void Push(int X, Stack S) //入栈
{
    if (IsFull(S))
        Error("Stack is full!");
    else
    {
        S->Array[++S->TopOfStack] = X;
    }
}

int Top(Stack S) //返回栈顶元素
{
    if (!IsEmpty(S))
        return S->Array[S->TopOfStack];
    Error("Stack is empty!");

    return 0;
}

void Pop(Stack S) //出栈
{
    if (IsEmpty(S))
        Error("Stack is empty!");
    else
    {
        S->TopOfStack--;
    }
}

int TopAndPop(Stack S) //弹出并返回栈顶元素
{
    if (!IsEmpty(S))
        return S->Array[S->TopOfStack--];
    Error("Stack is empty!");

    return 0;
}