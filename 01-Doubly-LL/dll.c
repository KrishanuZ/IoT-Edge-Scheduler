#include <stdlib.h>
#include "dll.h"

struct ProcessNode *createNode() {
    struct ProcessNode *newNode = (struct ProcessNode *)malloc(sizeof(struct ProcessNode));

    if (!newNode) {
        return NULL;
    }

    // Assign links to NULL
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct ProcessNode *deleteNode(struct ProcessNode *deleteNode) {
    free(deleteNode);
    return NULL; // Explicitly return NULL to avoid a dangling pointer
}