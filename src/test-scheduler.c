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

void test_sort(struct DoublyLinkedList *readyQueue) {
    printf("Sorting By Arrival Time:\n");
    sortByArrival(readyQueue);
    displayList(readyQueue);

    printf("\nSorting By Burst Time:\n");
    sortByBurst(readyQueue);
    displayList(readyQueue);
}

int main() {
    struct DoublyLinkedList *readyQueue = initialize_process();

    if(!readyQueue || checkEmptyList(readyQueue)) {
        return 1;
    }

    // test_fcfs(readyQueue);
    test_sort(readyQueue);

    readyQueue = destroyList(readyQueue);
    
    return 0;
}