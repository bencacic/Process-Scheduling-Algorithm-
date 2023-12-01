/*
    Group members: Mohammed Cacic, Khanh Le, Ben Cacic
    Course: COMP 3659
    Assignment 2: Process Scheduling Algorithm Simulation 
    File Name: processes.h
    Purpose use: Store the information of the processes
*/
#ifndef PROCESSES_H
#define PROCESSES_H

#include "mylib.h"

typedef struct {
    int process_id;
    int arrival_time;
    int burst_time;
    int priority;  
    int prevBursts[4];
} Process;

void initProcesses(Process process[]);

int compareArrivalTime(const void *a, const void *b);
int compareShortestTime (const void *a, const void *b);
int comparePriority (const void *a, const void *b);
         
void readyQueue (Process process[], int choice);


#endif