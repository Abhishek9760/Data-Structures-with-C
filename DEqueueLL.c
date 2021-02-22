#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *front = NULL, *rear = NULL;

void enqueue(int x)
{
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

int isEmpty()
{
    return front == NULL;
}

int dequeue()
{
    int x = -1;
    if (isEmpty())
        printf("Queue is empty");
    else
    {
        Node *t = front;
        x = t->data;
        front = front->next;
        free(t);
    }
    return x;
}

void display()
{
    Node *p = front;
    if (isEmpty())
        printf("Queue is empty");
    else
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