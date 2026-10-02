#include <stdlib.h>
#include <string.h>
#include "task.h"

struct SensorTask *createTask(pid_t tid, const char *taskName, unsigned int at, unsigned int bt) {
    struct SensorTask *newTask = (struct SensorTask *)malloc(sizeof(struct SensorTask));

    if (!newTask) {
        return NULL;
    }

    // TaskName
    strncpy(newTask->taskName, taskName, 31); // Max of 31 charaxcters, since last character = \0
    newTask->taskName[31] = '\0'; // Add null char for termination

    // Assign links to NULL
    newTask->prev = NULL;
    newTask->next = NULL;

    newTask->tid = tid;
    newTask->at = at;
    newTask->bt = bt;
    newTask->rt = newTask->bt; // Since the execution hasn't started yet

    // Assign 0 to avoid generating garbage values
    newTask->ct = 0;
    newTask->tat=0;
    newTask->wt=0;

    newTask->is_completed = false;

    return newTask;
}

struct SensorTask *destroyTask(struct SensorTask *task) {

    // Explicitly clear out the links
    task->prev = NULL;
    task->next = NULL;
    
    free(task);
    return NULL; // Explicitly return NULL to avoid a dangling pointer
}