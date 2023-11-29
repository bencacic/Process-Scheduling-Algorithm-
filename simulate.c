
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "processes.h"
#include "scheduling.h"
#include "timeControl.h"

const ARR_SIZE = 90;
const CORES = 1;

int main() {

//loop through all arrays of processes. Or have a seclection menu so that the user can pick which set of processes to initilize and which algorithm they want to test.
    runProcesses();

    return 0;
}


//This runs a single set of processes on one algorithm. As implement more algorithms, we can add to it so it.
void runProcesses() {        
    clock_t start_t, end_t;
    double total_t;

    Process process[ARR_SIZE];
    TimeIndex timeIndex[ARR_SIZE];

    initProcesses(process);
    initTimeIndex(timeIndex);

    start_t = clock();

    firstComeFirstServe(process, ARR_SIZE, timeIndex);

    // maybe long, idk how big these numbers are gonna be
    int total_CPU_time, total_wall_time, total_burst_time = 0;

    retrieve_time_totals(timeIndex, &total_CPU_time,  &total_wall_time, &total_burst_time);

    int CPU_util = CPU_Utilization(total_CPU_time, CORES, total_wall_time);

    //call print function here maybe
}

void print() {
    //handle all output, will get passed the calculated data. 

    //also handles storing this data in a txt file.
}