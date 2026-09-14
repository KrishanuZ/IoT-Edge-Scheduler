#include <stdlib.h>
#include "dll.h"

struct ProcessNode *createNode(pid_t pid, unsigned int at, unsigned int bt) {
    struct ProcessNode *newNode = (struct ProcessNode *)malloc(sizeof(struct ProcessNode));

    if (!newNode) {
        return NULL;
    }

    // Assign links to NULL
    newNode->prev = NULL;
    newNode->next = NULL;

    newNode->pid = pid;
    newNode->at = at;
    newNode->bt = bt;
    newNode->wt = newNode->bt; // Since the execution hasn't started yet

    // Assign 0 to avoid generating garbage values
    newNode->ct = 0;
    newNode->tat=0;
    newNode->wt=0;

    return newNode;
}

struct ProcessNode *destroyNode(struct ProcessNode *node) {

    // Explicitly clear out the links
    node->prev = NULL;
    node->next = NULL;
    
    free(node);
    return NULL; // Explicitly return NULL to avoid a dangling pointer
}