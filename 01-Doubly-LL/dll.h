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
};

#endif