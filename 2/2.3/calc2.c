#include "calc2.h"
#include <stdio.h>
#include <stddef.h>
#include <wchar.h>

Operation operations[SIZE] = {
    {1, "Adition (+)"},
    {2, "Subtraction (-)"},
    {3, "Multiplication (*)"},
    {4, "Division (/)"}};
float add(int a, int b)
{
    return a + b;
}

float subtract(int a, int b)
{
    return a - b;
}

float multiply(int a, int b)
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

float (*select(int choice))(int, int) {
    switch (choice) {
        case 1: return add;
        case 2: return subtract;
        case 3: return multiply;
        case 4: return divide;
        default: return add;
    }
}