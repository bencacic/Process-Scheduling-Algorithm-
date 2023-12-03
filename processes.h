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
    int actualStart;
    float estimatedBurstTime;
    int completed;
    int prevBursts[4];
} Process;

void initProcesses(Process process[]);

int compareArrivalTime(const void *a, const void *b);
int compareSJF(const void *a, const void *b);
int comparePriority (const void *a, const void *b);
void readyQueue (Process process[], int choice) ;
void sort_FCFS (Process process[]);
void sort_RR ();
void sort_PR(Process process[]);
void sort_SJB (Process process[]);
void estimateBurstTime(Process process[]);
void emptyQueue(Process process[]);



#endif