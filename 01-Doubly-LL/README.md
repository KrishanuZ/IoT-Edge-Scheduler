# Architecture: Doubly Linked List

## Node

```c
struct ProcessNode {
    pid_t pid; 
    unsigned int at;    
    unsigned int bt;   
    unsigned int ct;    
    unsigned int tat;
    unsigned int wt;
    unsigned int rt; 
    struct ProcessNode *prev;
    struct ProcessNode *next;
};
```

## Linked List Manager

```c
struct DoublyLinkedList {
    struct ProcessNode *head;
    struct ProcessNode *tail;
    size_t length; 
};
```
