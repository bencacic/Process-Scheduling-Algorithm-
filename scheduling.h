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

void firstComeFirstServe(Process procecess[], TimeIndex timeIndex[]);

void shortestJobFirst(Process procecess[]);

void shortestRemainingTimeFirst(Process procecess[]);

void roundRobin(Process procecess[]);

void priorityScheduling(Process procecess[]);

#endif