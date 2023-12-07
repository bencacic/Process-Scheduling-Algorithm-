/* Group Members: Mohammed Arab, Khanh Le, Ben Cacic
   Course: COMP 3659
   Assignment: Assignment 02
   Instructor: Marc Schroeder
   File Name: timeControl.h
 */
#ifndef TIMECONTROL_H
#define TIMECONTROL_H

#include "mylib.h"
#include "processes.h"

typedef struct {
    int pid;
    int startTime;
    int waitingTime;
    int burstTime;
    int initWaitingTime;
} TimeIndex;

/* Function name: CPU_utilization

   Inputs: int cpuTimeSum - Total CPU time for all processes.
           int wallTimeSum - Total time spent to complete all processes.
   Outputs: cpu utilization as a percentage.

   Description: This function serves to calculate the cpu utilization 
   for the given processes. Uses the formula: (Total CPU Time / # of cores )/
   total wall time.
*/
float CPU_utilization(int cpuTimeSum, int wallTimeSum);

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
float response_time(int beforeFirstExe);

/* Function name: throughput

   Inputs: int wallTimeSum - Total time spent to complete all processes.
   Outputs: the mean amount that a process completes in one unit time.

   Description: This function takes the # of processes completed, and 
   divides them by the total time spent to completes all processes. Mean TP
   formula used is: # of processes / total time to complete processes.
*/
float throughPut(int wallTimeSum);

/* Function name: waitingTime

   Inputs: int waitTimeSum - Summed time all the processes wait.
   Outputs: Mean waiting time for the set of processes.

   Description: Calculates the mean waiting time for the processes.
   Mean WT formula: sum of waiting time / # of processes.
*/
float waitingTime(int waitTimeSum);

/* Function name: turnaround_time

   Inputs: int burstSum - total CPU burst time
           int waitingTime - waiting time of all of the processes
   Outputs: Mean turnaround time for the completed processes.

   Description: Uses the formula: (Burst Time + Waiting Time) / Array size.
   Could also be accomplished with: (Completion Time – Arrival Time) / Array size.
*/
float turnaround_time(int burstSum, int waitingTime);

/* Function name: retrieve_time_totals

   Inputs: TimeIndex timeIndex[] - Array of time data 
           int *total_burst_time - Pointer to an int that holds the total burst time
           int *process_start_time - Pointer to an int that holds the process start time
           int *total_wait_time - Pointer to an int that holds the total wait time

   Description: Loops through the array of the time data for the processes.
   It records the total_burst_time, process_start_time, and total_wait_time (passes them back by reference) 
   because these will be used in CPU scheduling criteria calulations. 
*/
void retrieve_time_totals(TimeIndex timeIndex[], int *total_burst_time, int *beforeFirstExe, int *total_wait_time);

/* Function name: initTimeIndex

   Inputs: TimeIndex timeIndex[], Process process[]

   Description: Initiates the time index array. Requires the array of processes
   because it requires the process ID.
*/
void initTimeIndex(TimeIndex timeIndex[], Process process[]);
#endif