/* Group Members: Mohammed Arab, Khanh Le, Ben Cacic
   Course: COMP 3659
   Assignment: Assignment 02
   Instructor: Marc Schroeder
   File Name: output.c
   Purpose use: Store functions that is used for output purpose
    (1) Printing Gant Chart
    (2) Printing calculated and analyzed data
 */
#include "output.h"

/* Function name: preSetUp

   Inputs: Process process [] - Array of processes
           float scaeARR[] - Array of calculated scale for each process
   Outputs: None
   Description: The function calculated the printing scale for each 
   process based on the burst times for the gant chart.
*/
static void preSetUp (Process process[], float scaleARR[])
{
    // Elapsed_time
    int sum = sumOfBurstTime(process);
    float scale;
    for (int i = 0; i < ARR_SIZE; i++) {
        float scaledBurst = 1.00 + (((float)process[i].burst_time / sum) * 10 );
 
        scaleARR[i] = scaledBurst;
    }
    return; 
}

/* Function name: sumOfBurstTime

   Inputs: Process process [] - Array of processes
   Outputs: int - the sum of the burst time of all processes
   Description: The function calculates the sum of burst times 
   of all processes
*/
static int sumOfBurstTime(Process process[])
{
    int sum = 0;
    for (int i = 0; i < ARR_SIZE; i++)
    {
        sum += process[i].burst_time ;
    }  
    return sum;
}

/* Function name: makeGantChart

   Inputs: Process process [] - Array of processes
   Outputs: None
   Description: The function prints the gant chart of
   processes to the screen
*/
void makeGantChart(Process process[], int choice)
{
    float scale[ARR_SIZE];
    preSetUp(process, scale);

    printf("\n\t");

    for (int i = 0; i < ARR_SIZE; i++)
    {
        printf(" ");
        for (int j = 0; j < scale[i] + 2; j++)
        {
            printf(BOLD CYN"--");
        }
    }
    printf("\n\t");

    for (int i = 0; i < ARR_SIZE; i++)
    {
        printf(BOLD CYN"|");
        for (int j = 0; j < scale[i] + 2; j++)
        {
            if ((((int)scale[i]/2) + 1) == j)
            {
                printf(BOLD CYN);
                printf("P%d",process[i].process_id);
                printf(RESET);
                j++;
            }
            printf("  ");
        }
    }
    printf(BOLD CYN"|\n\t");
    for (int i = 0; i < ARR_SIZE; i++)
    {
        printf(" ");
        for (int j = 0; j < scale[i] + 2; j++)
        {
            printf(BOLD CYN"--");
        }
    }
    printf("\n\t");
    for (int i = 0; i < 10; i++)
    {
        printf(BOLD GRN);
        printf("%-3d", (process[i].actualStart));
        printf(RESET);
        for (int j = 0; j < scale[i] + 1; j++)
        {
            printf("  ");
        }
    }
    printf(BOLD GRN);
    if (choice == 4)
    {  
        print_RR_data(process, scale);
    } else {
        printf("%-3d", (process[9].actualStart + process[9].burst_time));
    }
    printf(RESET);
    printf("\n");


    return;
}
static void print_RR_data(Process process[], float scale[])
{
    // if (process[9].burst_time <= 10)
    // {
    //    // printf(BOLD GRN);
    //     printf("%-3d", (process[9].actualStart));
    //    // printf("%-3d", (process[9].actualStart + process[9].burst_time));
    // }else{
    //    // printf(BOLD GRN);
    //     printf("%-3d", (process[9].actualStart));
    //    // printf("%-3d", (process[9].actualStart + 10));
    // }  
    printf(BOLD GRN"START");  
    printf("\n\t");
        for (int i = 0; i < 10; i++)
        {
        printf(BOLD GRN);
        printf("%-3d", (process[i].completed));
        printf(RESET);
        for (int j = 0; j < scale[i] + 1; j++)
        {
            printf("  ");
        }
        }
        printf(BOLD GRN"COMPLETE"); 
        // printf(BOLD GRN);
        // if (process[9].burst_time <= 10)
        // {
        //     printf("%-3d", (process[9].actualStart + process[9].burst_time));
        // }else{
        //     printf("%-3d", (process[9].actualStart + 10));
        // }
    // printf("\n");
    return;
}

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
               float MeanTurnaroundTime, float meanWaitTime, float meanResponseTime)
{
// Print average CPU burst time with dashes
time_t currentTime;
struct tm *localTime;

time(&currentTime);
localTime = localtime(&currentTime);

printf("\n\n%s\n",asctime(localTime));
fprintf(filePtr, "\n\n%s\n",asctime(localTime));

if (choice == 1)
{
    fprintf(filePtr, "$$$$$ STATISTIC RECORD OF FIRST-COME-FIRST-SERVE ALGORITHM $$$$$\n");
    printf("$$$$$ STATISTIC RECORD OF FIRST-COME-FIRST-SERVE ALGORITHM $$$$$\n");
} else if (choice == 2)
{
    fprintf(filePtr, "$$$$$ STATISTIC RECORD OF SHORTEST-JOB-FIRST $$$$$\n");
    printf("$$$$$ STATISTIC RECORD OF SHORTEST-JOB-FIRST $$$$$\n");
}
else if (choice == 3)
{
    fprintf(filePtr, "$$$$$ STATISTIC RECORD OF SHORTEST-REMAINING-TIME $$$$$\n");
    printf("$$$$$ STATISTIC RECORD OF SHORTEST-REMAINING-TIME $$$$$\n");
    
} else if (choice == 4)
{
    fprintf(filePtr, "$$$$$ STATISTIC RECORD OF ROUND ROBIN ALGORITHM $$$$$\n");
    printf("$$$$$ STATISTIC RECORD OF ROUND ROBIN ALGORITHM $$$$$\n");
}
 else if (choice == 5)
{
    fprintf(filePtr, "$$$$$ STATISTIC RECORD OF PRIORITY-SCHEDULING ALGORITHM $$$$$\n");
    printf("$$$$$ STATISTIC RECORD OF PRIORITY-SCHEDULING ALGORITHM $$$$$\n");
}
// Print total CPU utilization time with dashes
printf("\nTotal CPU utilization: %.2f%% \n",cpuUtilization);
printf("--------------------------------------------------------\n");
fprintf(filePtr, "\nTotal CPU utilization: %.2f%%\n", cpuUtilization);
fprintf(filePtr,"--------------------------------------------------------\n");
// Print average waiting time with dashes
printf("Total burst time: %.0f seconds\n", burstTime);
printf("--------------------------------------------------------\n");
fprintf(filePtr, "Total burst time: %.2f seconds\n", burstTime);
fprintf(filePtr,"--------------------------------------------------------\n");

// Print turnaround time with dashes
printf("Mean Turnaround time: %.2f clock ticks per process\n", MeanTurnaroundTime);
printf("--------------------------------------------------------\n");
fprintf(filePtr, "Mean Turnaround time: %.2f clock ticks per process\n", MeanTurnaroundTime);
fprintf(filePtr,"--------------------------------------------------------\n");

// Print mean waiting time with dashes
printf("Mean wait time: %.2f per process\n", meanWaitTime);
printf("--------------------------------------------------------\n");
fprintf(filePtr, "Mean wait time: %.2f per process\n", meanWaitTime);
fprintf(filePtr,"--------------------------------------------------------\n");


//Print average response time with dashes
printf("Mean response time: %.2f seconds\n", meanResponseTime);
printf("--------------------------------------------------------\n");
fprintf(filePtr, "Mean response time: %.2f seconds\n", meanResponseTime);
fprintf(filePtr,"--------------------------------------------------------\n");

// Print throughput with dashes
printf("Mean throughput: %.6f processes per clock tick\n", throughput);
printf("--------------------------------------------------------\n");
fprintf(filePtr, "Meanhroughput: %.6f processes per clock tick\n", throughput);
fprintf(filePtr,"--------------------------------------------------------\n");

return;
}


