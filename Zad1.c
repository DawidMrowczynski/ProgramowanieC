#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter value: ");
    scanf("%i", &n);

    for (int i = 1; i <= n; i++) 
    { 
        int x = 1; 
        for (int j = 1; j <= i; j++) 
        { 
            printf("%d ", x); 
            x = x * (i - j) / j; 
        } 
        printf("\n"); 
    } 
}