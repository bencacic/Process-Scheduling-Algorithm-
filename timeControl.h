#ifndef TIMECONTROL_H
#define TIMECONTROL_H

#include "mylib.h"

typedef struct {
    int startTime;
    int waitingTime;
    int cpuBurstTime;
    int ioBurstTime;
    int timeFirstStarted ;
    int totalBurstTime;
    int wallTime;
} TimeIndex;

float CPU_utilization(int cpuTimeSum, int wallTimeSum);

// int throughput();

// int turnaround_time();

float totalBurstTime(int totalWaitTime);

// int response_time();

void retrieve_time_totals(TimeIndex timeIndex[], int *total_CPU_time, int *total_wall_time, int *total_burst_time);

void initTimeIndex(TimeIndex timeIndex[]);
#endif