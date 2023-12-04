#include "output.h"
// #include "processes.h"

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
static int sumOfBurstTime(Process process[])
{
    int sum = 0;
    for (int i = 0; i < ARR_SIZE; i++)
    {
        sum += process[i].burst_time ;
    }  
    return sum;
}
void makeGantChart(Process process[])
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
        printf("|");
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
    printf("|\n\t");
    for (int i = 0; i < ARR_SIZE; i++)
    {
        printf(" ");
        for (int j = 0; j < scale[i] + 2; j++)
        {
            printf(BOLD CYN);
            printf("--");
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
    printf("%-3d", (process[9].actualStart));
    printf(RESET);
    printf("\n");
    return;
}

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
    printf("$$$$$ STATISTIC RECORD OF FIRST-COME-FIRST-SERVE ALGORITHM $$$$$\n");
}
else if (choice == 3)
{
    fprintf(filePtr, "$$$$$ STATISTIC RECORD OF SHORTEST-REMAINING-TIME $$$$$\n");
    printf("$$$$$ STATISTIC RECORD OF SHORTEST-REMAINING-TIME $$$$$\n");
    
} else if (choice == 5)
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
printf("Total Burst time: %f seconds\n", burstTime);
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


return;
}
