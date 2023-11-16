/*
    Group members: Mohammed Cacic, Khanh Le, Ben Cacic
    Course: COMP 3659
    Assignment 2: Process Scheduling Algorithm Simulation 
    File Name: processes.h
    Purpose use: Store the information of the processes
*/
#ifndef PROCESSES_C
#define PROCESSES_C

typedef struct {
    int process_id;
    int arrival_time;
    int burst_time;
    // int remaining_time;
} Processes;
#endif