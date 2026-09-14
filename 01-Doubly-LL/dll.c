#include <stdlib.h>
#include "dll.h"

struct ProcessNode *createNode() {
    struct ProcessNode *newNode = (struct ProcessNode *)malloc(sizeof(struct ProcessNode));

    if (!newNode) {
        return NULL;
    }

    return newNode;
}