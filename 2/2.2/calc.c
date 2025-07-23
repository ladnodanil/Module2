#include "calc.h"
#include <stdio.h>
int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

float divide(int a, int b)
{
    if (b == 0)
    {
        printf("null\n");
        return 0;
    }
    return (float)a / b;
}
