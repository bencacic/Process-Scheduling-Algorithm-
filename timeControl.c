#include "timeControl.h"

float CPU_utilization(int cpuTimeSum, int wallTimeSum) {
/*
    printf("%d",cpuTimeSum);
    printf("\n%d",wallTimeSum);
*/
    printf("cputTimeSum = %d", cpuTimeSum);
    printf(" and wallTimeSum = %d", wallTimeSum);
    float utilization = ((float)cpuTimeSum/CORES) / (float)wallTimeSum;
    //utilization = (float)utilization / CLOCKS_PER_SEC;
    //printf("\n%f",utilization * 100);
    return utilization * 100;
}

// int throughput(TimeIndex timeIndex[]) {
//     return 1;
// }

// int turnaround_time(TimeIndex timeIndex[]) {
//     return 1;
// }

//check total burst time
float totalBurstTime(int totalWaitTime) {
    float average = 0;
    // divide by 3600 to get per seconds
    average = ((float)totalWaitTime) / CLOCKS_PER_SEC; //this should be changed to waiting time
    return average;
}

// int response_time(TimeIndex timeIndex[]) {
//     return 1;
// }

// Retrieves sum of any desired value. PBR so that we only loop through one time.
void retrieve_time_totals(TimeIndex timeIndex[], int *total_CPU_time, int *total_wall_time, int *total_burst_time) {
    int cpuSum, burstSum, wallSum = 0;
    for(int i = 0; i < ARR_SIZE; i++) {
        cpuSum += timeIndex[i].cpuBurstTime;
        wallSum += timeIndex[i].wallTime;
        burstSum += (timeIndex[i].cpuBurstTime + timeIndex[i].ioBurstTime);
       //burstSum += timeIndex[i].ioBurstTime;
    }

    *total_CPU_time = cpuSum;
    *total_wall_time = wallSum;
    *total_burst_time = burstSum; // + waiting time
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
        timeIndex[index].totalBurstTime = 0;
        timeIndex[index].wallTime = 0;
    }
    return;
}
