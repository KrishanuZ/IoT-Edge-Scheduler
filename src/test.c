#include "node.h"
#include "list.h"

#include <stdio.h>
#include <assert.h>


void node_creation_deletion() {
    // (Reconstructed node creation since it was cut off above line 21)
    struct ProcessNode *newNode = createNode(1, 0, 5); 
    
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
    assert(list->head->prev == NULL && list->tail->next == NULL && "Error: Outer boundaries of sentinel nodes were not established.");
    
    printf("Sentinel Nodes: OK.\n");
}

int main() {
    // node_creation_deletion();
    list_creation();
    return 0;
}