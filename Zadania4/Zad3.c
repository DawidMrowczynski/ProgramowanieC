#include <stdio.h>

void permute(int *array, int start, int end);

int main()
{
    int array[] = {1, 2, 3};
    int n = sizeof(array) / sizeof(array[0]);

    permute(array, 0, n - 1);

    return 0;
}

void permute(int *array, int start, int end)
{
    if (start == end)
    {
        for (int i = 0; i <= end; i++)
        {
            printf("%d ", array[i]);
        }
        printf("\n");
    }
    else
    {
        for (int i = start; i <= end; i++)
        {
            int tmp = array[start];
            array[start] = array[i];
            array[i] = tmp;

            permute(array, start + 1, end);

            tmp = array[start];
            array[start] = array[i];
            array[i] = tmp;
        }
    }
}