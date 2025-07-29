#include <stdlib.h>
#include <stdio.h>
#include "person.h"

typedef struct Item
{
    Person person;
    struct Item *next;
    struct Item *prev;

} Item;

Item *GetValue(int index, Item *head);

Item *InsertValue(Person person, Item *head);

Item *DeleteValue(Person *person, Item *head);

void PrintList(Item *head);

Item *DeleteList(Item *head);
