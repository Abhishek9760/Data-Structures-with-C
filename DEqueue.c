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

int isEmpty(Queue q)
{
    return q.front == q.rear;
}

int isFull(Queue q)
{
    return q.rear == q.size - 1;
}

void enqueueR(Queue *q, int x)
{
    if (isFull(*q))
        printf("Queue is full\n");
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

void enqueueF(Queue *q, int x)
{
    if (isFull(*q))
        printf("Queue is full\n");
    else
    {
        q->Q[q->front--] = x;
    }
}

int dequeueF(Queue *q)
{
    int x = -1;
    if (isEmpty(*q))
        printf("Queue is empty");
    else
        x = q->Q[q->front++];
    return x;
}

int dequeueR(Queue *q)
{
    int x = -1;
    if (isEmpty(*q))
        printf("Queue is empty");
    else
        x = q->Q[q->rear--];
    return x;
}

void display(Queue q)
{
    int i;

    if (isEmpty(q))
        printf("Queue is empty");
    for (i = q.front + 1; i < q.rear + 1; i++)
        printf("%d ", q.Q[i]);
}

int main()
{
    Queue q;
    create(&q, 5);
    enqueueF(&q, 10);
    enqueueF(&q, 20);
    enqueueF(&q, 30);
    enqueueR(&q, 40);
    enqueueR(&q, 50);
    dequeueF(&q);
    dequeueR(&q);
    dequeueF(&q);
    dequeueR(&q);
    dequeueF(&q);
    display(q);
}