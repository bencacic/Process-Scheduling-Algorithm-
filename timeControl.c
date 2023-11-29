#include "timeControl.h"

int CPU_utilization(int cpuTimeSum, const int nCores, int wallTimeSum) {
    int time = cpuTimeSum / nCores / wallTimeSum;
    return time;
}

int throughput(TimeIndex timeIndex[]) {
    return 1;
}

int turnaround_time(TimeIndex timeIndex[]) {
    return 1;
}

int waiting_time(TimeIndex timeIndex[]) {
    return 1;
}

int response_time(TimeIndex timeIndex[]) {
    return 1;
}

// Retrieves sum of any desired value. PBR so that we only loop through one time.
void retrieve_time_totals(TimeIndex timeIndex[], int *total_CPU_time, int *total_wall_time, int *total_burst_time) {

    int cpuSum, burstSum, wallSum = 0;
    for(int i = 0; i < ARR_SIZE; i++) {
        cpuSum =+ timeIndex[i].cpuBurstTime;
       // wallSum =+ timeIndex[i].wallTime;
       burstSum =+ timeIndex[i].cpuBurstTime;
       burstSum =+ timeIndex[i].ioBurstTime;
    }

    *total_CPU_time = cpuSum;
    *total_wall_time = wallSum;
    *total_burst_time = burstSum;
    return;
}
