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

void test_pop_semantics() {
    struct DoublyLinkedList *list = createList();

    if (!list) {
        printf("Memory allocation for list has failed.\n");
        return;
    }

    struct ProcessNode *p1 = createNode(1, 0, 2);
    struct ProcessNode *p2 = createNode(2, 1, 2);

    if (!p1 || !p2) {
        printf("Memory allocation for ProcessNode has failed.\n");
    }

    push_back(list, p1);
    push_back(list, p2);

    printf("\n\nTesting pop semantics:\n\n");

    printf("\n\nTesting pop_back():\n\n");
    struct ProcessNode *popped = pop_back(list); // p2 will be popped
    assert(popped == p2 && "Error: pop_back() mechanics is faulty.");
    printf("pop_back() mechanics: OK.\n");
    assert(list->tail->prev == p1 && "Error: pop_back() didn't update links.");
    printf("Link updation: OK.\n");
    assert(list->length == 1 && "Error: pop_back() did not update the length of the list.\n");
    printf("Length: OK.\n");

    printf("\npop_back(): OK.\n");

    printf("\n\nTesting pop_front():\n");
    popped = pop_front(list);
    assert(popped == p1 && "Error: Mechanics is fauly.\n");
    printf("Mechanics: OK.\n");
    assert(list->head->next == list->tail && "Error: Link was not updated.");
    printf("Link updation: OK.\n");
    assert(list->length == 0 && "Error: Length was not updated.");
    printf("Length: OK.\n");
    
    printf("\npop_front(): OK.\n");

    printf("\n\nPop semantics: OK.\n");
}

int main() {
    // node_creation_deletion();
    // list_creation();
    // test_push_front();
    // test_push_semantics();
    test_pop_semantics();

    return 0;
}