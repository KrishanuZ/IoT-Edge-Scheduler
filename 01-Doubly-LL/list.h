#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

#include "node.h"

struct DoublyLinkedList {
    struct ProcessNode *head;
    struct ProcessNode *tail;

    size_t length; // To track the length of the DLL
};

#endif
