#include "processes.h"
#include "scheduling.h"
#include "timeControl.h"
#include "output.h"
#include "mylib.h"
#include "stat_table.h"

void menu( FILE *filePtr);
void runAlgo(Process procecess[], TimeIndex timeIndex[], int choice, FILE *filePtr);
// void firstComeFirstServe();
// void runfirstComeFirstServe(Process procecess[], TimeIndex timeIndex[]);

 
    //#define Process process[ARR_SIZE];
    //#define TimeIndex timeIndex[ARR_SIZE];

    // initProcesses(process);
    // initTimeIndex(timeIndex);

const int FCFS_ALGORITHM = 1;
const int SHORTEST_JOB_FIRST = 2;
const int SHORTEST_REMAIN_TIME = 3;
const int ROUND_ROBIN = 4;
const int PRIORITY_SCHEDULING = 5;

int main() {
    //loop through all arrays of processes. Or have a seclection menu so that the user can pick which set of processes to initilize and which algorithm they want to test.
   // runProcesses();
    FILE *filePtr;
    filePtr = fopen("output.txt", "w+");

    if (filePtr == NULL)
    {
        printf("ERROR - UNABLE TO OPEN THE FILE\n");
    } else
    {
        menu(filePtr);
        fclose(filePtr);
    }
    return 0;
}


// //This runs a single set of processes on one algorithm. As implement more algorithms, we can add to it so it.
// void runProcesses(int option, Process process[], TimeIndex timeIndex[]) {        
//     // clock_t start_t, end_t;
//     // double total_t;

//     // Process process[ARR_SIZE];
//     // TimeIndex timeIndex[ARR_SIZE];

//     // initProcesses(process);
//     // initTimeIndex(timeIndex);

//    // runfirstComeFirstServe(process,timeIndex);
//     //firstjobdone();

//     if (option == 1){
//         runfirstComeFirstServe(process,timeIndex);
//     }else if (option == 2)
//     {
//        // firstjobdone();
//         /* code */
//     } else {
//         printf("Not Implemented");
//     }
    
//     // start_t = clock();

//     // firstComeFirstServe(process, timeIndex);
//     // //runfirstComeFirstServe();
//     // // maybe long, idk how big these numbers are gonna be
//     // int total_CPU_time, total_wall_time, total_burst_time = 0;

//     // retrieve_time_totals(timeIndex, &total_CPU_time,  &total_wall_time, &total_burst_time);

//     // float CPU_util = CPU_utilization(total_CPU_time, total_wall_time);

//     //call print function here maybe
// }

void runAlgo(Process procecess[], TimeIndex timeIndex[], int choice, FILE *filePtr){
    int wallTime, waitTime, burstTime, startTime = 0;
    float meanWaitTime, cpuUtilizzation, throughput, MeanTurnaroundTime, meanResponseTime = 0;
  
    // run the selected algorithm
    readyQueue(procecess, choice);

    //  if (choice == 3 || choice == 4)
    // {
    //      for (int i = 0; i < ARR_SIZE; i++)
    //     {
    //         temp[i] = procecess[i];
    //     }
    // }
    if (choice == 1){
        wallTime = firstComeFirstServe(procecess, timeIndex);
    }else if (choice == 2){  
      wallTime = shortestJobFirst( procecess, timeIndex);
    }else if (choice == 3) {
        wallTime = shortestRemainingTimeFirst(procecess, timeIndex);
    } else if (choice == 4)
    {
        wallTime = roundRobin(procecess, timeIndex);
    }
    else if (choice == 5)
    {
        wallTime = priorityScheduling(procecess, timeIndex);
    }
    
    // retrieve statistic information
    retrieve_time_totals(timeIndex, &burstTime, &startTime, &waitTime);
    cpuUtilizzation = CPU_utilization(burstTime, wallTime);
    throughput = throughPut(wallTime);
    MeanTurnaroundTime = turnaround_time(burstTime, waitTime);
    meanWaitTime = waitingTime(waitTime);
    meanResponseTime = response_time(waitTime);
    
    // print the output
    statistic_table(procecess,choice);
    makeGantChart(procecess, choice);
    for (int i = 0; i < ARR_SIZE; i++)
    {
        procecess[i].completed = 0;
    }
    printData(filePtr,choice,cpuUtilizzation,burstTime,throughput,MeanTurnaroundTime,meanWaitTime,meanResponseTime);
 } 


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
            runAlgo(process, timeIndex, 1,filePtr);
            //runfirstComeFirstServe(process,process);
        } else if (choice == SHORTEST_JOB_FIRST)
        {
            runAlgo(process, timeIndex, 2,filePtr);
            // Call Shortest Job First 
        } else if (choice == SHORTEST_REMAIN_TIME)
        {
            runAlgo(process, timeIndex, 3,filePtr);
            // Call Shortest Remaining Time 
        } else if (choice == ROUND_ROBIN)
        {
            runAlgo(process, timeIndex, 4,filePtr);
            // Call Round Robin
        } else if (choice == PRIORITY_SCHEDULING)
        {
            runAlgo(process, timeIndex, 5,filePtr);
            // Call Priority Schedule
        } else if (choice == 6)
        {
            runAlgo(process, timeIndex, 1,filePtr);
            runAlgo(process, timeIndex, 2,filePtr);
            runAlgo(process, timeIndex, 5,filePtr);
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
