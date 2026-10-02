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

    // Using the concept of Sentinel tasks
    list->head = createTask(-1, "[SENTINEL-HEAD]", 0, 0); // (tid, taskName, at, bt) 
    list->tail = createTask(-1, "[SENTINEL-TAIL]", 0, 0); // (tid, taskName, at, bt)
    
    // Linking the sentinel tasks(empty list):
    list->head->next = list->tail;
    list->tail->prev = list->head;

    // Absolute Boundaries:
    list->head->prev = NULL;
    list->tail->next = NULL;

    list->length = 0;

    return list;
}

bool push_front(struct DoublyLinkedList *list, struct SensorTask *task) {
    if (!list || !task) {
        return false;
    }

    // Link task with neighbors:
    task->next = list->head->next; // Link the previous 'first' task to the new one
    task->prev = list->head; // Link new task's prev to head sentinel

    // Link neighbors to the new task:
    task->next->prev = task; // The previous 'first' task to the new one
    list->head->next = task; // The new task is the first task
    
    list->length++;

    return true;
}

bool push_back(struct DoublyLinkedList *list, struct SensorTask *task) {
    if (!list || !task) {
        return false;
    }

    // Link task with neighbors:
    task->next = list->tail;
    task->prev = list->tail->prev;

    // Link neighbors with task:
    task->prev->next = task;
    list->tail->prev = task;

    list->length++;

    return true;
}

bool checkEmptyList(struct DoublyLinkedList *list) {
    if (list->head->next == list->tail || !list) {
        return true;
    }
    return false;
}

struct SensorTask *pop_front(struct DoublyLinkedList *list) {
    if (!list || checkEmptyList(list)) {
        return NULL;
    }
    
    struct SensorTask *poptask = list->head->next;

    // Update links of neighbors
    list->head->next = poptask->next;
    poptask->next->prev = list->head;

    // De-link task with neighbors:
    poptask->next = NULL;
    poptask->prev = NULL;

    list->length --;

    return poptask;
}

struct SensorTask *pop_back(struct DoublyLinkedList *list) {
    if (!list || checkEmptyList(list)) {
        return NULL;
    }

    struct SensorTask *popTask = list->tail->prev;

    // Update links of neighbors:
    list->tail->prev = popTask->prev;
    popTask->prev->next = list->tail;

    // De-link task with neighbors:
    popTask->next = NULL;
    popTask->prev = NULL;

    list->length--;

    return popTask;
}

struct DoublyLinkedList *destroyList(struct DoublyLinkedList* list) {
    if (!list) {
        return NULL;
    }

    while (!checkEmptyList(list)) {
        struct SensorTask *deleteTask = pop_front(list);
        destroyTask(deleteTask);
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

    struct SensorTask *currTask = list->head->next;

    printf("Task ID | Task Name | Arrival Time | Burst Time | Completion Time | TurnAround Time | Waiting Time\n");
    while(currTask != list->tail) {
        printf("%-7d | %-9s | %-12d | %-10d | %-15d | %-15d | %-12d\n", currTask->tid, currTask->taskName, currTask->at, currTask->bt, currTask->ct, currTask->tat, currTask->wt);
        currTask = currTask->next;
    }
}

void swapProcess(struct SensorTask *a, struct SensorTask *b) {
    // Storing 'a' in temp
    pid_t temp_id = a->tid;
    unsigned int temp_at = a->at;
    unsigned int temp_bt = a->bt;
    unsigned int temp_ct = a->ct;
    unsigned int temp_rt = a->rt;
    unsigned int temp_tat = a->tat;
    unsigned int temp_wt = a->wt;

    a->tid = b->tid;
    a->at = b->at;
    a->bt = b->bt;
    a->ct = b->ct;
    a->rt = b->rt;
    a->tat = b->tat;
    a->wt = b->wt;

    b->tid = temp_id;
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
    struct SensorTask *currTask = list->head->next->next; // Starting from second node

    while (currTask != list->tail) {
        struct SensorTask *j = currTask; // Storing the current Process

        while (j->prev != list->head && j->at < j->prev->at) {
            swapProcess(j, j->prev);
            j = j->prev;
        }
        currTask = currTask->next; // Onto the next Process
    }
}

void sortByBurst(struct DoublyLinkedList *list) {
    if (!list || checkEmptyList(list) || list->head->next == list->tail->prev) {
        // No sorting when: pointer = NULL, list = empty, list has only one node
        return;
    }
    
    // Insertion Sort:
    struct SensorTask *currTask = list->head->next->next; // From 2nd task

    while (currTask != list->tail) {
        struct SensorTask *j = currTask;

        while (j->prev != list->head && j->bt < j->prev->bt) { // Checking by 'bt`
            swapProcess(j, j->prev);
            j = j->prev;
        }
        currTask = currTask->next;
    }
}