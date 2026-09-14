#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "dll.h"

void node_creation_deletion() {
    
    // Creation:
    printf("\n\nTesting Creation:\n");
    struct ProcessNode *newNode = createNode(1, 0, 3); // Id: 1, Arrival Time: 0, Burst Time: 3
    
    if (!newNode) {
        printf("Memory Allocation has failed.\n");
        return;
    }
    printf("Memory Allocation: OK.\n");

    assert(newNode->pid == 1 && newNode->at == 0 && newNode->bt == 3 && "Metrics Assignment has failed.\n");
    printf("Metric Assignment: OK\n");
    printf("\nCreation: OK\n");

    //Deletion:
    printf("\n\nTesting Deletion:\n");
     assert(newNode->prev == NULL && newNode->next==NULL && "Error: Links are not NULL.\n");
    newNode = destroyNode(newNode);
    assert(newNode==NULL && "Error: Node's memory has leaked.\n");
    printf("\nDeletion: OK.\n");
}

int main() {
    node_creation_deletion();

    return 0;
}