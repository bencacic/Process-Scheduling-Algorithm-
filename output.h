#ifndef OUTPUT_H
#define OUTPUT_H

#include "mylib.h"
#include "processes.h"

#define BOLD  "\x1B[1m"
#define RESET "\x1B[0m"
#define CYN   "\x1B[36m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define WHT   "\x1B[37m"

static void preSetUp (Process process[], float scaleARR[]);
static int sumOfBurstTime(Process process[]);
void makeGantChart(Process process[]);
void printData(FILE *filePtr, int choice, float cpuUtilization, float burstTime, float throughput, 
               float MeanTurnaroundTime, float meanWaitTime, float meanResponseTime);

#endif