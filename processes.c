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
    srand(time(0));
    for (int i = 0; i < ARR_SIZE; ++i) {
        process[i].process_id = i + 100; // Assign some values as an example
        process[i].burst_time = (rand() % (max - min + 1)) + min; //max burst time 50 // 
        process[i].priority = (rand() % (12 - 0 + 1)) + 0; 
        process[i].arrival_time = (rand() % (maxArrival - minArrival + 1)) + minArrival; // between 30 to 
        process[i].actualStart = -1;
        for (int j = 0; j < 4; j++) {
            process[i].prevBursts[j] =  (rand() % ( process[i].burst_time - min + 1)) + min; // these values should be close to the cpu burst time
        }
    }
    return;
}

// void initProcesses(Process process[]){
//     int max = 50;
//     int min = 1;
//     int maxArrival = 30;
//     int minArrival = 0;
//     for (int i = 0; i < ARR_SIZE; ++i) {
//         process[i].process_id = i; // Assign some values as an example
//         process[i].burst_time = i+5; //max burst time 50 // 
//         process[i].priority = (rand() % (12 - 0 + 1)) + 0; 
//         process[i].arrival_time = i + 2; // between 30 to 
//         for (int j = 0; j < 4; j++) {
//             process[i].prevBursts[j] =  (rand() % ( process[i].burst_time - min + 1)) + min; // these values should be close to the cpu burst time
//         }
//     }
//     return;
// }

void readyQueue (Process process[], int choice) {

   // TimeIndex *temp_timeIndex;
  
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
    else if (choice == 4) // round robin
    {
    } 
    else if (choice == 5)
    {
        sort_PR(process); // priority     
    }
    
    return;
}
void sort_FCFS (Process process[]) {

    // for (int i = 0; i < ARR_SIZE; i++)
    // {
    //     process[i] = temp_queue[i];
    // }
    //  printf("Before time 2 %d \n" , process[0].arrival_time);
    //      printf("Time time 2 %d \n" , process[1].arrival_time);

    //     printf("Time time 2 %d\n" , process[2].arrival_time);

    //      printf("Time time 2 %d\n" , process[3].arrival_time);
    //      printf("Time time 2 %d\n" , process[4].arrival_time);

    //      printf("Time time 2 %d\n" , process[5].arrival_time);
    //      printf("Time time 2 %d\n" , process[6].arrival_time);
     
    //     printf("Time time 2 %d\n" , process[7].arrival_time);
    //     printf("Time time 2 %d\n" , process[8].arrival_time);
    //     printf("Time time 2 %d\n" , process[9].arrival_time);
    qsort(process, (size_t)ARR_SIZE, sizeof(process[0]), compareArrivalTime);
    //  printf("After time 2 %d \n" , process[0].arrival_time);
    //      printf("Time time 2 %d \n" , process[1].arrival_time);

    //     printf("Time time 2 %d\n" , process[2].arrival_time);

    //      printf("Time time 2 %d\n" , process[3].arrival_time);
    //      printf("Time time 2 %d\n" , process[4].arrival_time);

    //      printf("Time time 2 %d\n" , process[5].arrival_time);
    //      printf("Time time 2 %d\n" , process[6].arrival_time);
     
    //     printf("Time time 2 %d\n" , process[7].arrival_time);
    //     printf("Time time 2 %d\n" , process[8].arrival_time);
    //     printf("Time time 2 %d\n" , process[9].arrival_time);
 
    return;
}

void sort_SJB (Process process[]) {
    int numProcess = sizeof(Process) / sizeof(process[0]);
// Sort the array based on the 'arrival_time' field
    qsort(process, (size_t)ARR_SIZE, sizeof(process[0]), compareSJF);
}

void sort_PR(Process process[]) {
    int numProcess = sizeof(Process) / sizeof(process[0]);
    //sort array based on the 'priority' field
    qsort(process, (size_t)ARR_SIZE, sizeof(process[0]), comparePriority);
}


int compareArrivalTime(const void *a, const void *b)
{
    const Process *processA = (const Process *)a;
    const Process *processB = (const Process *)b;
    return processA -> arrival_time - processB -> arrival_time;
}

int compareSJF(const void *a, const void *b) {
    const Process *processA = (const Process *)a;
    const Process *processB = (const Process *)b;

    for(int i = 0; i < 4; i++) {
        int exponAveA = processA-> prevBursts[i];
        int exponAveB = processB-> prevBursts[i];    
    }
    //return processA  - processB-> priority;

   return 0;
   }

int comparePriority (const void *a, const void *b) {
    const Process *processA = (const Process *)a;
    const Process *processB = (const Process *)b;
    return processA-> priority - processB-> priority;
}

         


