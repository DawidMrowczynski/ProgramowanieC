#include <stdio.h>

int main()
{
    int x = 3;
    int *pointer = &x;
    
    printf("x: %i\n", x);
    
    *pointer = 5;
    
    printf("x changedd: %i\n", x);

    return 0;
}
