#include <time.h>
#include "queue.h"

int main()
{
    Item *head = NULL;
    srand((unsigned)time(NULL));
    printf("Generating messages:\n");
    for (int i = 0; i < 15; ++i)
    {
        int data = rand() % 100;
        uint8_t prio = rand() % 256;
        printf("Adding: %d[%d]\n", data, prio);
        head = Push(data, prio, head);
    }

    printf("\nQueue after generation:\n");
    PrintQueue(head);

    printf("\nFront element: %d[%d]\n", Front(head)->data, Front(head)->priority);
    printf("\nBack element: %d[%d]\n", Back(head)->data, Back(head)->priority);

    printf("\nRemoving the first element with priority 100:\n");
    head = PopPriority(100, head);
    PrintQueue(head);

    printf("\nRemoving the last element with priority >= 150:\n");
    head = PopPriorityMin(150, head);
    PrintQueue(head);

    printf("\nRemoving the last element:\n");
    head = Pop(head);
    PrintQueue(head);

    while (head != NULL)
    {
        head = Pop(head);
    }
    return 0;
}