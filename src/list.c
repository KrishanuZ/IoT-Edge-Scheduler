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

bool push_front(struct DoublyLinkedList *list, struct ProcessNode *node) {
    if (!list || !node) {
        return false;
    }

    // Link node with neighbors:
    node->next = list->head->next; // Link the previous 'first' node to the new one
    node->prev = list->head; // Link new node's prev to head sentinel

    // Link neighbors to the new node:
    node->next->prev = node; // The previous 'first' node to the new one
    list->head->next = node; // The new node is the first node
    
    list->length++;

    return true;
}

bool push_back(struct DoublyLinkedList *list, struct ProcessNode *node) {
    if (!list || !node) {
        return false;
    }

    // Link node with neighbors:
    node->next = list->tail;
    node->prev = list->tail->prev;

    // Link neighbors with node:
    node->prev->next = node;
    list->tail->prev = node;

    list->length++;

    return true;
}

bool checkEmptyList(struct DoublyLinkedList *list) {
    if (list->head->next == list->tail || !list) {
        return true;
    }
    return false;
}

struct ProcessNode *pop_front(struct DoublyLinkedList *list) {
    if (!list || checkEmptyList(list)) {
        return NULL;
    }
    
    struct ProcessNode *popNode = list->head->next;

    // Update links of neighbors
    list->head->next = popNode->next;
    popNode->next->prev = list->head;

    // De-link node with neighbors:
    popNode->next = NULL;
    popNode->prev = NULL;

    list->length --;

    return popNode;
}

struct ProcessNode *pop_back(struct DoublyLinkedList *list) {
    if (!list || checkEmptyList(list)) {
        return NULL;
    }

    struct ProcessNode *popNode = list->tail->prev;

    // Update links of neighbors:
    list->tail->prev = popNode->prev;
    popNode->prev->next = list->tail;

    // De-link node with neighbors:
    popNode->next = NULL;
    popNode->prev = NULL;

    list->length--;

    return popNode;
}

struct DoublyLinkedList *destroyList(struct DoublyLinkedList* list) {
    if (!list) {
        return NULL;
    }

    while (!checkEmptyList(list)) {
        struct ProcessNode *deleteNode = pop_front(list);
        destroyNode(deleteNode);
    }
    
    free(list->head);
    free(list->tail);

    free(list);

    return NULL;
}