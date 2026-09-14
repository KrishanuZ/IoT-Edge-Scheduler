#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "dll.c"

void node_creation_deletion() {
    
    // Creation:
    struct ProcessNode *newNode = createNode(1, 0, 3); // Id: 1, Arrival Time: 0, Burst Time: 3
    
    if (!newNode) {
        printf("Memory Allocation has failed.\n");
        return;
    }
    printf("Memory Allocation: OK.\n");

    assert(newNode->pid == 1 && newNode->at == 0 && newNode->bt == 3 && "Metrics Assignment has failed.\n");
    printf("Metric Assignment: OK\n");
    printf("\nCreation: OK\n");
}