#include "list.h"

#include <stdlib.h>

struct DoublyLinkedList *createList() {
    struct DoublyLinkedList *list = (struct DoublyLinkedList*)malloc(sizeof(struct DoublyLinkedList));

    if (!list) {
        return NULL;
    }

    // Using the concept of Sentinel Nodes
    list->head = createNode(-1, 0, 0); // (pid, at, bt) 
    list->tail = createNode(-1, 0, 0); // (pid, at, bt)
    
    // Linking the sentinel nodes(empty list):
    list->head->next = list->tail;
    list->tail->prev = list->head;

    // Absolute Boundaries:
    list->head->prev = NULL;
    list->tail->next = NULL;

    list->length = 0;

    return list;
}