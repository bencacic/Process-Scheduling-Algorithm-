/*
    Group members: Mohammed Arab, Khanh Le, Ben Cacic
    Course: COMP 3659
    Assignment 2: Process Scheduling Algorithm Simulation 
    File Name: main_helper.h
    Purpose use: Store helper functions for the main file
    simulatte.c. 
    There are 2 helper functions:
        (1) - prompting the menu and retrieve user's input
        (2) - perform the selected algorithm and output
              relevant data calculated
*/
#ifndef MAIN_HELPER_H
#define MAIN_HELPER_H

#include "mylib.h"
#include "processes.h"
#include "timeControl.h"
#include "scheduling.h"

/*  Function name: menu
    Inputs: FILE *filePtr - file variable for printing to the 
                            file purpose
    Output: None
    Description: This function prompts the menu of scheduling 
    algorithm option to the users and retrieves the user input.
    Based on the user's selected algorithm, the function calls 
    the run_algo functions and passed the selected choice to the 
    function to perform the scheduling.
    The options are:
        1 - FCFS
        2 - Shortest Job First
        3 - Shortest Remaing Time First
        4 - Round Robin
        5 - Priority Scheduling 
        6 - All algorithms to run at the same time
        -1 - Terminate the program
*/
void menu( FILE *filePtr); 

/*  Function name: runAlgo
    Inputs: Process processes[] - Array of processes
            TimeIndex timeIndex[] - Array of statistic time of each 
                                    process 
            int choice - algorithm choices 
            FILE *filePtr - file variable to perform printing to the 
                            specified file 
    Output: None
    Description: The function performs the scheduling algorithm based on 
    the specified choice from the user's input. After the scheduling 
    algorithm finishes, the function also is responsble for output 
    all relevant data that has been calculated by the scheduling algorithm
    to the screen and the file name "ouput.txt"
*/
void runAlgo(Process processes[], TimeIndex timeIndex[], int choice, FILE *filePtr);


#endif