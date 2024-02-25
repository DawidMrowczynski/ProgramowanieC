#include <stdio.h>

int main()
{
    int grades[2][5] = {{2, 4, 5, 3, 3}, {5, 4, 4, 4, 2}};
    float math = 0;
    float physics= 0;
    
    for (int i = 0; i < 5; i++)
    {
        math += grades[0][i];
        physics += grades[1][i];
    }
    
    printf("Math avg: %.2f    Physics avg: %.2f", math/5, physics/5);
    
    return 0;
}
