/* Group Members: Mohammed Arab, Khanh Le, Ben Cacic
   Course: COMP 3659
   Assignment: Assignment 02
   Instructor: Marc Schroeder
   File Name: timeControl.c
 */
#include "timeControl.h"

/* Function name: CPU_utilization

   Inputs: int cpuTimeSum - Total CPU time for all processes.
           int wallTimeSum - Total time spent to complete all processes.
   Outputs: cpu utilization as a percentage.

   Description: This function serves to calculate the cpu utilization 
   for the given processes. Uses the formula: (Total CPU Time / # of cores )/
   total wall time.
*/
float CPU_utilization(int cpuTimeSum, int wallTimeSum) {
    float utilization = ((float)cpuTimeSum/CORES) / (float)wallTimeSum;
    return utilization * 100;
}

/* Function name: throughput

   Inputs: int wallTimeSum - Total time spent to complete all processes.
   Outputs: the mean amount that a process completes in one unit time.

   Description: This function takes the # of processes completed, and 
   divides them by the total time spent to completes all processes. Mean TP
   formula used is: # of processes / total time to complete processes.
*/
float throughPut(int wallTimeSum) {
    float throughput = (float)ARR_SIZE / (float)wallTimeSum;
    return throughput;
}

/* Function name: waitingTime

   Inputs: int waitTimeSum - Summed time all the processes wait.
   Outputs: Mean waiting time for the set of processes.

   Description: Calculates the mean waiting time for the processes.
   Mean WT formula: sum of waiting time / # of processes.
*/
float waitingTime(int waitTimeSum) {

    float waitingTime = ((float)waitTimeSum / (float)ARR_SIZE);
    return waitingTime;
}

/* Function name: turnaround_time

   Inputs: int burstSum - total CPU burst time
           int waitingTime - waiting time of all of the processes
   Outputs: Mean turnaround time for the completed processes.

   Description: Uses the formula: (Burst Time + Waiting Time) / Array size.
   Could also be accomplished with: (Completion Time – Arrival Time) / Array size.
*/
float turnaround_time(int burstSum, int waitingTime) {
    float turnaroundtime = (float)(burstSum + waitingTime)/(float)ARR_SIZE;
    return turnaroundtime;
}

/* Function name: response_time

   Inputs: int beforeFirstExe - Sum of the initial waiting time for 
        the processes.
   Outputs: the mean response time for the set of processes.
   
   Description: This function serves to calculate the mean response 
   time for the processes. Formula used for Mean RT is: (sum of time the processes were
   first started - when it entered the ready queue) / # of processes. 
   Response time is the Duration between entering the ready queue and 
   getting its first execution by the CPU.
*/
float response_time(int beforeFirstExe) {
    float responseTime = ((float)beforeFirstExe / (float)ARR_SIZE);
    return responseTime;
    }

/* Function name: retrieve_time_totals

   Inputs: TimeIndex timeIndex[] - Array of time data 
           int *total_burst_time - Pointer to an int that holds the total burst time
           int *process_start_time - Pointer to an int that holds the process start time
           int *total_wait_time - Pointer to an int that holds the total wait time

   Description: Loops through the array of the time data for the processes.
   It records the total_burst_time, process_start_time, and total_wait_time (passes them back by reference) 
   because these will be used in CPU scheduling criteria calulations. 
*/
void retrieve_time_totals(TimeIndex timeIndex[], int *total_burst_time, int *beforeFirstExe, int *total_wait_time) {
    int burstSum = 0, 
        processStart = 0, 
        waitSum = 0, 
        turnaroundTimeSum = 0;

    for(int i = 0; i < ARR_SIZE; i++) {
        burstSum += timeIndex[i].burstTime;
        processStart += timeIndex[i].initWaitingTime;
        waitSum = waitSum + timeIndex[i].waitingTime;
    }

    *total_burst_time = burstSum; 
    *beforeFirstExe = processStart;
    *total_wait_time = waitSum;

    return;
}

/* Function name: initTimeIndex

   Inputs: TimeIndex timeIndex[], Process process[]

   Description: Initiates the time index array. Requires the array of processes
   because it requires the process ID.
*/
void initTimeIndex(TimeIndex timeIndex[], Process process[])
{
    for (int index = 0; index < ARR_SIZE; index++)
    {
        timeIndex[index].pid = process[index].process_id;
        timeIndex[index].burstTime = -1;
        timeIndex[index].startTime = -1;
        timeIndex[index].waitingTime = -1;
        timeIndex[index].initWaitingTime = -1;
    }
    return;
}
