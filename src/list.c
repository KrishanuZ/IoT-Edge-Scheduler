#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

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

void displayList(struct DoublyLinkedList *list) {
    if(!list || checkEmptyList(list)) {
        return;
    }

    struct ProcessNode *currNode = list->head->next;

    printf("Process ID | Arrival Time | Burst Time | Completion Time | TurnAround Time | Waiting Time\n");
    while(currNode != list->tail) {
        printf("%-10d | %-12d | %-10d | %-15d | %-15d | %-12d\n", currNode->pid, currNode->at, currNode->bt, currNode->ct, currNode->tat, currNode->wt);
        currNode = currNode->next;
    }
}

void swapProcess(struct ProcessNode *a, struct ProcessNode *b) {
    // Storing 'a' in temp
    pid_t temp_id = a->pid;
    unsigned int temp_at = a->at;
    unsigned int temp_bt = a->bt;
    unsigned int temp_ct = a->ct;
    unsigned int temp_rt = a->rt;
    unsigned int temp_tat = a->tat;
    unsigned int temp_wt = a->wt;

    a->pid = b->pid;
    a->at = b->at;
    a->bt = b->bt;
    a->ct = b->ct;
    a->rt = b->rt;
    a->tat = b->tat;
    a->wt = b->wt;

    b->pid = temp_id;
    b->at = temp_at;
    b->bt = temp_bt;
    b->ct = temp_ct;
    b->rt = temp_rt;
    b->tat = temp_tat;
    b->wt = temp_wt;
}

void sortByArrival(struct DoublyLinkedList *list) {
    if (!list || checkEmptyList(list) || list->head->next == list->tail->prev) {
        // No sorting when: pointer = NULL, list = empty, list has only one node 
        return;
    }
    // Insertion Sort:

    struct ProcessNode *currNode = list->head->next->next; // Starting from second node

    while (currNode != list->tail) {
        struct ProcessNode *j = currNode; // Storing the current Process

        while (j->prev != list->head && j->at < j->prev->at) {
            swapProcess(j, j->prev);
        }
        j = j->prev;
    }
    currNode = currNode->next; // Onto the next Process
}

void sortByBurst(struct DoublyLinkedList *list) {
    if (!list || checkEmptyList(list) || list->head->next == list->tail->prev) {
        // No sorting when: pointer = NULL, list = empty, list has only one node
        return;
    }
    
    // Insertion Sort:
    struct ProcessNode *currNode = list->head->next->next; // From 2nd node

    while (currNode != list->tail) {
        struct ProcessNode *j = currNode;

        while (j->prev != list->head && j->bt < j->prev->bt) { // Checking by 'bt`
            swapProcess(j, j->prev);
            j = j->prev;
        }
        currNode = currNode->next;
    }
}