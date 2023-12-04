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

int firstComeFirstServe(Process procecess[], TimeIndex timeIndex[]);

int shortestJobFirst(Process process[], TimeIndex timeIndex[]);   

int shortestRemainingTimeFirst(Process process[], TimeIndex timeIndex[]);

void roundRobin(Process procecess[]);

int priorityScheduling(Process process[], TimeIndex timeIndex[]);

int findIndex(const Process *arr, int size, int searchId);

void sortQueue(Process process[], Process temp[]);
void sortPriority(Process process[], Process temp[]);
void swap(Process process[], TimeIndex timeIndex[], int index1, int index2);


#endif