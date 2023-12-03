#ifndef OUTPUT_H
#define OUTPUT_H

#include "mylib.h"

#define BOLD  "\x1B[1m"
#define RESET "\x1B[0m"
#define CYN   "\x1B[36m"

static void preSetUp (Process process[], float scaleARR[]);
static int sumOfBurstTime(Process process[]);
void makeGantChart(Process process[], float scale[]);

#endif