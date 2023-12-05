/* Group Members: Mohammed Arab, Khanh Le, Ben Cacic
   Course: COMP 3659
   Assignment: Assignment 02
   Instructor: Marc Schroeder
   File Name: timeControl.c
 */
#include "timeControl.h"

// Time spent executing a burst 
float CPU_utilization(int cpuTimeSum, int wallTimeSum) {
/*
    printf("%d",cpuTimeSum);
    printf("\n%d",wallTimeSum);
*/
   // printf("cputTimeSum = %d", cpuTimeSum);
   // printf(" and wallTimeSum = %d", wallTimeSum);
    float utilization = ((float)cpuTimeSum/CORES) / (float)wallTimeSum;
    //utilization = (float)utilization / CLOCKS_PER_SEC;
    //printf("\n%f",utilization * 100);
    return utilization * 100; //to get as a percentage
}

// Number of processes completed per unit time
float throughPut(int wallTimeSum) {
    float throughput = (float)ARR_SIZE / (float)wallTimeSum;
    return throughput;
}

// Total time a process spends in the ready queue. Should be same as response time 
// as we have no IO bursts implemented
float waitingTime(int waitTimeSum) {

    float waitingTime = ((float)waitTimeSum / (float)ARR_SIZE);
    return waitingTime;
}

// Time a process spends being executed and in waiting
/*
The turnaround time formula is as follows:

Turnaround Time = Completion Time – Arrival Time

Alternatively, it is also calculated as follows:

TAT = Burst Time + Waiting Time
*/
float turnaround_time(int burstSum, int waitingTime) {
    float turnaroundtime = (float)(burstSum + waitingTime)/(float)ARR_SIZE;
    return turnaroundtime;
}

// Duration between entering the ready queue and getting its first execution by the CPU
float response_time(int totalWaitTime) {
 float responseTime = ((float)totalWaitTime / (float)ARR_SIZE);
    return responseTime;
    }

// Retrieves sum of any desired value. PBR so that we only loop through one time.
void retrieve_time_totals(TimeIndex timeIndex[], int *total_burst_time, int *process_start_time, int *total_wait_time) {
    int burstSum = 0, 
        processStart = 0, 
        waitSum = 0, 
        turnaroundTimeSum = 0;

    for(int i = 0; i < ARR_SIZE; i++) {
        burstSum += timeIndex[i].burstTime;
        processStart += timeIndex[i].startTime;
        waitSum = waitSum + timeIndex[i].waitingTime;
    }

 // dont need this here anymore. Can leave it for now though.
    *total_burst_time = burstSum; 
    *process_start_time = processStart;
    *total_wait_time = waitSum;
   // printf("\nsss %d\n", waitSum);
   // *total_response_time = waitSum;
    return;
}
void initTimeIndex(TimeIndex timeIndex[], Process process[])
{
    for (int index = 0; index < ARR_SIZE; index++)
    {
        timeIndex[index].pid = process[index].process_id;
        timeIndex[index].burstTime = -1;
        timeIndex[index].startTime = -1;
        // timeIndex[index].estimatedBurstTime = -1;
 // per process start time
       // timeIndex[index].timeFirstStarted = 0;
        timeIndex[index].waitingTime = -1;
       // timeIndex[index].totalBurstTime = 0;
      //  timeIndex[index].wallTime = 0;

    }
    return;
}
