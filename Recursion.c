#include <stdio.h>

int sum(int n)
{
    if (n == 0)
        return 0;
    return sum(n - 1) + n;
}

int factorial(int n)
{
    if (n == 1)
        return 1;
    return factorial(n - 1) * n;
}

int pow_(int m, int n)
{
    if (n == 0)
        return 1;
    return pow_(m, n - 1) * m;
}

int pow_2(int m, int n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
        return pow_2(m * m, n / 2);
    else
        return m * pow_2(m * m, (n - 1) / 2);
}

int e(int x, int n)
{
    static int f = 1, p = 1;
    int r;
    if (n == 0)
        return 1;
    else
    {
        r = e(x, n - 1);
        p = p * x;
        f = f * n;
        return r + p / f;
    }
}

int e_horner(int x, int n)
{
    // int r=1;
    // for(;n>0;n--)
    //     r=1+x/n*r;
    // return r;
    static int r = 1;
    if (n == 0)
        return r;
    r = 1 + x / n * r;
    return e_horner(x, n - 1);
}

int fib(int n)
{
    if (n <= 1)
        return n;
    else
        return fib(n - 2) + fib(n - 1);
}

int cache[10];

int fib_memo(int n)
{
    if (n < 2)
    {
        cache[n] = n;
        return n;
    }
    else
    {
        if (cache[n - 2] == -1)
            cache[n - 2] = fib(n - 2);

        if (cache[n - 1] == -1)
            cache[n - 1] = fib(n - 1);

        cache[n] = cache[n - 2] + cache[n - 1];
        return cache[n - 2] + cache[n - 1];
    }
}

int main()
{
    int i;
    for (i = 0; i < 10; i++)
        cache[i] = -1;

    printf("%d\n", fib_memo(10));
    for (i = 0; i < 10; i++)
        printf("%d ", cache[i]);
    return 0;
}
