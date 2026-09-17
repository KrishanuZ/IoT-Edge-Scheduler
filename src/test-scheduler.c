#include "scheduler.h"

struct DoublyLinkedList *initialize_process() {
    struct DoublyLinkedList *readyQueue = createList();

    if (!readyQueue) {
        printf("Memory Allocation for ReadyQueue has failed.\n");
        return NULL;
    }

    struct ProcessNode *process[5];

    if (!process) {
        printf("Memory allocation for process' array has failed.\n");
        return NULL;
    }

    for(int i = 0; i < 5; i++) {
        process[i] = createNode(i + 1, i, i + 1);
        push_back(readyQueue, process[i]);
    }

    return readyQueue;
}