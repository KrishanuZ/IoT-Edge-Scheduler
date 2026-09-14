# Architecture: **Doubly Linked List**

## Structure: **Node**

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

| Variable | Metric | Description |
| :--- | :--- | :--- |
| `pid` | Process ID | Unique ID assigned to a process. |
| `at` | Arrival Time | The exact CPU tick when the process enters. |
| `bt` | Burst Time | The number of CPU ticks requested by the process to complete its execution. |
| `ct` | Completion Time | The exact CPU tick when the process exits the scheduler. |
| `tat` | TurnAround Time | The number of ticks for which the process was inside the scheduler. `tat=ct-at` |
| `wt` | Waiting Time | The number of CPU ticks for which the process was scheduled and was not using the resource. `wt=tat-bt` |
| `rt` | Remaining Time | The number of ticks left for the process to execute. |

### Core Functions

1. ```c
    struct ProcessNode *createNode(pid_t pid, unsigned int at, unsigned int bt)
   ```

    * **Concept**: Allocates memory to a process node using `malloc()`.
    * **Output**: Returns a pointer to a struct of type `ProcessNode`.
    * **Time Complexity**: `O(1)`.
    * **Space Complexity**:
        * **Input Space**: `O(1)`
        * **Auxiliary Space**: `O(1)`
        * **Output Space**: `O(1)`

2. ```c
    struct ProcessNode *destroyNode(struct ProcessNode *node)
   ```

    * **Concept**: Deallocates the memory of a process node using `free()`.
    * **Output**: Explicitly returns `NULL` pointer.
    * **Time Complexity**: `O(1)`.
    * **Space Complexity**:
        * **Input Space**: `O(1)`
        * **Auxiliary Space**: `O(1)`
        * **Output Space**: `O(1)`

---

## Structure: **Linked List Manager**

```c
struct DoublyLinkedList {
    struct ProcessNode *head;
    struct ProcessNode *tail;
    size_t length; 
};
```

* **Concept**: **head** and **tail** pointers are dynamically allocated Sentinel Nodes to eliminate `NULL` pointer edge cases.

### Core functions

1. ```c
    struct DoublyLinkedList *createList()
   ```

    * **Concept**: Allocates memory to a double ended queue of type `DoublyLinkedList` consisting of structures of type `ProcessNode`.
    * **Output**: Returns a pointer to a struct of type `DoublyLinkedList`.
    * **Time Complexity**: `O(1)`
    * **Space Complexity**:
      * **Input Space**: `O(1)`
      * **Auxilary Space**: `O(1)`
      * **Output Space**: `O(1)`
