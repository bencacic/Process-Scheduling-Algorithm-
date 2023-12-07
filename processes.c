/*
    Group members: Mohammed Arab, Khanh Le, Ben Cacic
    Course: COMP 3659
    Assignment 2: Process Scheduling Algorithm Simulation 
    File Name: processes.c
    Purpose use: Store the information of the processes, 
    and handle them.
*/
#include "processes.h"

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
void initProcesses(Process process[]){
    int max = 50;
    int min = 1;
    int maxArrival = 30;
    int minArrival = 0;
    srand(time(0));
    for (int i = 0; i < ARR_SIZE; ++i) {
        process[i].process_id = i;
        process[i].burst_time = (rand() % (max - min + 1)) + min; //max burst time 50 // 
        process[i].priority = (rand() % (10 - 0 + 1)) + 0; 
        process[i].arrival_time = (rand() % (maxArrival - minArrival + 1)) + minArrival;
        process[i].actualStart = -1;
        process[i].completed = 0; //changed this when working on RR if there is any errors it might be it
        process[i].started = 1;  //means procees has started 
        process[i].numberOfBursts = 0;
        process[i].estimatedBurstTime = -1;
        for (int j = 0; j < 4; j++) {
            process[i].prevBursts[j] = ((rand() % 11) + (process[i].burst_time - 5)) < 1 ? 1 : (rand() % 11) + (process[i].burst_time - 5);
        }
    }
    return;
}

/* Function name: readyQueue

   Inputs: Process process[] - Array of processes.
           int choice - which scheduling algorithm 
            was selected by the user.
 
   Description: Sorts the unsorted array of processes
        by arrival time, and calculates the estimated 
        burst time. This simulates the ready queue as the
        algorithm would see it.
*/
void readyQueue (Process process[], int choice) {

    if (choice == 1) // sort by arrival time (FCFS)
    {
        // Call sorting function
        sort_FCFS (process);
    }
    else if (choice == 2) // shortest job first
    {
        estimateBurstTime(process);
        sort_FCFS (process);
        //sort_SJB(process);
    }
    else if (choice == 3) // shortest reaming time
    {
        estimateBurstTime(process);
        sort_FCFS (process);
    }
    else if (choice == 4) // round robin
    {

        sort_FCFS (process); // let here temporarily
    } 
    else if (choice == 5)
    {
        sort_FCFS(process); // priority     
    }
    
    return;
}

/* Function name: sort_FCFS 

   Inputs: Process process[] - Array of processes.
 
   Description: calls qsort to sort the processes by 
        arrival time.
*/
void sort_FCFS (Process process[]) {
    qsort(process, (size_t)ARR_SIZE, sizeof(process[0]), compareArrivalTime);
}

/* Function name: sort_SJB 

   Inputs: Process process[] - Array of processes.
 
   Description: calls qsort to sort the processes by 
        estimated burst time.
*/
void sort_SJB (Process process[]) {
    qsort(process, (size_t)ARR_SIZE, sizeof(process[0]), compareSJF);
}

/* Function name: sort_PR 

   Inputs: Process process[] - Array of processes.
 
   Description: calls qsort to sort the processes by 
        priority level.
*/
void sort_PR(Process process[]) {
    qsort(process, (size_t)ARR_SIZE, sizeof(process[0]), comparePriority);
}

/* Function name: compareArrivalTime

   Inputs: const void *a - A process from the process array.
           const void *b - Another process from the process array.
   Outputs: an int that can be used by qsort to determine which 
            element is larger based on whether its positive/negative/
            zero.
   Description: 
*/
int compareArrivalTime(const void *a, const void *b)
{
    const Process *processA = (const Process *)a;
    const Process *processB = (const Process *)b;
    return processA -> arrival_time - processB -> arrival_time;
}

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
int compareSJF(const void *a, const void *b) {
    const Process *processA = (const Process *)a;
    const Process *processB = (const Process *)b;

    float diff = processA->estimatedBurstTime - processB->estimatedBurstTime;

    // Use a small epsilon value to handle precision issues
    if (fabs(diff) < 0.0001) {
        return 0;  // Consider them equal
    } else if (diff < 0) {
        return -1;
    } else {
        return 1;
    }         
}

/* Function name: comparePriority

   Inputs: const void *a - A process from the process array.
           const void *b - Another process from the process array.
   Outputs: an int that can be used by qsort to determine which 
            element is larger based on whether its positive/negative/
            zero.
   Description: Compare the two processes based on which one has a lower
            priority value (higher priority)
*/
int comparePriority (const void *a, const void *b) {
    const Process *processA = (const Process *)a;
    const Process *processB = (const Process *)b;
    return processA-> priority - processB-> priority;
}

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
void estimateBurstTime(Process process[]) {

    float alpha = 0.5;

    for(int i = 0; i < ARR_SIZE; i++){
        float current_value = process[i].prevBursts[0] * alpha;
        for (int j = 1; j < 4; j++) {
            current_value = alpha * process[i].prevBursts[j] * (1 - alpha) + current_value;
        }
    process[i].estimatedBurstTime = current_value;
    }

    return;
}         