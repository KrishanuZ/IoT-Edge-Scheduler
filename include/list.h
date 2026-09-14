#ifndef LIST_H
#define LIST_H

#include "node.h"

#include <stdlib.h>
#include <stdbool.h>

// Struct:
struct DoublyLinkedList {
    struct ProcessNode *head;
    struct ProcessNode *tail;

    size_t length; // To track the length of the DLL
};

// Functions:
struct DoublyLinkedList *createList();
bool push_front(struct DoublyLinkedList*, struct ProcessNode *);

#endif