/* Group Members: Mohammed Arab, Khanh Le, Ben Cacic
   Course: COMP 3659
   Assignment: Assignment 02
   Instructor: Marc Schroeder
   File Name: stat_table.c
 */
#include "stat_table.h"

void statistic_table(Process process[], int choice)
{
    if (choice == 5)
    {
        print_table_priority(process);
    } else if (choice == 1){
        print_table_FCFS(process);
    } else if ((choice == 2) || (choice == 3))
    {
        print_table_ExpectedBurst(process);
    } else if (choice == 4)
    {
        print_table_RR(process);
    }
    return;
}
static void print_label(int choice)
{
    printf(BOLD CYN);
    if (choice == 5)
    {
        printf(BOLD CYN "+-----+--------------+--------------+-----------------+-----------------+-----------------+--------------+--------------+\n");
        print_lable_name();
        printf(BOLD YEL"    Priority  ");
         printf(BOLD CYN); printf("|");
        printf(BOLD CYN "\n+-----+--------------+--------------+-----------------+-----------------+-----------------+--------------+--------------+\n");
    } else if (choice == 1) {
        printf(BOLD CYN "+-----+--------------+--------------+-----------------+-----------------+-----------------+--------------+\n");
        print_lable_name();
        printf(BOLD CYN "\n+-----+--------------+--------------+-----------------+-----------------+-----------------+--------------+\n");
    } else if ((choice == 2) || (choice == 3))
    {
        printf(BOLD CYN "+-----+--------------+--------------+-----------------+-----------------+-----------------+--------------+-----------------+\n");
        print_lable_name();
        printf(BOLD YEL"  Expected Ouput ");
        printf(BOLD CYN); printf("|");
        printf(BOLD CYN "\n+-----+--------------+--------------+-----------------+-----------------+-----------------+--------------+-----------------+\n");
    } else if (choice == 4)
    {
        printf(BOLD CYN "+-----+--------------+--------------+-----------------+-----------------+-----------------+--------------+--------------+\n");
        print_lable_name();
        printf(BOLD YEL"  # of Bursts ");
        printf(BOLD CYN); printf("|");
        printf(BOLD CYN "\n+-----+--------------+--------------+-----------------+-----------------+-----------------+--------------+--------------+\n");
    }

    return;
}
static void print_lable_name()
{
    printf(BOLD CYN); printf("| ");
    printf(BOLD YEL); printf("PID ");
    printf(BOLD CYN); printf("| ");
    printf(BOLD YEL); printf("Arrival Time ");
    printf(BOLD CYN); printf("| ");
    printf(BOLD YEL); printf("Actual Start ");
    printf(BOLD CYN); printf("| ");
    printf(BOLD YEL); printf("  Burst Time    ");
    printf(BOLD CYN); printf("| ");
    printf(BOLD YEL); printf("Completion Time ");
    printf(BOLD CYN); printf("| ");
    printf(BOLD YEL); printf("Turnaround Time ");
    printf(BOLD CYN); printf("| ");
    printf(BOLD YEL); printf("Waiting Time ");
    printf(BOLD CYN"|");

    return;
}
static void print_table_priority(Process process[])
{
    print_label(5);

    for (int i = 0; i < ARR_SIZE; i++)
    {
        printf(BOLD CYN"| ");  printf(WHT "P%d  ",process[i].process_id);
        printf(BOLD CYN"|     "); printf(WHT"%3d      ",process[i].arrival_time);
        printf(BOLD CYN"|     "); printf(WHT"%3d      ",process[i].actualStart);
        printf(BOLD CYN"|     "); printf(WHT"%3d         ",process[i].burst_time);
        // actual starting time + burst time = completion time
        int completionTime = process[i].actualStart + process[i].burst_time;
        printf(BOLD CYN"|       "); printf(WHT "%3d       ",completionTime);
        // completion time - arrival time = turnaround time
        int turnaroundTime = completionTime - process[i].arrival_time;
        printf(BOLD CYN"|        "); printf(WHT"%3d      ", turnaroundTime);
        // turn_around time - burst time = waiting time
        printf(BOLD CYN"|     "); printf(WHT "%3d      ", (turnaroundTime - process[i].burst_time));
        printf(BOLD CYN"|   ");  printf(WHT"  %3d      ",process[i].priority);
        printf(BOLD CYN"|\n");
        printf(BOLD CYN);
        printf(BOLD CYN "+-----+--------------+--------------+-----------------+-----------------+-----------------+--------------+--------------+\n");
    }
}
static void print_table_FCFS(Process process[])
{
    print_label(1);
    for (int i = 0; i < ARR_SIZE; i++)
    {
        printf(BOLD CYN"| ");  printf(WHT "P%d  ",process[i].process_id);
        printf(BOLD CYN"|     "); printf(WHT"%3d      ",process[i].arrival_time);
        printf(BOLD CYN"|     "); printf(WHT"%3d      ",process[i].actualStart);
        printf(BOLD CYN"|     "); printf(WHT"%3d         ",process[i].burst_time);
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
        printf(BOLD CYN "+-----+--------------+--------------+-----------------+-----------------+-----------------+--------------+\n");
    }
    return;
}
static void print_table_ExpectedBurst(Process process[])
{
    print_label(2);
    for (int i = 0; i < ARR_SIZE; i++)
    {
        printf(BOLD CYN"| ");  printf(WHT "P%d  ",process[i].process_id);
        printf(BOLD CYN"|     "); printf(WHT"%3d      ",process[i].arrival_time);
        printf(BOLD CYN"|     "); printf(WHT"%3d      ",process[i].actualStart);
        printf(BOLD CYN"|     "); printf(WHT"%3d         ",process[i].burst_time);
        // actual starting time + burst time = completion time 
        int completionTime = process[i].actualStart + process[i].burst_time;
        printf(BOLD CYN"|       "); printf(WHT "%3d       ",completionTime);
        // completion time - arrival time = turnaround time
        int turnaroundTime = completionTime - process[i].arrival_time;
        printf(BOLD CYN"|        "); printf(WHT"%3d      ", turnaroundTime);
        // turn_around time - burst time = waiting time
        printf(BOLD CYN"|     "); printf(WHT "%3d      ", (turnaroundTime - process[i].burst_time));
        printf(BOLD CYN"|  "); printf(WHT "%10.2f     ", process[i].estimatedBurstTime);
        printf(BOLD CYN"|\n");
        printf(BOLD CYN);
        printf(BOLD CYN "+-----+--------------+--------------+-----------------+-----------------+-----------------+--------------+-----------------+\n");
    }
    return;
}

static void print_table_RR(Process process[])
{
    print_label(4);
    for (int i = 0; i < ARR_SIZE; i++)
    {
        printf(BOLD CYN"| ");  printf(WHT "P%d  ",process[i].process_id);
        printf(BOLD CYN"|     "); printf(WHT"%3d      ",process[i].arrival_time);
        printf(BOLD CYN"|     "); printf(WHT"%3d      ",process[i].actualStart);
        printf(BOLD CYN"|     "); printf(WHT"%3d         ",process[i].burst_time);
        // actual starting time + burst time = completion time 
        int completionTime = process[i].actualStart + process[i].burst_time;
        printf(BOLD CYN"|       "); printf(WHT "%3d       ",completionTime);
        // completion time - arrival time = turnaround time
        int turnaroundTime = completionTime - process[i].arrival_time;
        printf(BOLD CYN"|        "); printf(WHT"%3d      ", turnaroundTime);
        // turn_around time - burst time = waiting time
        printf(BOLD CYN"|     "); printf(WHT "%3d      ", (turnaroundTime - process[i].burst_time));
        printf(BOLD CYN"|     "); printf(WHT "%3d      ", process[i].burst_time);
        printf(BOLD CYN"|\n");
        printf(BOLD CYN);
        printf(BOLD CYN "+-----+--------------+--------------+-----------------+-----------------+-----------------+--------------+--------------+\n");
    }
    return;
}