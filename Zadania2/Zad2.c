#include <stdio.h>

void multiply(float *x);

int main()
{
   float x = 7.4;
   printf("x: %.2f\n", x);
   multiply(&x);
   printf("multiplied x: %.2f\n", x);
   
}

void multiply(float *x)
{
    *x *= 2;
}
