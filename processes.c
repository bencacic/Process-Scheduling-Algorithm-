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
    int max = 10000;
    int maxIO = 20000;
    int min = 1;
    for (int i = 0; i < ARR_SIZE; ++i) {
        process[i].process_id = i * 10; // Assign some values as an example
        process[i].cpu_burst_time = (rand() % (max - min + 1)) + min; //max burst time 20
        process[i].io_burst_time = (rand() % (maxIO - min + 1)) + min;
        process[i].arrival_time = 0;
        process[i].priority = 0 ; 
        process[i].remaining_time = 0;   
        for (int j = 0; j < 4; j++) {
            process[i].prevBursts[j] = 0; // these values should be close to the cpu burst time
        }
    }
    return;
}
