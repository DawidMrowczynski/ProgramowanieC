#include <stdio.h>

int binarySearch(int array[], int left, int right, int target);

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("Index of target: %d", binarySearch(array, 0, 9, 8));

}

int binarySearch(int array[], int left, int right, int target)
{
    if(array[right] < target || array[left] > target)
    {
        return -1;
    }

    int m = left + (right - left) / 2;
    
    if (array[m] == target)
    {
        return m;
    }
    if (array[m] > target)
    {
        return binarySearch(array, left, m - 1, target);
    }
    else if (array[m] < target)
    {
        return binarySearch(array, m + 1, right, target);
    }


}