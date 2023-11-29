/*
    Group members: Mohammed Cacic, Khanh Le, Ben Cacic
    Course: COMP 3659
    Assignment 2: Process Scheduling Algorithm Simulation 
    File Name: scheduling.h
    Purpose use: Store scheduling algorithms
*/
#ifndef SCHEDULING_C
#define SCHEDULING_C
#include "PROCESSES.H"

void firstComeFirstServe(Process procecess[], int arr_size, TimeIndex timeIndex[]);

void shortestJobFirst(Process procecess[], int arr_size);

void shortestRemainingTimeFirst(Process procecess[], int arr_size);

void roundRobin(Process procecess[], int arr_size);

void priorityScheduling(Process procecess[], int arr_size);

#endif