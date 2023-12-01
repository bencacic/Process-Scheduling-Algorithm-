#include "timeControl.h"

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
    return utilization * 100;
}

float throughPut(int wallTimeSum) {
    float throughput = (float)ARR_SIZE / (float)wallTimeSum;
    return throughput;
}

float waitingTime(int waitTimeSum) {

    float waitingTime = ((float)waitTimeSum / (float)ARR_SIZE) / CLOCKS_PER_SEC;
    return waitingTime;
}

float turnaround_time(int process_start_time, int wallTimeSum) {
    float turnaroundtime = (float)(wallTimeSum - process_start_time)/(float)ARR_SIZE;
    return turnaroundtime;
}

//check total burst time
float totalBurstTime(int totalWaitTime) {
    float average = 0;
    // divide by 3600 to get per seconds
    average = ((float)totalWaitTime) / CLOCKS_PER_SEC; //this should be changed to waiting time
    return average;
}

float response_time(int totalWaitTime) {
 float responseTime = ((float)totalWaitTime / (float)ARR_SIZE) / CLOCKS_PER_SEC;
    return responseTime;
    }

// Retrieves sum of any desired value. PBR so that we only loop through one time.
void retrieve_time_totals(TimeIndex timeIndex[], int *total_CPU_time, int *total_wall_time, int *total_burst_time, int *process_start_time, int *total_wait_time,
    int *total_response_time) {
    int cpuSum, burstSum, wallSum, processStart, waitSum = 0;
    for(int i = 0; i < ARR_SIZE; i++) {
        wallSum += timeIndex[i].wallTime;
        burstSum += timeIndex[i].burstTime;
        processStart += timeIndex[i].startTime;
        waitSum += timeIndex[i].waitingTime;
    }

    *total_CPU_time = cpuSum;
    *total_wall_time = wallSum;
    *total_burst_time = burstSum; // + waiting time
    *process_start_time = processStart;
    *total_wait_time = waitSum;
    *total_response_time = waitSum;
    return;
}
void initTimeIndex(TimeIndex timeIndex[])
{
    for (int index = 0; index < ARR_SIZE; index++)
    {
        timeIndex[index].burstTime = -1;
        timeIndex[index].startTime = -1;
       // timeIndex[index].timeFirstStarted = 0;
        timeIndex[index].waitingTime = -1;
       // timeIndex[index].totalBurstTime = 0;
      //  timeIndex[index].wallTime = 0;

    }
    return;
}
