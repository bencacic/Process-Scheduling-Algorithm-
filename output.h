/* Group Members: Mohammed Arab, Khanh Le, Ben Cacic
   Course: COMP 3659
   Assignment: Assignment 02
   Instructor: Marc Schroeder
   File Name: output.h
  Purpose use: Store functions that is used for output purpose
    (1) Printing Gant Chart
    (2) Printing calculated and analyzed data
 */
#ifndef OUTPUT_H
#define OUTPUT_H

#include "mylib.h"
#include "processes.h"

#define BOLD  "\x1B[1m"
#define RESET "\x1B[0m"
#define CYN   "\x1B[36m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define WHT   "\x1B[37m"

/* Function name: preSetUp

   Inputs: Process process [] - Array of processes
           float scaeARR[] - Array of calculated scale for each process
   Outputs: None
   Description: The function calculated the printing scale for each 
   process based on the burst times for the gant chart.
*/
static void preSetUp (Process process[], float scaleARR[]);

/* Function name: sumOfBurstTime

   Inputs: Process process [] - Array of processes
   Outputs: int - the sum of the burst time of all processes
   Description: The function calculates the sum of burst times 
   of all processes
*/
static int sumOfBurstTime(Process process[]);

/* Function name: makeGantChart

   Inputs: Process process [] - Array of processes
   Outputs: None
   Description: The function prints the gant chart of
   processes to the screen
*/
void makeGantChart(Process process[], int choice);

/* Function name: printData

   Inputs: FILE *filePtr - printing to file 
           int choice - algorithm choices 
           float cpuUtilization - CPU Utilization
           float burstTime - Burst time of all processes
           float throughput - Througput of all processes
           float MeanTurnaroundTime - Mean of Turnaround time of all processes
           float meanWaitTime - Mean wait time of all processes
           float meanResponseTime - Mean respond time of all process
   Outputs: None
   Description: The functions print the CPU utilization, total burst time, 
   throughput, mean turnaround time, mean wait time, and mean respond time
   of all processes to the screen and output.txt file based on the chosen
   algorithm(s).
*/
void printData(FILE *filePtr, int choice, float cpuUtilization, float burstTime, float throughput, 
               float MeanTurnaroundTime, float meanWaitTime, float meanResponseTime);


/* Function name: print_RR_data

   Inputs: Process process [] - Array of processes
           float scale [] - Array of calculated scale for each process
   Outputs: None
   Description: The function prints the calculated data retrieved from 
   processes to the screen and the files.
*/
// static void print_PR_data(Process process[], float scale[]);

static void print_data(Process process[], float scale[], int choice);


#endif