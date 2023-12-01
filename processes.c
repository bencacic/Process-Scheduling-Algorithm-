/*
    Group members: Mohammed Cacic, Khanh Le, Ben Cacic
    Course: COMP 3659
    Assignment 2: Process Scheduling Algorithm Simulation 
    File Name: processes.c
    Purpose use: Store the information of the processes
*/
#include "processes.h"

//Process process[ARR_SIZE];


void initProcesses(Process process[]){
    int max = 50;
    int min = 1;
    int maxArrival = 30;
    int minArrival = 0;
    for (int i = 0; i < ARR_SIZE; ++i) {
        process[i].process_id = i + 100; // Assign some values as an example
        process[i].burst_time = (rand() % (max - min + 1)) + min; //max burst time 20 // 1000 - > 10000
        process[i].priority = (rand() % (12 - 0 + 1)) + 0; 
        process[i].arrival_time = (rand() % (maxArrival - minArrival + 1)) + minArrival; // between 30 to 0
        for (int j = 0; j < 4; j++) {
            process[i].prevBursts[j] = 0; // these values should be close to the cpu burst time
        }
    }
    return;
}

void readyQueue (Process process[], int choice) {

   // TimeIndex *temp_timeIndex;
    Process *newPointer;
  
    if (choice == 1) // sort by arrival time (FCFS)
    {
        // Call sorting function
        sort_FCFS (process);
    }
    else if (choice == 2) // shortest job first
    {
        sort_SJB(process);
    }
    else if (choice == 3) // shortest reaming time
    {
        /* code */
    }
    else if (choice == 4) // priority
    {
        /* code */
    } else if (choice == 5)
    {
    }
    
    return newPointer;
}
void sort_FCFS (Process process[]) {

    // for (int i = 0; i < ARR_SIZE; i++)
    // {
    //     process[i] = temp_queue[i];
    // }

    int numProcess = sizeof(process) / sizeof(process[0]);
    qsort(process, (size_t)ARR_SIZE, sizeof(process)/sizeof(process[0]), compareArrivalTime);
 
    return;
}

void sort_SJB (Process process[]) {
    int numProcess = sizeof(process) / sizeof(process[0]);
// Sort the array based on the 'arrival_time' field
    qsort(process, numProcess, sizeof(Process), compareAttributes);
}

void sort_PR(Process process[]) {
    
}

void sort_RR () {}


int compareArrivalTime(const void *a, const void *b)
{
    const Process *processA = (const Process *)a;
    const Process *processB = (const Process *)b;
    if (/* condition */)
    {
       return processA->arrival_time - processB->arrival_time;
    }
    
    return processA->arrival_time - processB->arrival_time;
}

int comparePriority (const void *a, const void *b) {
    const Process *processA = (const Process *)a;
    const Process *processB = (const Process *)b;
    return processA-> priority - processB-> priority;
}
int comparePriority (const void *a, const void *b) {
    const Process *processA = (const Process *)a;
    const Process *processB = (const Process *)b;
    return processA-> priority - processB-> priority;
}
int comparePriority (const void *a, const void *b) {
    const Process *processA = (const Process *)a;
    const Process *processB = (const Process *)b;
    return processA-> priority - processB-> priority;
}
         


