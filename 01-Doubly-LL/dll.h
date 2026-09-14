#ifndef DLL_H
#define DLL_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

/*
Time Metrics:

at: Arrival Time
bt: Burst Time
ct: Completion Time
tat: TurnAround Time
wt: Waiting Time
*/
struct ProcessNode {
    pid_t pid; // Process ID

    // Time Metrics:
    unsigned int at;    
    unsigned int bt;   
    unsigned int ct;    
    unsigned int tat;
    unsigned int wt;

    unsigned int rt; // rt: Rmaining time; Added for SRTF algo

    struct ProcessNode *prev;
    struct ProcessNode *next;
};

struct DoublyLinkedList {
    struct ProcessNode *head;
    struct ProcessNode *tail;

    size_t length; // To track the length of the DLL
};


// Function prototypes:

// Core Functions:

struct ProcessNode *createNode(pid_t, unsigned int, unsigned int);
struct ProcessNode *deleteNode(struct ProcessNode*);

#endif