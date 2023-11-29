/*
    Group members: Mohammed Cacic, Khanh Le, Ben Cacic
    Course: COMP 3659
    Assignment 2: Process Scheduling Algorithm Simulation 
    File Name: scheduling.c
    Purpose use: Store scheduling algorithms
*/
#include "scheduling.h"

//initialize process aray
//startr clock to nanosec
//call algortihm funciton
//end clock 
// calculations in testing module
//print data

//
// 

void firstComeFirstServe(Process process[], TimeIndex timeIndex[]) {
    clock_t cpuStartTime = 0, 
            cpuEndTime = 0, 
            ioStartTime = 0, 
            ioEndTime = 0, 
            waitTime = 0;
    TimeIndex *temp_timeIndex;

 //printf("this Should be 0 first time %d", timeIndex[2].cpuBurstTime);
for(int i = 0; i < ARR_SIZE; i++ ) {
    int processCputBurst = process[i].cpu_burst_time;
    int processIBurst = process[i].io_burst_time;
    cpuStartTime = clock();
    while (processCputBurst > 0)
    {
         processCputBurst--;
    }
    cpuEndTime = clock();
    ioEndTime = cpuEndTime;
        temp_timeIndex = &timeIndex[i];
        temp_timeIndex -> cpuBurstTime = cpuEndTime - cpuStartTime;
     //timeIndex[i].cpuBurstTime = cpuEndTime - cpuStartTime;
    
    if(processIBurst != 0){
    ioStartTime = clock();
    while (processIBurst > 0)
    {
        processIBurst--;
    }
    ioEndTime = clock();
    }
    temp_timeIndex -> ioBurstTime = ioEndTime - ioEndTime;
    temp_timeIndex -> totalBurstTime = ioEndTime - cpuStartTime;  

    temp_timeIndex -> wallTime = ioEndTime - cpuStartTime;
   
     //timeIndex[i].ioBurstTime = ioEndTime - ioEndTime;
     //timeIndex[i].totalBurstTime = ioEndTime - cpuStartTime;          
    }

     //printf("this Sould == to one above %d", timeIndex[2].cpuBurstTime);
   
}

// void firstComeFirstServe(Process process[], TimeIndex timeIndex[]) {
    
//     int i = 0;
//     // CPU start time per process
//     clock_t cpuStart = 0, 
//             cpuEnd = 0, 
//             cpuTime = 0,
//             ioStart = 0,
//             ioEnd = 0,
//             ioTime = 0;
    
//     while (process[i].cpu_burst_time > 0  && i < ARR_SIZE)
//     {
//         cpuStart = clock();
//         process[i].cpu_burst_time--;
//         if (process[i].cpu_burst_time == 0)
//         {
    
//             cpuEnd = clock();
//             cpuTime = cpuEnd - cpuStart;
//             //stop cput time
//             while (process[i].io_burst_time > 0)
//              {
//                 ioStart = clock();
//                 process[i].io_burst_time--;
//              }

//             ioEnd = clock();
//             ioTime = ioEnd - ioStart;
//             //timeIndex[i].processId = process[i].processId;
//             //timeIndex[i].cpuBurstTime = cpuTime;
//             //timeIndex[i].ioBurst_time = ioTime;
//             i++;
//         }
//     }
 
// }


void shortestJobFirst(Process process[]) {

}

void shortestRemainingTimeFirst(Process process[]) {

}

void roundRobin(Process process[]) {

}

void priorityScheduling(Process process[]) {

}
