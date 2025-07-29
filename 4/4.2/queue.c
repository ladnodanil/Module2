#include "queue.h"

Item *Push(int data, uint8_t priority, Item *head)
{
    Item *newItem = malloc(sizeof(Item));
    newItem->data = data;
    newItem->next = NULL;
    newItem->priority = priority;
    Item *tmp = head;

    if (head == NULL)
        return newItem;
    if (newItem->priority < tmp->priority)
    {
        newItem->next = tmp;
        return newItem;
    }
    while (tmp->next != NULL)
    {
        if (newItem->priority < tmp->next->priority)
        {
            newItem->next = tmp->next;
            tmp->next = newItem;
            break;
        }
        else
        {
            tmp = tmp->next;
        }
    }
    tmp->next = newItem;
    return head;
}

void PrintQueue(Item *head)
{
    Item *tmp = head;
    if (head == NULL)
    {
        printf("List empty!\n");
        return;
    }
    do
    {
        printf("%d[%d] ", tmp->data, tmp->priority);
        tmp = tmp->next;
    } while (tmp != NULL);
    printf("\n");
}

Item *Front(Item *head)
{
    if (head == NULL)
    {
        printf("List empty!\n");
        return NULL;
    }
    return head;
}

Item *Back(Item *head)
{
    if (head == NULL)
    {
        printf("List empty!\n");
        return NULL;
    }
    Item *tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    return tmp;
}

Item *Pop(Item *head)
{
    if (head == NULL)
    {
        printf("List empty!\n");
        return NULL;
    }
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    Item *prevItem = head;
    while (prevItem->next->next != NULL)
    {
        prevItem = prevItem->next;
    }
    Item *deleteItem = prevItem->next;
    prevItem->next = NULL;
    free(deleteItem);
    return head;
}

Item *PopPriority(uint8_t priority, Item *head)
{
    if (head == NULL)
    {
        printf("List empty!\n");
        return NULL;
    }

    Item *curr = head;
    Item *prev = NULL;
    Item *lastMatch = NULL;
    Item *lastMatchPrev = NULL;

    while (curr != NULL)
    {
        if (curr->priority == priority)
        {
            lastMatch = curr;
            lastMatchPrev = prev;
        }
        prev = curr;
        curr = curr->next;
    }

    if (lastMatch == NULL)
    {
        printf("No element with such priority!\n");
        return head;
    }
    if (lastMatchPrev == NULL)
    {
        head = head->next;
        free(lastMatch);
    }
    else
    {
        lastMatchPrev->next = lastMatch->next;
        free(lastMatch);
    }
    return head;
}

Item *PopPriorityMin(uint8_t priority, Item *head)
{
    Item *curr = head;
    Item *prev = NULL;

    while (curr != NULL)
    {
        if (curr->priority >= priority)
        {
            Item *toDelete = curr;
            if (prev == NULL)
            {
                head = curr->next;
                curr = head;
            }
            else
            {
                prev->next = curr->next;
                curr = curr->next;
            }
            free(toDelete);
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}
