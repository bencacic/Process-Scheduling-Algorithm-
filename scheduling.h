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
            Process temp[] - 
    Output: None
    Description: 
*/
void sortQueue(Process process[], Process temp[]);

/*  Function name: sortSRTF
    Inputs: Process process[] - Array of processes
            Process temp[] - 
    Output: None
    Description: 
*/
void sortSRTF(Process process[], Process temp[]);

/*  Function name: sortPriority
    Inputs: Process process[] - Array of processes
            Process temp[] - 
    Output: None
    Description: 
*/
void sortPriority(Process process[], Process temp[]);

/*  Function name: sortPriority
    Inputs: Process process[] - Array of processes
            Process temp[] - 
    Output: None
    Description: 
*/
int findShortest(Process temp[], int time);

/*  Function name: runBurst
    Inputs: Process process[] - Array of processes
            TimeIndex timeIndex[] - Array of statistic time of each 
                                    process 
            int time - the clock time of the process
    Output: None
    Description: 
*/
int runBurst(Process process[], TimeIndex timeIndex[], int time);

/*  Function name: copy_process
    Inputs: Process src_process[] - Array of source processes
            Process dest_process[] - Array of destination processes 
    Output: None
    Description: 
*/
static void copy_process(Process src_process[], Process dest_process[]);

#endif