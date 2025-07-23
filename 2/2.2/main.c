#include <stdio.h>
#include "calc.h"

int main()
{
    int choice, a, b;
    float result;
    while (1)
    {
        printf("Calculator:\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("0. Exit\n");
        printf("Choose an operation: ");
        scanf("%d", &choice);

        if (choice == 0)
        {
            printf("Exiting the program.\n");
            break;
        }

        printf("Enter a numbers: ");
        scanf("%d", &a);
        printf("Enter b numbers: ");
        scanf("%d", &b);

        switch (choice)
        {
        case 1:
            result = add(a, b);
            printf("Result: %f\n", result);
            break;
        case 2:
            result = subtract(a, b);
            printf("Result: %f\n", result);
            break;
        case 3:
            result = multiply(a, b);
            printf("Result: %f\n", result);
            break;
        case 4:
            result = divide(a, b);
            printf("Result: %f\n", result);
            break;
        default:
            printf("Invalid choice!\n");
        }
        printf("\n");
    }
    return 0;
}