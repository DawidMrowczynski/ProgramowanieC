#include <stdio.h>

void factorial(int array[], int length);

int main()
{
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int length = sizeof(array) / sizeof(array[0]); 
    factorial(array, length);
    return 0;
}

void factorial(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        int result = 1;
        for (int j = 1; j <= array[i]; j++)
        {
            result *= j;
        }
        printf("Factorial of %d: %d\n", array[i], result);
    }
}