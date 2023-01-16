#ifndef LINKED_LIST
#define LINKED_LIST
#include <stdlib.h>
#include <stdio.h>

#ifndef NULL
#define NULL 0
#endif

typedef enum
{
    FALSE,
    TRUE
} boolean;

typedef struct Node Node;
typedef struct Iterator Iterator;
typedef struct LinkedList LinkedList;

struct Node
{
    Node *next;
    void *value;
};

struct Iterator
{
    Node *current;
    boolean (*goNext)(Iterator *);
    void *(*getValue)(Iterator *);
    void (*free)(Iterator *);
};

struct LinkedList
{
    Node *first;
    Node *last;
    Node *(*push)(LinkedList *list, void *value);
    Iterator *(*iterator)(LinkedList *list);
    void (*serialize)(LinkedList *list, char *path, size_t size_of_member);
    void (*free)(LinkedList *list);
    void (*deserialize)(LinkedList *list, char *path);
};

LinkedList *initList();

#endif