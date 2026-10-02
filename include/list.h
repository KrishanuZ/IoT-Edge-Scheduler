#ifndef LIST_H
#define LIST_H

#include "task.h"

#include <stdlib.h>
#include <stdbool.h>

// Struct:
struct DoublyLinkedList {
    struct SensorTask *head;
    struct SensorTask *tail;

    size_t length; // To track the length of the DLL
};

// Functions:
struct DoublyLinkedList *createList();
bool push_front(struct DoublyLinkedList*, struct SensorTask*);
bool push_back(struct DoublyLinkedList*, struct SensorTask*);
bool checkEmptyList(struct DoublyLinkedList*); // Helper function
struct SensorTask *pop_front(struct DoublyLinkedList*);
struct SensorTask *pop_back(struct DoublyLinkedList*);
struct DoublyLinkedList *destroyList(struct DoublyLinkedList*);
void displayList(struct DoublyLinkedList*);
void swapProcess(struct SensorTask*, struct SensorTask*); // Helper function
void sortByArrival(struct DoublyLinkedList*);
void sortByBurst(struct DoublyLinkedList*);

#endif