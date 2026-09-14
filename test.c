#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "node.h"
#include "list.h"

void node_creation_deletion() {
    
    // Creation:
    printf("\n\nTesting Creation:\n");
    struct ProcessNode *newNode = createNode(1, 0, 3); // Id: 1, Arrival Time: 0, Burst Time: 3
    
    if (!newNode) {
        printf("Memory Allocation has failed.\n");
        return;
    }
    printf("Memory Allocation: OK.\n");

    assert(newNode->pid == 1 && newNode->at == 0 && newNode->bt == 3 && "Error: Metrics Assignment has failed.");
    printf("Metric Assignment: OK\n");
    printf("\nCreation: OK\n");

    //Deletion:
    printf("\n\nTesting Deletion:\n");
    assert(newNode->prev == NULL && newNode->next==NULL && "Error: Links are not NULL.");
    newNode = destroyNode(newNode);
    assert(newNode==NULL && "Error: Node's memory has leaked.");
    printf("\nDeletion: OK.\n");
}

void list_creation() {
    
    printf("\n\nTesting List Creation:\n");

    struct DoublyLinkedList *list = createList();

    if (!list) {
        printf("Memory allocation for list has failed.\n");
        return;
    }
    printf("Memory Allocation: OK.\n");
    
    assert(list->head->next == list->tail && list->tail->prev == list->head && "Error: Sentinel Nodes are not linked in an emoty list.");
    assert(list->head->prev == NULL && list->tail->next && "Error: Outer boundaries of sentinel nodes were not established.");

    printf("Sentinel Nodes: OK.\n");
}

int main() {
    // node_creation_deletion();
    list_creation();
    return 0;
}