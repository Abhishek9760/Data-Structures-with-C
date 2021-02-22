#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;
Node *Head;

void create(int A[], int n)
{
    Node *t, *last;
    int i;
    Head = (Node *)malloc(sizeof(Node *));
    Head->next = Head;
    Head->data = A[0];
    last = Head;

    for (i = 1; i < n; i++)
    {
        t = (Node *)malloc(sizeof(Node *));
        t->next = last->next;
        t->data = A[i];
        last->next = t;
        last = t;
    }
}

void display(Node *p)
{
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != Head);
}

void Rdisplay(Node *h)
{
    static int flag = 0;
    if (h != Head || flag == 0)
    {
        flag = 1;
        printf("%d ", h->data);
        Rdisplay(h->next);
    }
    flag = 0;
}

int length(Node *p)
{
    int i = 0;
    do
    {
        i++;
        p = p->next;
    } while (p != Head);
    return i;
}

void insert(Node *p, int data, int index)
{
    Node *t;
    int i;
    if (index < 0 || index > length(p) - 1)
        return;
    if (index == 0)
    {
        t = (Node *)malloc(sizeof(Node *));
        t->data = data;
        if (!Head)
        {
            Head = t;
            Head->next = Head;
        }
        else
        {
            while (p->next != Head)
                p = p->next;
            t->next = Head;
            Head = t;
        }
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t = (Node *)malloc(sizeof(Node *));
        t->data = data;
        t->next = p->next;
        p->next = t;
    }
}

int delete (Node *p, int index)
{
    int i, x = -1;
    Node *t;
    if (index < 0 || index > length(p) - 1)
        return x;
    if (index == 0)
    {
        do
        {
            p = p->next;
        } while (p->next != Head);
        p->next = Head->next;
        x = Head->data;
        free(Head);
        Head = p->next;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t = p->next;
        p->next = t->next;
        x = t->data;
        free(t);
    }
    return x;
}

int main()
{
    int A[] = {1, 24, 4, 54, 6};
    create(A, 5);
    printf("deleted %d\n", delete (Head, 5));
    // printf("%d", length(Head));
    // insert(Head, 32, -1);
    Rdisplay(Head);
}