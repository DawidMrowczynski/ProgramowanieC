#include <stdio.h>

int add(int n1, int n2);
int multiply(int n1, int n2);
int subtract(int n1, int n2);

int main()
{
    int (*pf)(int, int);
    int n1, n2, choice, result;

    printf("Enter first number: ");
    scanf("%d", &n1);
    printf("Enter second number: ");
    scanf("%d", &n2);

    printf("Choose operation:\n");
    printf("1. Add\n");
    printf("2. Multiply\n");
    printf("3. Subtract\n");
    printf("Option: ");
    scanf("%d", &choice);

    switch(choice) 
    {
        case 1:
            pf = &add;
            result = (pf)(n1, n2);
            printf("Result of addition: %d\n", result);
            break;
        case 2:
            pf = &multiply;
            result = (pf)(n1, n2);
            printf("Result of multiplication: %d\n", result);
            break;
        case 3:
            pf = &subtract;
            result = (pf)(n1, n2);
            printf("Result of subtraction: %d\n", result);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}

int add(int n1, int n2)
{
    return (n1 + n2);
}

int multiply(int n1, int n2)
{
    return (n1 * n2);
}

int subtract(int n1, int n2)
{
    return (n1 - n2);
}