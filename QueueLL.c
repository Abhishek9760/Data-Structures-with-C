#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

void enqueue(int x)
{
    int i;
    Node *t;
    t = (Node *)malloc(sizeof(Node));
    t->data = x;
    t->next = NULL;
    if (front == NULL)
        front = rear = t;
    else
    {
        rear->next = t;
        rear = t;
    }
}

int dequeue()
{
    int x = -1;
    Node *t;
    if (front == NULL)
        printf("Queue is empty\n");
    else
    {
        t = front;
        x = t->data;
        front = front->next;
        free(t);
    }
    return x;
}

void display()
{
    Node *p = front;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    dequeue();
    display();
}