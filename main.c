#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    LinkedList *list = initList();
    size_t size = sizeof(int);
    for (int i = 3; i <= 30; i += 3)
    {
        int *val = (int *)malloc(size);
        *val = i;
        list->push(list, val);
    }
    Iterator *iterator = list->iterator(list);
    printf("Values added to the list:\n");
    while (1)
    {
        printf("%d", *((int *)iterator->getValue(iterator)));
        if (!iterator->goNext(iterator))
        {
            break;
        }
        printf(", ");
    }
    iterator->free(iterator);
    list->serialize(list, "./list.bin", size);
    list->free(list);

    list = initList();
    list->deserialize(list, "./list.bin");
    iterator = list->iterator(list);
    printf("\n\nDeserialized values:\n");
    while (1)
    {
        printf("%d", *((int *)iterator->getValue(iterator)));
        if (!iterator->goNext(iterator))
        {
            break;
        }
        printf(", ");
    }
    iterator->free(iterator);
    list->free(list);
    return 0;
}