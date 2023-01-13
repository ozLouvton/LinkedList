#include "LinkedList.h"
#include <stdlib.h>

Node *push(LinkedList *list, void *value);
Iterator *iterator(LinkedList *list);
boolean goNext(Iterator *iterator);
void *getValue(Iterator *iterator);

LinkedList *initList()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->iterator = iterator;
    list->push = push;
    list->first = (Node *)malloc(sizeof(Node));
    list->first->value = NULL;
    list->first->next = NULL;
    list->last = list->first;
    return list;
}

Node *push(LinkedList *list, void *value)
{
    Node *new;
    new = (Node *)malloc(sizeof(Node));
    new->value = value;
    new->next = NULL;
    list->last->next = new;
    list->last = new;
    return new;
}
Iterator *iterator(LinkedList *list)
{
    Iterator *newIterator = (Iterator *)malloc(sizeof(Iterator));
    newIterator->getValue = getValue;
    newIterator->goNext = goNext;
    newIterator->current = list->first->next;
    return newIterator;
}
boolean goNext(Iterator *iterator)
{
    if (iterator->current->next == NULL)
    {
        return FALSE;
    }
    iterator->current = iterator->current->next;
    return TRUE;
}
void *getValue(Iterator *iterator)
{
    return iterator->current->value;
}