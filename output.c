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
            printf("--");
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

if (choice == 1)
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

fclose(filePtr);

return;
}
void statistic_table(Process process[], int priority_flag)
{
    if (priority_flag)
    {
        print_table_priority(process);
    } else{
        print_table(process);
    }
    return;
}
static void print_table_priority(Process process[])
{
    printf("\n");
    printf(BOLD CYN);
    printf("\t+-----+----------+--------------+------------+-----------------+-----------------+--------------+\n");
    printf(BOLD CYN); printf("\t| ");
    printf(BOLD YEL); printf("PID ");
    printf(BOLD CYN); printf("| ");
    printf(BOLD YEL); printf("Priority ");
    printf(BOLD CYN); printf("| ");
    printf(BOLD YEL); printf("Arrival Time ");
    printf(BOLD CYN); printf("| ");
    printf(BOLD YEL); printf("Burst Time ");
    printf(BOLD CYN); printf("| ");
    printf(BOLD YEL); printf("Completion Time ");
    printf(BOLD CYN); printf("| ");
    printf(BOLD YEL); printf("Turnaround Time ");
    printf(BOLD CYN); printf("| ");
    printf(BOLD YEL); printf("Waiting Time ");
    printf(BOLD CYN"|\n");
    printf(BOLD CYN);
    printf("\t+-----+----------+--------------+------------+-----------------+-----------------+--------------+\n" RESET);

    for (int i = 0; i < ARR_SIZE; i++)
    {
        printf(BOLD CYN"\t| ");  printf(WHT "P%d  ",process[i].process_id);
        printf(BOLD CYN"|   ");  printf(WHT"%3d    ",process[i].priority);
        printf(BOLD CYN"|     "); printf(WHT"%3d      ",process[i].arrival_time);
        printf(BOLD CYN"|     "); printf(WHT"%3d    ",process[i].burst_time);
        // actual starting time + burst time = completion time
        int completionTime = process[i].actualStart + process[i].burst_time;
        printf(BOLD CYN"|       "); printf(WHT "%3d       ",completionTime);
        // completion time - arrival time = turnaround time
        int turnaroundTime = completionTime - process[i].arrival_time;
        printf(BOLD CYN"|        "); printf(WHT"%3d      ", turnaroundTime);
        // turn_around time - burst time = waiting time
        printf(BOLD CYN"|     "); printf(WHT "%3d      ", (turnaroundTime - process[i].burst_time));
        printf(BOLD CYN"|\n");
        printf(BOLD CYN);
        printf("\t+-----+----------+--------------+------------+-----------------+-----------------+--------------+\n" RESET);
    }
}
static void print_table(Process process[])
{
    printf("\n");
    printf(BOLD CYN);
    printf(BOLD CYN "\t+-----+--------------+------------+-----------------+-----------------+--------------+\n");
    printf(BOLD CYN); printf("\t| ");
    printf(BOLD YEL); printf("PID ");
    printf(BOLD CYN); printf("| ");
    printf(BOLD YEL); printf("Arrival Time ");
    printf(BOLD CYN); printf("| ");
    printf(BOLD YEL); printf("Burst Time ");
    printf(BOLD CYN); printf("| ");
    printf(BOLD YEL); printf("Completion Time ");
    printf(BOLD CYN); printf("| ");
    printf(BOLD YEL); printf("Turnaround Time ");
    printf(BOLD CYN); printf("| ");
    printf(BOLD YEL); printf("Waiting Time ");
    printf(BOLD CYN"|\n");
    printf(BOLD CYN);
    printf(BOLD CYN "\t+-----+--------------+------------+-----------------+-----------------+--------------+\n");

    for (int i = 0; i < ARR_SIZE; i++)
    {
        printf(BOLD CYN"\t| ");  printf(WHT "P%d  ",process[i].process_id);
        printf(BOLD CYN"|     "); printf(WHT"%3d      ",process[i].arrival_time);
        printf(BOLD CYN"|     "); printf(WHT"%3d    ",process[i].burst_time);
        // actual starting time + burst time = completion time 
        int completionTime = process[i].actualStart + process[i].burst_time;
        printf(BOLD CYN"|       "); printf(WHT "%3d       ",completionTime);
        // completion time - arrival time = turnaround time
        int turnaroundTime = completionTime - process[i].arrival_time;
        printf(BOLD CYN"|        "); printf(WHT"%3d      ", turnaroundTime);
        // turn_around time - burst time = waiting time
        printf(BOLD CYN"|     "); printf(WHT "%3d      ", (turnaroundTime - process[i].burst_time));
        printf(BOLD CYN"|\n");
        printf(BOLD CYN);
        printf(BOLD CYN "\t+-----+--------------+------------+-----------------+-----------------+--------------+\n");
    }
    return;
}