#include <stdio.h>

union myUnion 
{
    int intUnion;
    float floatUnion;
    char charUnion;
};

int main() 
{
    union myUnion uni;

    uni.intUnion = 77;
    printf("Union int: %i\n", uni.intUnion);

    uni.floatUnion = 5.54;
    printf("Union float: %.2f\n", uni.floatUnion);

    uni.charUnion = 'C';
    printf("Union char: %c\n", uni.charUnion);

    return 0;
}