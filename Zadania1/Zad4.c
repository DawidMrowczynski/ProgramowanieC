#include <stdio.h>

int main()
{
    int i = 1;
    while (i < 201)
    {
        if (i % 5 == 0 && i % 7 == 0)
            printf("FooBar\n");
        else if (i % 5 == 0)
            printf("Foo\n");
        else if (i % 7 == 0)
            printf("Bar\n");
        else
            printf("%i\n", i);
        i++;
    
    }    
    return 0;
}
    
   