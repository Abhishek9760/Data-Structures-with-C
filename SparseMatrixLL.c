#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int col;
    int val;
    struct Node *next;
} Node;

void create(Node *A[], int n)
{
    int i, row, col, val;
    Node *t, *p;
    for (i = 0; i < n; i++)
    {
        printf("Enter row, col and val :");
        scanf("%d%d%d", &row, &col, &val);

        t = (Node *)malloc(sizeof(Node));
        t->val = val;
        t->col = col;
        if (A[row] == NULL)
        {
            t->next = NULL;
            A[row] = t;
        }
        else
        {
            p = A[row];
            while (p->next != NULL)
                p = p->next;
            p->next = t;
        }
    }
}

void display(Node *A[], int rows, int cols)
{
    int i, j;
    Node *p;
    for (i = 0; i < rows; i++)
    {
        p = A[i];
        for (j = 0; j < cols; j++)
        {
            if (p && j == p->col)
            {
                printf("%d ", p->val);
                p = p->next;
            }
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    int rows, cols, n, i;
    printf("Enter rows and cols :");
    scanf("%d%d", &rows, &cols);
    Node *A[rows];
    for (i = 0; i < rows; i++)
        A[i] = NULL;
    printf("Enter no. of elements :");
    scanf("%d", &n);
    create(A, n);
    display(A, rows, cols);
}