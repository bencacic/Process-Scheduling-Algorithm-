/*
    Group members: Mohammed Cacic, Khanh Le, Ben Cacic
    Course: COMP 3659
    Assignment 2: Process Scheduling Algorithm Simulation 
    File Name: scheduling.h
    Purpose use: Store scheduling algorithms
*/
#ifndef SCHEDULING_H
#define SCHEDULING_H

#include "mylib.h"
#include "processes.h"
#include "timeControl.h"

/*  Function name: firstComeFirstServe
    Inputs: Process process[] - Array of processes
            TimeIndex timeIndex[] - Array of statistic time of each 
                                    process 
    Output: int - the wall time
    Description: The function performs the first-come-first-serve
    scheduling algorithms on the processes.
*/
int firstComeFirstServe(Process procecess[], TimeIndex timeIndex[]);

/*  Function name: shortestJobFirst
    Inputs: Process process[] - Array of processes
            TimeIndex timeIndex[] - Array of statistic time of each 
                                    process 
    Output: int - the wall time
    Description: The function performs the shortest job first
    scheduling algorithms on the processes.
*/
int shortestJobFirst(Process process[], TimeIndex timeIndex[]);   

/*  Function name: shortestRemainingTimeFirst
    Inputs: Process process[] - Array of processes
            TimeIndex timeIndex[] - Array of statistic time of each 
                                    process 
    Output: int - the wall time
    Description: The function performs the shortest remaining time 
    first scheduling algorithms on the processes.
*/
int shortestRemainingTimeFirst(Process process[], TimeIndex timeIndex[]);

/*  Function name: roundRobin
    Inputs: Process process[] - Array of processes
            TimeIndex timeIndex[] - Array of statistic time of each 
                                    process 
    Output: int - the wall time
    Description: The function performs the Round Robin 
    scheduling algorithms on the processes.
*/
int roundRobin(Process process[], TimeIndex timeIndex[]);

/*  Function name: priorityScheduling
    Inputs: Process process[] - Array of processes
            TimeIndex timeIndex[] - Array of statistic time of each 
                                    process 
    Output: int - the wall time
    Description: The function performs the priority
    scheduling algorithms on the processes.
*/
int priorityScheduling(Process process[], TimeIndex timeIndex[]);

/*  Function name: sortQueue
    Inputs: Process process[] - Array of processes
            Process temp[] - Copy of process array.
    Output: None
    Description: This function sorts processes based on their estimated burst times, and executes 
            them in that order.
*/
void sortQueue(Process process[], Process temp[]);

/*  Function name: sortSRTF
    Inputs: Process process[] - Array of processes.
            Process temp[] - Copy of process array.
                by estimated burst time.
    Output: None
    Description: Selects the process with the shortest remaining burst time.
*/
void sortSRTF(Process process[], Process temp[]);

/*  Function name: sortPriority
    Inputs: Process process[] - Array of processes.
            Process temp[] - Copy of process array.
    Output: None
    Description: Selects the process with the lowest priority value.
*/
void sortPriority(Process process[], Process temp[]);

/*  Function name: findShortest
    Inputs: Process temp[] - Array of processes
            int time - uses current time to manage
            which processes are ready and not completed. 
    Output: shortest index - returns the index of the process with the 
            lowest remaining time.
    Description: Checks which processes are currently available to run, and out 
            of the processes that are, returns the index of the process with the 
            shortest remaining run time.
*/
int findShortest(Process temp[], int time);

/*  Function name: runBurst
    Inputs: Process process[] - Array of processes
            TimeIndex timeIndex[] - Array of statistic time of each 
                                    process 
            int time - the clock time of the process
    Output: the total time time it has taken to run the processes.
    Description: The function runs the processes. Used in non pre-emptive
            scheduling algorithms to reduce duplicate code.
*/
int runBurst(Process process[], TimeIndex timeIndex[], int time);

/*  Function name: copy_process
    Inputs: Process src_process[] - Array of source processes.
            Process dest_process[] - Array of destination processes.
    Output: None
    Description: Copy the processes from the source to the destination 
            array.
*/
static void copy_process(Process src_process[], Process dest_process[]);

#endif