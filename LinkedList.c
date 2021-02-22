#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;
Node *first;
Node *second;
Node *third;

void insert(Node *p, int n)
{
    Node *t;
    if (!p)
    {
        t = (Node *)malloc(sizeof(Node));
        t->data = n;
        t->next = NULL;
        first = t;
    }
    else
    {
        t = (Node *)malloc(sizeof(Node));
        t->data = n;
        while (p->next)
            p = p->next;
        p->next = t;
        t->next = NULL;
    }
}

void create1(int A[], int n)
{
    int i;
    Node *t, *last;
    t = (Node *)malloc(sizeof(Node));
    t->data = A[0];
    t->next = NULL;
    first = t;
    last = t;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create2(int A[], int n)
{
    int i;
    Node *t, *last;
    t = (Node *)malloc(sizeof(Node));
    t->data = A[0];
    t->next = NULL;
    second = t;
    last = t;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
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

int sum(Node *p)
{
    int s = 0;
    while (p)
    {
        s += p->data;
        p = p->next;
    }
    return s;
}

int count(Node *p)
{
    int s = 0;
    while (p)
    {
        s += 1;
        p = p->next;
    }
    return s;
}

int max(Node *p)
{
    int n = -1;
    if (count(p) < 1)
        return n;

    if (count(p) == 1)
        return p->data;

    while (p)
    {
        if (p->data > n)
            n = p->data;
        p = p->next;
    }
    return n;
}

void sortedInsert(Node *p, int n)
{
    struct Node *q = NULL, *t;
    t = (Node *)malloc(sizeof(Node));
    t->data = n;
    t->next = NULL;
    if (!first)
        first = t;
    else
    {
        while (p && p->data < n)
        {
            q = p;
            p = p->next;
        }
        q->next = t;
        t->next = p;
    }
}

int delete (Node *p, int index)
{
    Node *q = NULL, *t;
    int x = -1, i;
    if (count(p) < 1)
        return x;

    if (index == 0)
    {
        t = p;
        x = t->data;
        first = t->next;
        free(t);
        return x;
    }
    for (i = 0; i < index; i++)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    free(p);
    return x;
}

void isSorted(Node *p)
{
    while (p && p->next)
    {
        if (!(p->data < p->next->data))
        {
            printf("Not sorted");
            return;
        }
        p = p->next;
    }
    printf("Sorted");
}

void removeDuplicate(Node *p)
{
    Node *q = p->next;

    while (q)
    {
        if (q->data != p->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

void reverse(Node *p)
{
    Node *r = NULL, *q = NULL;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void reverseRec(Node *q, struct Node *p)
{
    if (p)
    {
        reverseRec(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

void merge(Node *p, Node *q)
{
    Node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }

    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }

    if (p)
        last->next = p;
    if (q)
        last->next = q;
}

int isloop(Node *f)
{
    Node *p, *q;
    p = q = f;
    do
    {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    } while (p && q && p != q);
    if (p == q)
        return 1;
    else
        return 0;
}

int main()
{
    Node *t1, *t2;
    int A[] = {10, 20, 30, 45, 50};
    create1(A, 5);

    t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next = t1;

    printf("Is loop :%d", isloop(first));
    // int B[] = {5, 12, 34, 43, 544};
    // create2(B, 5);
    // merge(first, second);
    //delete(first, 4);
    //isSorted(first);
    //removeDuplicate(first);
    //printf("Max is %d\n", max(first));
    // reverseRec(NULL, first);
    // display(third);
}