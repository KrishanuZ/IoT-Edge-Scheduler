#include "scheduler.h"

void fcfs(struct DoublyLinkedList *readyQueue) {
    if (!readyQueue || checkEmptyList(readyQueue)) {
        return;
    }

    unsigned int current_tick = 0;

    while (!checkEmptyList(readyQueue)) {
        struct ProcessNode *currProcess = pop_front(readyQueue);

        current_tick = current_tick + currProcess->bt; // Complete the Process
        currProcess->ct = current_tick; // Update current tick

        // Update tine netrics
        currProcess->tat = currProcess->ct - currProcess->at; 
        currProcess->wt = currProcess->tat - currProcess->bt;
    }
}