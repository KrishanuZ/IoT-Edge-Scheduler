#include <stdlib.h>
#include "node.h"

struct SensorTask *createTask(pid_t pid, const char *taskName, unsigned int at, unsigned int bt) {
    struct SensorTask *newNode = (struct SensorTask *)malloc(sizeof(struct SensorTask));

    if (!newNode) {
        return NULL;
    }

    // Assign links to NULL
    newNode->prev = NULL;
    newNode->next = NULL;

    newNode->pid = pid;
    newNode->at = at;
    newNode->bt = bt;
    newNode->rt = newNode->bt; // Since the execution hasn't started yet

    // Assign 0 to avoid generating garbage values
    newNode->ct = 0;
    newNode->tat=0;
    newNode->wt=0;

    newNode->is_completed = false;

    return newNode;
}

struct SensorTask *destroyTask(struct SensorTask *node) {

    // Explicitly clear out the links
    node->prev = NULL;
    node->next = NULL;
    
    free(node);
    return NULL; // Explicitly return NULL to avoid a dangling pointer
}