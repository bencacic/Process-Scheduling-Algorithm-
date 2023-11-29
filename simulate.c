#include "processes.h"
#include "scheduling.h"
#include "timeControl.h"
void menu();
void runProcesses(int option, Process procecess[], TimeIndex timeIndex[]) ;
void printData(float cpuUtilization, float total_burstTime);
// void firstComeFirstServe();
void runfirstComeFirstServe(Process procecess[], TimeIndex timeIndex[]);

 
    //#define Process process[ARR_SIZE];
    //#define TimeIndex timeIndex[ARR_SIZE];

    // initProcesses(process);
    // initTimeIndex(timeIndex);


int main() {

    //loop through all arrays of processes. Or have a seclection menu so that the user can pick which set of processes to initilize and which algorithm they want to test.
   // runProcesses();
   menu();
    return 0;
}


//This runs a single set of processes on one algorithm. As implement more algorithms, we can add to it so it.
void runProcesses(int option, Process process[], TimeIndex timeIndex[]) {        
    // clock_t start_t, end_t;
    // double total_t;

    // Process process[ARR_SIZE];
    // TimeIndex timeIndex[ARR_SIZE];

    // initProcesses(process);
    // initTimeIndex(timeIndex);

   // runfirstComeFirstServe(process,timeIndex);
    //firstjobdone();

    if (option == 1){
    runfirstComeFirstServe(process,timeIndex);
    }else if (option == 2)
    {
       // firstjobdone();
        /* code */
    } else {
        printf("Not Implemente");
    }
    
    // start_t = clock();

    // firstComeFirstServe(process, timeIndex);
    // //runfirstComeFirstServe();
    // // maybe long, idk how big these numbers are gonna be
    // int total_CPU_time, total_wall_time, total_burst_time = 0;

    // retrieve_time_totals(timeIndex, &total_CPU_time,  &total_wall_time, &total_burst_time);

    // float CPU_util = CPU_utilization(total_CPU_time, total_wall_time);

    //call print function here maybe
}



void runfirstComeFirstServe(Process procecess[], TimeIndex timeIndex[]){
    int cpuTimeSum = 0;
    int wallTimeSum = 0;
    float cpuUtilizzation = 0;
    float averageWaitTime = 0;
    float burstTime = 0;
    int total_burstTime = 0;
   // Process procecess[ARR_SIZE];
   // TimeIndex timeIndex[ARR_SIZE];
    firstComeFirstServe(procecess, timeIndex);
    retrieve_time_totals(timeIndex, &cpuTimeSum,  &wallTimeSum, &total_burstTime);
 //   cpuTimeSum = timeIndex->cpuBurstTime;
   // wallTimeSum = timeIndex->totalBurstTime;
    cpuUtilizzation = CPU_utilization(cpuTimeSum, wallTimeSum);
    burstTime = totalBurstTime(wallTimeSum);
    printData(cpuUtilizzation, burstTime);
 } 

 void printData(float cpuUtilization, float burstTime){
// Print average CPU burst time with dashes
// printf("Average CPU burst time: %f S\n", average_Waiting_ime);
// printf("---------------------------------\n");

// Print total CPU utilization time with dashes
printf("\nTotal CPU utilization: %.2f%% \n",cpuUtilization);
printf("---------------------------------\n");

// Print average waiting time with dashes
printf("Total Burst time: %.6f seconds\n", burstTime);
printf("---------------------------------\n");

// Print average turnaround time with dashes
// printf("Average turnaround time: %.2f\n", average_turnaround_time);
// printf("---------------------------------\n");

// // Print throughput with dashes
// printf("Throughput: %.2f processes per unit time\n", throughput);
// printf("---------------------------------\n");

// // Print context switch count with dashes
// printf("Total context switches: %d\n", total_context_switches);
// printf("---------------------------------\n");
 }

void menu() {
    
    Process process[ARR_SIZE];
    TimeIndex timeIndex[ARR_SIZE];

    initProcesses(process);
    initTimeIndex(timeIndex);

    printf("\nSelect the alogrithm to run: \n");
    printf("\n1) First-come-first-serve Algorithm \n");
    printf("\n2) Shortest Job First (Non-preemptive) \n");
    printf("\n3) Shortest Remaining Time First \n");
    printf("\n4) Round Robin \n");
    printf("\n5) Priority Scheduling \n\n");

    printf("Enter your choice here (option between 1 to 5): ");

    int choice;
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
    runProcesses(1, process, timeIndex);
   // runProcesses(1, process, timeIndex);
   // runProcesses(1, process, timeIndex);
       // runfirstComeFirstServe();//print
        // Call FIFO function 
        break;
    case 2:
        // call Shortest job first 
        break;
    case 3:
        // call shortest remaining time first 
        break;
    case 4:
        // Call Round Robin 
        break;
    case 5:
        // Call Priority Scheduling 
        break;
    default:
        printf("***** ERROR - You enter an invalid option number! *****\n");
        break;
    }
    return;
}
