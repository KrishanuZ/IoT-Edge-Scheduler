# **Architecture**: Doubly Linked List

## Structures

### Node

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

---

### Linked List Manager

```c
struct DoublyLinkedList {
    struct ProcessNode *head;
    struct ProcessNode *tail;
    size_t length; 
};
```

---

## Utility Functions

### 1. `createNode()`

```c
struct ProcessNode *createNode(pid_t, unsigned int, unsigned int)
```

* **Concept**: Allocates memeory to a process node using `malloc()`.
* **Output**: Returns struct of type `ProcessNode`.
* **Time Complexity:** `O(1)`.
* **Space Complexity:**
  * **Input Space**: `O(1)`
  * **Auxilary Space**: `O(1)`
  * **Output Space**: `O(1)`

### 2. `destroyNode()`

```c
struct ProcessNode *destroyNode(struct ProcessNode*)
```

* **Concept**: Deallocates the memory of a process node using `free()`.
* **Output**: Explicitly returns `NULL` pointer.
* **Time Complexity:** `O(1)`.
* **Space Complexity:**
  * **Input Space**: `O(1)`
  * **Auxilary Space**: `O(1)`
  * **Output Space**: `O(1)`
  