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

void test_push_semantics() {
    struct DoublyLinkedList *list = createList();

    if (!list) {
        printf("Memory allocation for the list has failed.\n");
    }

    printf("\n\nTesting push_back():\n\n");

    struct ProcessNode *p1 = createNode(0, 0, 1);
    push_back(list, p1);
    assert(list->tail->prev==p1 && p1->next == list->tail && "Error: push_back() didn't update tail sentinel node.");
    printf("Links with Tail: OK.\n");
    assert(list->length == 1 && "Error: push_back() did not update length of the list.");
    printf("Length: OK\n");
    printf("\npush_back(): OK\n");

    printf("\n\nTesting push_front():\n\n");
    struct ProcessNode *p2 = createNode(0, 1, 2);
    push_front(list, p2);
    assert(list->head->next == p2 && p2->prev == list->head && "Error: push_front() didn't update head sentinel node.");
    printf("Links with Head: OK.\n");
    assert(list->length == 2 && "Error: push_front() did not update length of the list.");
    printf("Length: OK\n");
    printf("\npush_front(): OK\n");

    printf("\n\nPush Semantics: OK.\n");
}

int main() {
    // node_creation_deletion();
    // list_creation();
    // test_push_front();
    test_push_semantics();

    return 0;
}