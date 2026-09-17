#include "scheduler.h"

void fcfs(struct DoublyLinkedList *readyQueue) {
    if (!readyQueue || checkEmptyList(readyQueue)) {
        return;
    }

    unsigned int current_tick = 0;

    struct ProcessNode *currProcess = readyQueue->head->next;

    while (!checkEmptyList(readyQueue)) {
        if(current_tick < currProcess->at) {
            current_tick += currProcess->at;
        }

        current_tick = current_tick + currProcess->bt; // Complete the Process
        currProcess->ct = current_tick; // Update current tick

        // Update time netrics
        currProcess->tat = currProcess->ct - currProcess->at; 
        currProcess->wt = currProcess->tat - currProcess->bt;

        // Traverse to next node
        currProcess = currProcess->next;
    }
}