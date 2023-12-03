#include "processes.h"
#include "scheduling.h"
#include "timeControl.h"

void menu();
void runProcesses(int option, Process procecess[], TimeIndex timeIndex[]) ;
void printData(int choice, float cpuUtilization, float burstTime, float throughput, 
               float MeanTurnaroundTime, float meanWaitTime, float meanResponseTime);
// void firstComeFirstServe();
void runfirstComeFirstServe(Process procecess[], TimeIndex timeIndex[]);

 
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
        printf("Not Implemented");
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
    int wallTime, waitTime, burstTime, startTime = 0;
    float meanWaitTime, cpuUtilizzation, throughput, MeanTurnaroundTime, meanResponseTime = 0;

    readyQueue(procecess, 1);
    wallTime = firstComeFirstServe(procecess, timeIndex);
    retrieve_time_totals(timeIndex, &burstTime, &startTime, &waitTime);
    printf("burst time %d" ,burstTime);
    printf("wallTime time %d" ,wallTime);

    cpuUtilizzation = CPU_utilization(burstTime, wallTime);

    throughput = throughPut(wallTime);
    MeanTurnaroundTime = turnaround_time(burstTime);
    meanWaitTime = waitingTime(waitTime);
    meanResponseTime = response_time(waitTime);
    printData(FCFS_ALGORITHM,cpuUtilizzation, burstTime, throughput, MeanTurnaroundTime, meanWaitTime, meanResponseTime);
 } 

void printData(int choice, float cpuUtilization, float burstTime, float throughput, 
               float MeanTurnaroundTime, float meanWaitTime, float meanResponseTime)
{
// Print average CPU burst time with dashes
time_t currentTime;
struct tm *localTime;
FILE *filePtr;

filePtr = fopen("output.txt", "w+");

if (filePtr == NULL)
{
    printf("ERROR - UNABLE TO OPEN THE FILE\n");
}

time(&currentTime);
localTime = localtime(&currentTime);

printf("\n\n%s\n",asctime(localTime));
fprintf(filePtr, "\n\n%s\n",asctime(localTime));

if (choice == FCFS_ALGORITHM)
{
    fprintf(filePtr, "$$$$$ STATISTIC RECORD OF FIRST-COME-FIRST-SERVE ALGORITHM $$$$$\n");
    printf("$$$$$ STATISTIC RECORD OF FIRST-COME-FIRST-SERVE ALGORITHM $$$$$\n");
}
// Print total CPU utilization time with dashes
printf("\nTotal CPU utilization: %.2f%% \n",cpuUtilization);
printf("--------------------------------------------------------\n");
fprintf(filePtr, "\nTotal CPU utilization: %.2f%%\n", cpuUtilization);
fprintf(filePtr,"--------------------------------------------------------\n");
// Print average waiting time with dashes
printf("Total Burst time: %.6f seconds\n", burstTime);
printf("--------------------------------------------------------\n");
fprintf(filePtr, "Total Burst time: %.6f seconds\n", burstTime);
fprintf(filePtr,"--------------------------------------------------------\n");

// Print mean waiting time with dashes
printf("Mean wait time: %.6f per process\n", meanWaitTime);
printf("--------------------------------------------------------\n");
fprintf(filePtr, "Mean wait time: %.6f per process\n", meanWaitTime);
fprintf(filePtr,"--------------------------------------------------------\n");

// Print throughput with dashes
printf("Throughput: %.6f processes per unit time\n", throughput);
printf("--------------------------------------------------------\n");
fprintf(filePtr, "Throughput: %.6f processes per unit time\n", throughput);
fprintf(filePtr,"--------------------------------------------------------\n");

//Print average response time with dashes
printf("Average response time: %.6f seconds\n", meanResponseTime);
printf("--------------------------------------------------------\n");
fprintf(filePtr, "Average response time: %.6f seconds\n", meanResponseTime);
fprintf(filePtr,"--------------------------------------------------------\n");

// Print turnaround time with dashes
printf("Turnaround time: %.6f processes per unit time\n", MeanTurnaroundTime);
printf("--------------------------------------------------------\n");
fprintf(filePtr, "Turnaround time: %.6f processes per unit time\n", MeanTurnaroundTime);
fprintf(filePtr,"--------------------------------------------------------\n");

fclose(filePtr);

return;
}


void menu() {
    
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
        printf("6) To view all all\n");
        printf("To terminate the program, please enter -1\n");

        printf("Enter your choice here (options 1 to 5, or -1 to terminate): ");
        scanf("%d", &choice);

        if (choice == FCFS_ALGORITHM)
        {
            runfirstComeFirstServe(process,timeIndex);
        } else if (choice == SHORTEST_JOB_FIRST)
        {
            // Call Shortest Job First 
        } else if (choice == SHORTEST_REMAIN_TIME)
        {
            // Call Shortest Remaining Time 
        } else if (choice == ROUND_ROBIN)
        {
            // Call Round Robin
        } else if (choice == PRIORITY_SCHEDULING)
        {
            // Call Priority Schedule
        } else if (choice == 6)
        {
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
