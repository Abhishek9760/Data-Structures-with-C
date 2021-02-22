#include <stdio.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void display(struct Array arr)
{
    int i;
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

void append(struct Array *arr, int n)
{
    if (arr->length == arr->size)
        return;
    arr->A[arr->length - 1] = n;
    arr->length++;
}

void insert(struct Array *arr, int index, int n)
{
    int i = arr->length - 1;
    if (arr->length == arr->size)
        return;
    while (i != index - 1)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[index] = n;
    arr->length++;
}

void delete (struct Array *arr, int index)
{
    if (arr->length == 0)
        return;
    for (int i = index; i < arr->length - 1; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }
    arr->length--;
}

void linearSearch(struct Array arr, int key)
{
    int i;
    for (i = 0; i < arr.length; i++)
    {
        if (arr.A[i] == key)
        {
            printf("Key found");
            return;
        }
    }
    printf("Key not found");
}

void binarySearch(struct Array arr, int key)
{
    int L = 0, U = arr.length - 1;
    int mid;

    while (L <= U)
    {
        mid = (L + U) / 2;
        if (key == arr.A[mid])
        {
            printf("Key found");
            return;
        }
        else if (key < arr.A[mid])
            U = mid - 1;
        else
            L = mid + 1;
    }
    printf("Key not found");
}

void reverse1(struct Array *arr)
{
    int i, j;
    int B[10];
    for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
        B[j] = arr->A[i];
    for (i = 0; i < arr->length; i++)
        arr->A[i] = B[i];
}

void reverse2(struct Array *arr)
{
    int i, j;
    int temp;
    for (i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}

int main()
{
    struct Array a = {{1, 2, 3, 4}, 10, 4};
    // append(&a, 12);
    // display(a);
    // insert(&a, 1, 99);
    display(a);
    reverse2(&a);
    // delete (&a, 0);
    // binarySearch(a, 5);
    display(a);
}