#ifndef TIMECONTROL_H
#define TIMECONTROL_H

#include "mylib.h"
#include "processes.h"

typedef struct {
    int pid;
    int startTime;
    int waitingTime;
    int burstTime;
    
} TimeIndex;

float CPU_utilization(int cpuTimeSum, int wallTimeSum);

// int throughput();
float response_time(int totalWaitTime);

float throughPut(int wallTimeSum);

float waitingTime(int waitTimeSum);

float turnaround_time(int burstSum, int waitingTime);

// float totalBurstTime(int totalWaitTime);

// int response_time();
// void retrieve_time_totals(TimeIndex timeIndex[], int *total_burst_time, int *process_start_time, int *total_wait_time, 
//     int *total_response_time);
void retrieve_time_totals(TimeIndex timeIndex[], int *total_burst_time, int *process_start_time, int *total_wait_time);
//void initTimeIndex (TimeIndex timeIndex[], int *total_CPU_time, int *total_wall_time, int *total_burst_time, int *Mean_Turnaround_Time);

void initTimeIndex(TimeIndex timeIndex[], Process process[]);
#endif