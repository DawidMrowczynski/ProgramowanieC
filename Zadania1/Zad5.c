#include <stdio.h>

int sumMultiple(int n);

int main()
{
    int sum = sumMultiple(15);
    printf("%i\n", sum);
    
    return 0;
}


int sumMultiple(int n)
{
    if (n < 0)
    {
        return 0;
    }
    
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            sum += i;
        }
    }
    return sum;
}