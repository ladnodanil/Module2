#include "item.h"

int main()
{
    Item *head = NULL;

    int choice, index;
    Person person;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Add contact\n");
        printf("2. Edit contact\n");
        printf("3. Delete contact\n");
        printf("4. Print all contacts\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("Input error!\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        while (getchar() != '\n')
            ;

        switch (choice)
        {
        case 1:
            Input(&person);
            head = InsertValue(person, head);
            break;
        case 2:
            while (getchar() != '\n');
            Input(&GetValue(index-1, head)->person);
            break;
        case 3:
            printf("Enter the contact number to delete (from 1 to %d): ", personCount);
            if (scanf("%d", &index) != 1 || index < 1 || index > personCount)
            {
                printf("Invalid number!\n");
                while (getchar() != '\n')
                    ;
                break;
            }
            while (getchar() != '\n')
                ;
            head = DeleteValue(&(GetValue(index-1, head)->person), head);
            break;
        case 4:
            PrintList(head);
            break;
        case 0:
            printf("Exiting the program.\n");
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
}