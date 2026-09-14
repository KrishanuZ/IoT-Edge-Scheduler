#include "list.h"

#include <stdlib.h>

struct DoublyLinkedList *createList() {
    struct DoublyLinkedList *list = (struct DoublyLinkedList*)malloc(sizeof(struct DoublyLinkedList));

    if (!list) {
        return NULL;
    }
    // Assign links to NULL
    list->head = NULL;
    list->tail = NULL;

    list->length = 0;

    return list;
}