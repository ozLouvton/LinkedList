# C linked list

The `LinkedList.h` file presents the structures and methods to create a generic linked list. Use `initList()` to create a new linked list. The `main.c` presents a full example of how to add items to the list and use its iterator. Make sure to call `free` for any list and iterator you've created to remove any allocated memory. The function `free` for the list will also free any value she got to add to the list, so don't worry about that.

## Serialization

You can save your list's values to a file by calling `serialize`. You can only do that if your list's values have the same size. You can deserialize by calling a list's `deserialize` function. Given a serialized file, it will add all the values in the file to the list.
