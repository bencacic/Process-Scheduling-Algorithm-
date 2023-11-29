/*
    Group members: Mohammed Cacic, Khanh Le, Ben Cacic
    Course: COMP 3659
    Assignment 2: Process Scheduling Algorithm Simulation 
    File Name: processes.h
    Purpose use: Store the information of the processes
*/
#ifndef PROCESSES_H
#define PROCESSES_H

#include "mylib.h"


typedef struct {
    int process_id;
    int arrival_time;
    int cpu_burst_time;
    //how it is going be interrupted
    int io_burst_time;
    int remaining_time;
    int priority;  
} Process;

void initProcesses(Process process[]);


#endif