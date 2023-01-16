#include "LinkedList.h"

Node *push(LinkedList *list, void *value);
Iterator *iterator(LinkedList *list);
void freeList(LinkedList *list);
boolean goNext(Iterator *iterator);
void *getValue(Iterator *iterator);
void freeIterator(Iterator *iterator);
void serializeList(LinkedList *list, char *path, size_t size_of_member);
void deserializeList(LinkedList *list, char *path);

void _setLinkedListFunctions(LinkedList *list)
{
    list->iterator = iterator;
    list->push = push;
    list->free = freeList;
    list->serialize = serializeList;
    list->deserialize = deserializeList;
}

LinkedList *initList()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    _setLinkedListFunctions(list);
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
    newIterator->free = freeIterator;
    return newIterator;
}

void serializeList(LinkedList *list, char *path, size_t size_of_member)
{
    FILE *fptr;
    fptr = fopen(path, "wb");
    fwrite(&size_of_member, sizeof(size_of_member), 1, fptr);
    Iterator *iter = list->iterator(list);
    while (1)
    {
        fwrite(iter->getValue(iter), size_of_member, 1, fptr);
        if (!iter->goNext(iter))
        {
            break;
        }
    }
    fclose(fptr);
    iter->free(iter);
}

void deserializeList(LinkedList *list, char *path)
{
    FILE *fptr;
    fptr = fopen(path, "rb");
    size_t size_of_member;
    fread(&size_of_member, sizeof(size_of_member), 1, fptr);
    while (1)
    {
        void *value = malloc(size_of_member);
        if (!fread(value, size_of_member, 1, fptr))
        {
            break;
        }
        list->push(list, value);
    }
    fclose(fptr);
}

void freeList(LinkedList *list)
{
    Node *current = list->first;
    while (current->next != NULL)
    {
        Node *temp = current;
        current = current->next;
        free(temp->value);
        free(temp);
    }
    free(current->value);
    free(current);
    free(list);
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

void freeIterator(Iterator *iterator)
{
    free(iterator);
}