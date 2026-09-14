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
    pid_t pid; 
    int at;    
    int bt;   
    int ct;    
    int tat;
    int wt;
};

#endif