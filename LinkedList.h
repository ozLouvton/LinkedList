#ifndef LINKED_LIST
#define LINKED_LIST

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
};

struct LinkedList
{
    Node *first;
    Node *last;
    Node *(*push)(LinkedList *list, void *value);
    Iterator *(*iterator)(LinkedList *list);
};

LinkedList *initList();

#endif