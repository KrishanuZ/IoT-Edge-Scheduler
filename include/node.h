#ifndef NODE_H
#define NODE_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdbool.h>

/*
Time Metrics:

at: Arrival Time
bt: Burst Time
ct: Completion Time
tat: TurnAround Time
wt: Waiting Time
*/
struct SensorTask {
    pid_t pid; // Process ID
    char taskName[32]; // Storing task's name, prevent mem leaks

    // Time Metrics:
    unsigned int at;    
    unsigned int bt;   
    unsigned int ct;    
    unsigned int tat;
    unsigned int wt;

    unsigned int rt; // rt: Rmaining time; Added for SRTF algo

    bool is_completed;
    
    struct SensorTask *prev;
    struct SensorTask *next;
};

// Core Functions:
struct SensorTask *createNode(pid_t, unsigned int, unsigned int);
struct SensorTask *destroyNode(struct SensorTask*);

#endif