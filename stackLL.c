#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;
Node *top = NULL;

void push(int x)
{
    Node *t;
    t = (Node *)malloc(sizeof(Node));
    t->data = x;
    t->next = top;
    top = t;
}

int isEmpty()
{
    return top == NULL;
}

int pop()
{
    int x = -1;
    Node *t;
    if (isEmpty())
        printf("Stack is full");
    else
    {
        t = top->next;
        x = top->data;
        free(top);
        top = t;
    }
    return x;
}

void display()
{
    Node *p = top;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    push(32);
    push(12);
    push(42);
    push(34);
    push(1);
    pop();
    display();
}