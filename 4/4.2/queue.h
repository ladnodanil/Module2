#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

typedef struct Item
{
    int data;
    uint8_t priority;
    struct Item *next;
} Item;

Item *Push(int data, uint8_t priority, Item *head);

void PrintQueue(Item *head);

Item *Front(Item *head);

Item *Back(Item *head);

Item *Pop(Item *head);

Item *PopPriority(uint8_t priority, Item *head);

Item *PopPriorityMin(uint8_t priority, Item *head);
