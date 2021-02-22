#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int front;
    int rear;
    int size;
    int *Q;
} Queue;

void create(Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueue(Queue *q, int x)
{
    if ((q->rear + 1) % q->size == q->front)
        printf("Queue is full\n");
    else
    {
        q->rear = (q->rear + 1) % q->size;
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
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

void display(Queue q)
{
    int i = q.front + 1;
    if (q.rear == q.front)
        printf("NULL");
    else
    {
        do
        {
            printf("%d ", q.Q[i]);
            i = (i + 1) % q.size;
        } while (i != (q.rear + 1) % q.size);
        printf("\n");
    }
}

int main()
{
    Queue q;
    create(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    display(q);
}