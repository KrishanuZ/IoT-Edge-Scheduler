#ifndef DLL_H
#define DLL_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
struct ProcessNode {
    pid_t pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};

#endif