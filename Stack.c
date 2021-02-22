#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int size;
    int Top;
    int *S;
} stack;

void create(stack *st)
{
    printf("Enter size :");
    scanf("%d", &st->size);
    st->S = (int *)malloc(sizeof(int) * st->size);
    st->Top = -1;
}

void push(stack *st, int val)
{
    if (st->size - 1 == st->Top)
        printf("Stack is full");
    else
    {
        st->Top++;
        st->S[st->Top] = val;
    }
}

int pop(stack *st)
{
    int x = -1;
    if (st->Top == -1)
        printf("Stack is empty");
    else
        x = st->S[st->Top--];
    return x;
}

void display(stack st)
{
    int i;
    for (i = st.Top; i >= 0; i--)
        printf("%d ", st.S[i]);
    printf("\n");
}

int peek(stack st, int pos)
{
    int x = -1;
    int i;
    i = st.Top - pos + 1;
    if (pos <= 0 || pos > st.size - st.Top + 1)
        printf("Invalid index\n");
    else
        x = st.S[i];
    return x;
}

int isEmpty(stack st)
{
    return st.Top == -1;
}

int isFull(stack st)
{
    return st.Top == st.size - 1;
}

int stackTop(stack st)
{
    if (!isEmpty(st))
        return st.S[st.Top];
    return -1;
}

int main()
{
    stack st;
    create(&st);
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    // push(&st, 40);
    // push(&st, 50);
    printf("peek %d\n", peek(st, 4));
    display(st);
}