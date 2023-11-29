#ifndef TIME_C
#define TIME_C

#include "processes.h"
#include "scheduling.h"

int CPU_utilization(int cpuTimeSum, const int nCores, int wallTimeSum);

int throughput();

int turnaround_time();

int waiting_time();

int response_time();

void retrieve_time_totals(TimeIndex timeIndex[], int *total_CPU_time, int *total_wall_time, int *total_burst_time);

#endif