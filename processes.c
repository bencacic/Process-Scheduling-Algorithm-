/*
    Group members: Mohammed Cacic, Khanh Le, Ben Cacic
    Course: COMP 3659
    Assignment 2: Process Scheduling Algorithm Simulation 
    File Name: processes.c
    Purpose use: Store the information of the processes
*/

const ARR_SIZE = 10;
#include "processes.h"


//Process process[ARR_SIZE];

void initPorcesses(Process process[]){
    int max = 20;
    int maxIO = 80;
    int min = 1;
for (int i = 0; i < ARR_SIZE; ++i) {
        process[i].process_id = i * 10; // Assign some values as an example
        process[i].cpu_burst_time = (rand() % (max - min + 1)) + min; //max burst time 20
        process[i].io_burst_time = (rand() % (maxIO - min + 1)) + min;
        process[i].arrival_time = 0;
        process[i].priority ; 
        process[i].remaining_time;   
    }
    return;
}
void initTimeIndex(TimeIndex timeIndex[])
{
    for (int index = 0; index < ARR_SIZE; index++)
    {
        timeIndex[index].ioBurstTime = 0;
        timeIndex[index].cpuBurstTime = 0;
        timeIndex[index].startTime = 0;
        timeIndex[index].timeFirstStarted = 0;
        timeIndex[index].waitingTime = 0;
    }
    return;
}