#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} Node;
Node *first = NULL;

void create(int A[], int n)
{
    Node *p, *last;
    int i;
    first = (Node *)malloc(sizeof(Node));
    first->next = first->prev = NULL;
    first->data = A[0];
    last = first;

    for (i = 1; i < n; i++)
    {
        p = (Node *)malloc(sizeof(Node));
        p->next = NULL;
        last->next = p;
        p->prev = last;
        p->data = A[i];
        last = p;
    }
}

void display(Node *p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int count(Node *p)
{
    int i = 0;
    while (p)
    {
        p = p->next;
        i++;
    }
    return i;
}

void insert(Node *p, int index, int data)
{
    Node *t, *q;
    int i;
    if (index < 0 || index > count(p))
        return;
    t = (Node *)malloc(sizeof(Node));
    t->data = data;
    if (index == 0)
    {
        t->prev = NULL;
        if (!first)
        {
            t->next = NULL;
            first = t;
        }
        else
        {
            t->next = first;
            first->prev = t;
            first = t;
        }
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        if (p->next)
            p->next->prev = t;
        p->next = t;
        t->prev = p;
    }
}

void delete (Node *p, int index)
{
    int i;
    Node *q;
    if (index < 0 || index > count(p) - 1)
        return;
    if (index == 0)
    {
        p->next->prev = NULL;
        first = p->next;
        free(p);
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        q = p->next;
        if (q->next)
            q->next->prev = p;
        p->next = q->next;
        free(q);
    }
}

void reverse(Node *p)
{
    Node *t;
    while (p)
    {
        t = p->next;
        p->next = p->prev;
        p->prev = t;
        p = p->prev;
        if (p && !p->next)
            first = p;
    }
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    create(A, 5);
    reverse(first);
    // delete (first, 5);
    // insert(first, 5, 21);
    display(first);
}