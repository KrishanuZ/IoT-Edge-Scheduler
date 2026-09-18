#include "scheduler.h"

#include <stdio.h>

struct DoublyLinkedList *initialize_process() {
    struct DoublyLinkedList *readyQueue = createList();

    if (!readyQueue) {
        printf("Memory Allocation for ReadyQueue has failed.\n");
        return NULL;
    }

    struct ProcessNode *process[5];

    for(int i = 0; i < 5; i++) {
        process[i] = createNode(i + 1, i, i + 1);
        push_back(readyQueue, process[i]);
    }

    return readyQueue;
}

void test_fcfs (struct DoublyLinkedList *readyQueue) {
    if(!readyQueue || checkEmptyList(readyQueue)) {
        return;
    }

    fcfs(readyQueue);

    displayList(readyQueue);
}

void test_sort() {
    struct DoublyLinkedList *readyQueue = initialize_process();

    if(!readyQueue || checkEmptyList(readyQueue)) {
        return 1;
    }

    test_sort(readyQueue);

    struct ProcessNode *p1 = createNode(1, 0, 1);
    struct ProcessNode *p2 = createNode(2, 2, 5);
    struct ProcessNode *p3 = createNode(3, 5, 1);
    struct ProcessNode *p4 = createNode(4, 1, 2);
    struct ProcessNode *p5 = createNode(5, 4, 7);
    struct ProcessNode *p6 = createNode(6, 2, 1);

    push_back(readyQueue, p1);
    push_back(readyQueue, p2);
    push_back(readyQueue, p3);
    push_back(readyQueue, p4);
    push_back(readyQueue, p5);
    push_back(readyQueue, p6);

    if (!p1 || !p2 || !p3 || !p4 || !p5 || !p6) {
        printf("Memory Allocation for Process has failed.\n");
        return;
    }

    printf("Sorting By Arrival Time:\n");
    sortByArrival(readyQueue);
    displayList(readyQueue);

    printf("\nSorting By Burst Time:\n");
    sortByBurst(readyQueue);
    displayList(readyQueue);

    readyQueue = destroyList(readyQueue);
}

int main() {
    /* struct DoublyLinkedList *readyQueue = initialize_process();

    if(!readyQueue || checkEmptyList(readyQueue)) {
        return 1;
    }
    */

    // test_fcfs(readyQueue);
    test_sort();

    // readyQueue = destroyList(readyQueue);
    
    return 0;
}