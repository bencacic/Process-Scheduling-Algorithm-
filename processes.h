/*
    Group members: Mohammed Arab, Khanh Le, Ben Cacic
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
    int started;
    int numberOfBursts;
    int prevBursts[4];
} Process;

/*  Function name: initProcesses

    Inputs: Process process[] - Array of processes.
                                     
    Description: initializes each element in the
    array of processes with the following:
        int process_id;
        int arrival_time;
        int burst_time;
        int priority;  
        int actualStart;
        float estimatedBurstTime;
        int completed;
        int started;
        int numberOfBursts;
        int prevBursts[4];
*/
void initProcesses(Process process[]);

/* Function name: compareArrivalTime

   Inputs: const void *a - A process from the process array.
           const void *b - Another process from the process array.
   Outputs: an int that can be used by qsort to determine which 
            element is larger based on whether its positive/negative/
            zero.
   Description: 
*/
int compareArrivalTime(const void *a, const void *b);

/* Function name: compareSJF

   Inputs: const void *a - A process from the process array.
           const void *b - Another process from the process array.
   Outputs: an int that can be used by qsort to determine which 
            element is larger based on whether its positive/negative/
            zero.
   Description: Compare the two processes based on which one has a lower
            expected burst time. Used by Shorst remaining time first 
            and shortest job first algorithms.
*/
int compareSJF(const void *a, const void *b);

/* Function name: comparePriority

   Inputs: const void *a - A process from the process array.
           const void *b - Another process from the process array.
   Outputs: an int that can be used by qsort to determine which 
            element is larger based on whether its positive/negative/
            zero.
   Description: Compare the two processes based on which one has a lower
            priority value (higher priority)
*/
int comparePriority (const void *a, const void *b);

/* Function name: readyQueue

   Inputs: Process process[] - Array of processes.
           int choice - which scheduling algorithm 
            was selected by the user.
 
   Description: Sorts the unsorted array of processes
        by arrival time, and calculates the estimated 
        burst time. This simulates the ready queue as the
        algorithm would see it.
*/
void readyQueue (Process process[], int choice);

/* Function name: sort_FCFS 

   Inputs: Process process[] - Array of processes.
 
   Description: calls qsort to sort the processes by 
        arrival time.
*/
void sort_FCFS (Process process[]);

/* Function name: sort_PR 

   Inputs: Process process[] - Array of processes.
 
   Description: calls qsort to sort the processes by 
        priority level.
*/
void sort_PR(Process process[]);

/* Function name: sort_SJB 

   Inputs: Process process[] - Array of processes.
 
   Description: calls qsort to sort the processes by 
        estimated burst time.
*/
void sort_SJB (Process process[]);

/* Function name: estimateBurstTime

   Inputs: Process process[] - Array of processes.
 
   Description: Each process in the array contains its
        an array of past burst times that will be within
        5 time units of the randomized actual burst time.
        Using exponential averaging, the length of the next
        burst is estimated. It is then used in SJF and SRTF 
        algorithms to make decisions on which process to 
        serve next. 
*/
void estimateBurstTime(Process process[]);

#endif