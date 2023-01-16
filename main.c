#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    LinkedList *list = initList();
    size_t stringLength = sizeof(char) * (strlen("number ") + 3);
    for (int i = 0; i < 10; i++)
    {
        char *val = (char *)malloc(stringLength);
        sprintf(val, "number %d", i);
        list->push(list, val);
    }
    Iterator *iterator = list->iterator(list);
    while (1)
    {
        printf("%s\n", (char *)iterator->getValue(iterator));
        if (!iterator->goNext(iterator))
        {
            break;
        }
    }
    list->free(list);
    iterator->free(iterator);
    return 0;
}