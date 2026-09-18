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
    * **Time Complexity**: `O(1)`
    * **Space Complexity**:
        * **Input Space**: `O(1)`
        * **Auxiliary Space**: `O(1)`
        * **Output Space**: `O(1)`

2. ```c
    struct ProcessNode *destroyNode(struct ProcessNode *node)
   ```

    * **Concept**: Deallocates the memory of a process node using `free()`.
    * **Output**: Explicitly returns `NULL` pointer.
    * **Time Complexity**: `O(1)`
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

2. ```c
    bool push_front(struct DoublyLinkedList*, struct ProcessNode*)
   ```

    * **Concept**: Adds a `ProcessNode` at the start of the list. Increments length of the list by **1**.
    * **Output**: Returns `false` when **NULL** pointers are passed. Returns `true` upon successful insertion.
    * **Time Complexity**: `O(1)`
    * **Space Complexity**:
      * **Input Space**: `O(1)`
      * **Auxilary Space**: `O(1)`
      * **Output Space**: `O(1)`

3. ```c
    bool push_back(struct DoublyLinkedList*, struct ProcessNode*)
   ```

   * **Concept**: Adds a `ProcessNode` at the end of the list. Increments length of the list by **1**.
   * **Output**: Returns `false` when **NULL** pointers are passed. Returns `true` upon successful insertion.
   * **Time Complexity**: `O(1)`
   * **Space Complexity**:
     * **Input Space**: `O(1)`
     * **Auxilary Space**: `O(1)`
     * **Output Space**: `O(1)`

4. ```c
    struct ProcessNode *pop_front(struct DoublyLinkedList*)
   ```

   * **Concept**: Removes a `ProcessNode` from the start of the list. Decrements length of the list by **1**.
   * **Output**: Returns `false` when **NULL** pointers are passed. Returns `true` upon successful removal.
   * **Time Complexity**: `O(1)`
   * **Space Complexity**:
     * **Input Space**: `O(1)`
     * **Auxilary Space**: `O(1)`
     * **Output Space**: `O(1)`

5. ```c
    struct ProcessNode *pop_back(struct DoublyLinkedList*)
   ```

   * **Concept**: Removes a `ProcessNode` at the end of the list. Decrements length of the list by **1**.
   * **Output**: Returns `false` when **NULL** pointers are passed. Returns `true` upon successful removal.
   * **Time Complexity**: `O(1)`
   * **Space Complexity**:
     * **Input Space**: `O(1)`
     * **Auxilary Space**: `O(1)`
     * **Output Space**: `O(1)`

6. ```c
    struct DoublyLinkedList *destroyList(struct DoublyLinkedList*)
   ```

   * **Concept**: Traverses and de-allocates all the `ProcessNode` sequentially.
   * **Output**: Returns a **NULL** pointer.
   * **Time Complexity**: `O(N)`
   * **Space Complexity**:
     * **Input Space**: `O(1)`
     * **Auxilary Space**: `O(1)`
     * **Output Space**: `O(1)`

7. ```c
    struct DoublyLinkedList *displayList(struct DoublyLinkedList*)
   ```

   * **Concept**: Traverses and displays `ProcessNode`.
   * **Output**: Time metrics of each `ProcessNode`.
   * **Time Complexity**: `O(N)`
   * **Space Complexity**:
     * **Input Space**: `O(1)`
     * **Auxilary Space**: `O(1)`
     * **Output Space**: `O(1)`

8. ```c
    void sortByArrival(struct DoublyLinkedList*)
    ```

    * **Concept**: Sorts the list with respect to **Arrival Time** using **Insertion Sort** algorithm.
    * **Output**: Arranges the list in increasing order of **Arrival Time**.
    * **Time Complexity**:
      * **Best Case**: `O(N)`
      * **Average Case**: `O(N^2)`
      * **Worst Case**: `O(N^2)`
    * **Space Complexity**:
      * **Input Space**: `O(1)`
      * **Auxilary Space**: `O(1)`
      * **Output Space**: `O(1)`

9. ```c
    void sortByBurst(struct DoublyLinkedList*)
    ```

    * **Concept**: Sorts the list with respect to **Burst Time** using **Insertion Sort** algorithm.
    * **Output**: Arranges the list in increasing order of **Burst Time**.
    * **Time Complexity**:
      * **Best Case**: `O(N)`
      * **Average Case**: `O(N^2)`
      * **Worst Case**: `O(N^2)`
    * **Space Complexity**:
      * **Input Space**: `O(1)`
      * **Auxilary Space**: `O(1)`
      * **Output Space**: `O(1)`
