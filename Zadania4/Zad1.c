#include <stdio.h>

int factorial(int n);

int main()
{
    printf("Factorial: %d", factorial(6));
    return 0;
}

int factorial(int n)
{
    if (n < 0)
    {
        printf("Only positive values allowed!");
        return 1;
    }
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return factorial(n - 1) * n;
}