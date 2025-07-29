#include "item.h"

Item *GetValue(int index, Item *head)
{
    if (head == NULL | index < 0)
        return NULL;
    Item *current = head;
    int currentIndex = 0;

    while (current != NULL && currentIndex < index)
    {
        current = current->next;
        currentIndex++;
    }
    return current;
}

Item *InsertValue(Person person, Item *head)
{
    Item *newItem = malloc(sizeof(Item));
    newItem->person = person;
    newItem->next = NULL;
    newItem->prev = NULL;

    Item *tmp = head;

    // список пуст
    if (head == NULL)
        return newItem;
    // вставка в начало
    if (newItem->person.LastName[0] < tmp->person.LastName[0])
    {
        newItem->next = tmp;
        tmp->prev = newItem;
        return newItem;
    }
    // вставка дальше
    while (tmp->next != NULL)
    {
        if (newItem->person.LastName[0] < tmp->next->person.LastName[0])
        {
            newItem->next = tmp->next;
            tmp->next->prev = newItem;
            tmp->next = newItem;
            newItem->prev = tmp;
            break;
        }
        else
        {
            tmp = tmp->next;
        }
    }
    tmp->next = newItem;
    newItem->prev = tmp;
    return head;
}

Item *DeleteValue(Person *person, Item *head)
{
    Item *prevItem = head;
    Item *deleteItem;
    if (head == NULL)
        return NULL;
    // удаление из начала
    if (memcmp(&(head->person), person, sizeof(Person)) == 0)
    {
        deleteItem = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(deleteItem);
        return head;
    }
    while (prevItem->next != NULL)
    {
        if (memcmp(&(prevItem->next->person), person, sizeof(Person)) == 0)
        {
            deleteItem = prevItem->next;
            prevItem->next = prevItem->next->next;
            if (prevItem->next != NULL)
                prevItem->next->prev = prevItem;
            free(deleteItem);
            return head;
        }
        else
            prevItem = prevItem->next;
    }
    return head;
}

void PrintList(Item *head)
{
    Item *tmp = head;
    if (head == NULL)
    {
        printf("List empty!\n");
        return;
    }
    do
    {
        PrintPerson(&(tmp->person));
        tmp = tmp->next;
    } while (tmp != NULL);
    printf("\n");
}

Item *DeleteList(Item *head)
{
    Item *tmp;
    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    return NULL;
}