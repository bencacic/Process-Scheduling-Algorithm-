/*
    Group members: Mohammed Arab, Khanh Le, Ben Cacic
    Course: COMP 3659
    Assignment 2: Process Scheduling Algorithm Simulation 
    File Name: main_helper.c
    Purpose use: Store helper functions for the main file
    simulatte.c. 
    There are 2 helper functions:
        (1) - prompting the menu and retrieve user's input
        (2) - perform the selected algorithm and output
              relevant data calculated
*/
#include "main_helper.h"
#include "output.h"
#include "stat_table.h"

// OPTION CHOICE NUMBER
const int FCFS_ALGORITHM = 1;
const int SHORTEST_JOB_FIRST = 2;
const int SHORTEST_REMAIN_TIME = 3;
const int ROUND_ROBIN = 4;
const int PRIORITY_SCHEDULING = 5;

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
void runAlgo(Process processes[], TimeIndex timeIndex[], int choice, FILE *filePtr){
    int wallTime, waitTime, burstTime, startTime = 0;
    float meanWaitTime, cpuUtilization, throughput, MeanTurnaroundTime, meanResponseTime = 0;
  
    // run the selected algorithm
    readyQueue(processes, choice);

    if (choice == 1){
        wallTime = firstComeFirstServe(processes, timeIndex);
    }else if (choice == 2)
    {  
      wallTime = shortestJobFirst( processes, timeIndex);
    }else if (choice == 3) 
    {
        wallTime = shortestRemainingTimeFirst(processes, timeIndex);
    } else if (choice == 4)
    {
        wallTime = roundRobin(processes, timeIndex);
    }
    else if (choice == 5)
    {
        wallTime = priorityScheduling(processes, timeIndex);
    }
    
    // retrieve statistic information
    retrieve_time_totals(timeIndex, &burstTime, &startTime, &waitTime);
    cpuUtilization = CPU_utilization(burstTime, wallTime);
    throughput = throughPut(wallTime);
    MeanTurnaroundTime = turnaround_time(burstTime, waitTime);
    meanWaitTime = waitingTime(waitTime);
    meanResponseTime = response_time(startTime);
    
    // print the output
    statistic_table(processes,choice);
    makeGantChart(processes, choice);
    for (int i = 0; i < ARR_SIZE; i++)
    {
        processes[i].completed = 0;
    }
    printData(filePtr,choice,cpuUtilization,burstTime,throughput,MeanTurnaroundTime,meanWaitTime,meanResponseTime);
 } 

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
void menu(FILE *filePtr) {
    
    Process process[ARR_SIZE];
    TimeIndex timeIndex[ARR_SIZE];
    int choice;

    initProcesses(process);
    initTimeIndex(timeIndex, process);

     do {
        printf("\nSelect the algorithm to run: \n");
        printf("1) First-come-first-serve Algorithm\n");
        printf("2) Shortest Job First (Non-preemptive)\n");
        printf("3) Shortest Remaining Time First\n");
        printf("4) Round Robin\n");
        printf("5) Priority Scheduling\n");
        printf("6) To view all algorithms\n");
        printf("To terminate the program, please enter -1\n");

        printf("Enter your choice here (options 1 to 5, or -1 to terminate): ");
        scanf("%d", &choice);

        if (choice == FCFS_ALGORITHM)
        {
            runAlgo(process, timeIndex, FCFS_ALGORITHM,filePtr);
            //runfirstComeFirstServe(process,process);
        } else if (choice == SHORTEST_JOB_FIRST)
        {
            runAlgo(process, timeIndex, SHORTEST_JOB_FIRST,filePtr);
            // Call Shortest Job First 
        } else if (choice == SHORTEST_REMAIN_TIME)
        {
            runAlgo(process, timeIndex, SHORTEST_REMAIN_TIME,filePtr);
            // Call Shortest Remaining Time 
        } else if (choice == ROUND_ROBIN)
        {
            runAlgo(process, timeIndex, ROUND_ROBIN,filePtr);
            // Call Round Robin
        } else if (choice == PRIORITY_SCHEDULING)
        {
            runAlgo(process, timeIndex, PRIORITY_SCHEDULING,filePtr);
            // Call Priority Schedule
        } else if (choice == 6)
        {
            runAlgo(process, timeIndex, FCFS_ALGORITHM,filePtr);
            runAlgo(process, timeIndex, SHORTEST_JOB_FIRST,filePtr);
            runAlgo(process, timeIndex, SHORTEST_REMAIN_TIME,filePtr);
            runAlgo(process, timeIndex, ROUND_ROBIN,filePtr);
            runAlgo(process, timeIndex, PRIORITY_SCHEDULING,filePtr);
            /// call all the functions
        } else if (choice == -1)
        {
            printf("\nProgram terminated.\n");
        } else 
        {
            printf("\n***** ERROR - YOU ENTERED AN INVALID OPTION *****\n");
        }
        fflush(stdin);

    } while (choice != -1);

    return;
}