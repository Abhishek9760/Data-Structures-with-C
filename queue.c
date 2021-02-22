#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
} Queue;

void create(Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(sizeof(int) * q->size);
}

void enqueue(Queue *q, int x)
{
    if (q->rear == q->size - 1)
        printf("Queue is full");
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int dequeue(Queue *q)
{
    int x = -1;
    if (q->front == q->rear)
        printf("Queue is empty\n");
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void display(Queue q)
{
    int i;
    for (i = q.front + 1; i < q.rear + 1; i++)
        printf("%d ", q.Q[i]);
    printf("\n");
}

int main()
{
    Queue q;
    create(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    dequeue(&q);
    display(q);
    return 0;
}