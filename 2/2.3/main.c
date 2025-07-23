
#include <stdio.h>
#include "calc2.h"

int main()
{
    int choice, a, b;
    float result;
    float (*op)(int , int );

    while (1)
    {
        printf("Calculator:\n");
        for (int i = 0; i < SIZE; i++)
        {
            printf("%d. %s\n", operations[i].id, operations[i].name);
        }

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

        if (choice >= 1 && choice <= SIZE)
        {
            op = select(choice);
            printf("Result: %f\n", op(a, b));
        }
        else
        {
            printf("Invalid choice!\n");
        }
        printf("\n");
    }
    return 0;
}
