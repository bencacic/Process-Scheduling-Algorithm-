/*
    Group members: Mohammed Cacic, Khanh Le, Ben Cacic
    Course: COMP 3659
    Assignment 2: Process Scheduling Algorithm Simulation 
    File Name: scheduling.c
    Purpose use: Store scheduling algorithms
*/
#include "scheduling.h"
#include "output.h"

/*  Function name: firstComeFirstServe
    Inputs: Process process[] - Array of processes
            TimeIndex timeIndex[] - Array of statistic time of each 
                                    process 
    Output: int - the wall time
    Description: The function performs the first-come-first-serve
    scheduling algorithms on the processes.
*/

int firstComeFirstServe(Process process[], TimeIndex timeIndex[]) {
    int time = 0;
    return runBurst( process, timeIndex, time);
}

/*  Function name: shortestJobFirst
    Inputs: Process process[] - Array of processes
            TimeIndex timeIndex[] - Array of statistic time of each 
                                    process 
    Output: int - the wall time
    Description: The function performs the shortest job first
    scheduling algorithms on the processes.
*/

int shortestJobFirst(Process process[], TimeIndex timeIndex[]){
    int time = 0;
    Process temp[ARR_SIZE];

    copy_process(process,temp);
    qsort(temp, (size_t)ARR_SIZE, sizeof(temp[0]), compareSJF);
    sortQueue(process, temp);

    return runBurst( process, timeIndex, time);
}


int shortestRemainingTimeFirst(Process process[], TimeIndex timeIndex[]) {
    int time = 0;
    int completed = 0;
    int numberOfBursts = 0;
    int newIndex = -1;
    int shortestIndex = -1;
    Process temp[ARR_SIZE];
    
    copy_process(process,temp);
    qsort(temp, (size_t)ARR_SIZE, sizeof(temp[0]), compareSJF);
    sortSRTF(process, temp);
    copy_process(process,temp);
     
    while (completed < ARR_SIZE) { 
        shortestIndex = findShortest(temp, time);
        if (shortestIndex == -1) {
            time++; // No process available to execute, move to the next unit of time
            continue;
        }

        if(temp[shortestIndex].started == 1){
            timeIndex[shortestIndex].startTime = time;
            temp[shortestIndex].actualStart = time;
            temp[shortestIndex].started = 0;
            }
       
        process[shortestIndex].actualStart = time;
        while( temp[shortestIndex].burst_time > 0){
        temp[shortestIndex].burst_time--;
        time++;
        newIndex = findShortest(temp, time);
         
        if(newIndex != shortestIndex){
            break;
            }
        }
  
        process[shortestIndex].completed = time;
        if (temp[shortestIndex].burst_time <= 0) {
            temp[shortestIndex].completed = 1;
            completed++;
        }
     makeGantChart(process, 3);
}

    for (int i = 0; i < ARR_SIZE; i++){
    timeIndex[i].waitingTime = (process[i].completed - process[i].arrival_time) - process[i].burst_time;
    timeIndex[i].burstTime = process[i].burst_time;
    process[i].actualStart = temp[i].actualStart;
    timeIndex[i].initWaitingTime = process[i].actualStart - process[i].arrival_time;
}
    return time;
}

/*  Function name: roundRobin
    Inputs: Process process[] - Array of processes
            TimeIndex timeIndex[] - Array of statistic time of each 
                                    process 
    Output: int - the wall time
    Description: The function performs the Round Robin 
    scheduling algorithms on the processes.
*/
int roundRobin(Process process[], TimeIndex timeIndex[]) {
    int time = 0;
    int i;
    int timeQuantum;
    int completed = 0;
    Process temp[ARR_SIZE];

    copy_process(process,temp);
    while (completed < ARR_SIZE)
    {
     for (i = 0; i < ARR_SIZE; i++) {
        timeQuantum = 0;
        if (!temp[i].completed)
        {
            int arrivalTime = temp[i].arrival_time;
            while (arrivalTime > time)
            {
                time++;
            }
            if(temp[i].started == 1){
            timeIndex[i].startTime = time;
            temp[i].actualStart = time;
            }
            process[i].actualStart = time;
            int burstTime = temp[i].burst_time;

            while(burstTime > 0 && timeQuantum < 10) {
                burstTime--;
                time++;
                timeQuantum++;
            }
            temp[i].burst_time = burstTime;
            process[i].numberOfBursts++;
            process[i].completed = time;
            if (temp[i].burst_time <= 0)
            {
                temp[i].completed = 1;
                completed++;
                temp[i].burst_time = 0;
            }
            temp[i].started = 0;
        }
    }
    makeGantChart(process, 4);
}

    for ( i = 0; i < ARR_SIZE; i++){
    timeIndex[i].waitingTime = (process[i].completed - process[i].arrival_time) - process[i].burst_time;
    timeIndex[i].burstTime = process[i].burst_time;
    process[i].actualStart = temp[i].actualStart;
    timeIndex[i].initWaitingTime = process[i].actualStart - process[i].arrival_time;
 }
    return time;
}

/*  Function name: priorityScheduling
    Inputs: Process process[] - Array of processes
            TimeIndex timeIndex[] - Array of statistic time of each 
                                    process 
    Output: int - the wall time
    Description: The function performs the priority
    scheduling algorithms on the processes.
*/
int priorityScheduling(Process process[], TimeIndex timeIndex[]) {
 
    Process temp[ARR_SIZE];
    int time = 0;
    int i;
    copy_process(process,temp);
    qsort(temp, (size_t)ARR_SIZE, sizeof(temp[0]), comparePriority);
    sortPriority(process, temp);

        for (i = 0; i < ARR_SIZE; i++) {
            int arrivalTime = process[i].arrival_time;

            timeIndex[i].waitingTime = abs(arrivalTime - time);
            timeIndex[i].initWaitingTime = abs(arrivalTime - time);

            while (arrivalTime > time)
            {
                time++;
            }
            timeIndex[i].startTime = time;
            process[i].actualStart = time;
            int burstTime = process[i].burst_time;

            while(burstTime > 0) {
                burstTime--;
                time++;
            }
            process[i].completed = time;
            timeIndex[i].burstTime = time - timeIndex[i].startTime;           
        }
    return time;
}

/*  Function name: sortQueue
    Inputs: Process process[] - Array of processes
            Process temp[] - 
    Output: None
    Description: see some stuff here so you can't understand
                 what we wrote in here and up because you are not going
                 to read it, and it is nothing important to you. so if you want
                 you can read it and
*/
void sortQueue(Process process[], Process temp[]) {
    int currentTime = 0;
    int processedCount = 0;
  
    while (processedCount < ARR_SIZE) {
        int shortestIndex = -1;
        float shortestBurst = 60;
        // Find the arrived process with the shortest burst time from the sorted temp array
        for (int i = 0; i < ARR_SIZE; i++) {
            if (temp[i].arrival_time <= currentTime && temp[i].process_id != -1) {
                if (temp[i].estimatedBurstTime < shortestBurst) {
                    shortestBurst = temp[i].estimatedBurstTime;
                    shortestIndex = i;
                }
            }
        }

        if (shortestIndex != -1) {
            process[processedCount++] = temp[shortestIndex];
            currentTime += temp[shortestIndex].burst_time;
            temp[shortestIndex].process_id = -1; // Mark as processed
        } else {
            currentTime++; // Move to the next unit of time
        }
    }
}

/*  Function name: sortSRTF
    Inputs: Process process[] - Array of processes
            Process temp[] - 
    Output: None
    Description: 
*/
void sortSRTF(Process process[], Process temp[]) {
    int currentTime = 0;
    int processedCount = 0;
    while (processedCount < ARR_SIZE) {
        int shortestIndex = -1;
        float shortestBurst = 60;
        // Find the arrived process with the shortest burst time from the sorted temp array
        for (int i = 0; i < ARR_SIZE; i++) {
            if (temp[i].arrival_time <= currentTime && temp[i].process_id != -1) {
                if (temp[i].burst_time < shortestBurst) {
                    shortestBurst = temp[i].burst_time;
                    shortestIndex = i;
                }
            }
        }

        if (shortestIndex != -1) {
            process[processedCount++] = temp[shortestIndex];
            currentTime += temp[shortestIndex].burst_time;
            temp[shortestIndex].process_id = -1; // Mark as processed
        } else {
            currentTime++; // Move to the next unit of time
        }
    }
}

/*  Function name: sortPriority
    Inputs: Process process[] - Array of processes
            Process temp[] - 
    Output: None
    Description: 
*/
void sortPriority(Process process[], Process temp[]) {
    int currentTime = 0;
    int processedCount = 0;

    while (processedCount < ARR_SIZE) {
        int highestPriorityIndex = -1;
        int highestPriority = 50;

        // Find the arrived process with the highest priority from the temp array
        for (int i = 0; i < ARR_SIZE; i++) {
            if (temp[i].arrival_time <= currentTime && temp[i].process_id != -1) {
                if (temp[i].priority < highestPriority) {
                    highestPriority = temp[i].priority;
                    highestPriorityIndex = i;
                }
            }
        }

        if (highestPriorityIndex != -1) {
            process[processedCount++] = temp[highestPriorityIndex];
            currentTime += temp[highestPriorityIndex].burst_time;
            temp[highestPriorityIndex].process_id = -1; // Mark as processed
        } else {
            currentTime++; // Move to the next unit of time if no task is available
        }
    }
}

int findShortest(Process temp[], int time) {
    int shortestIndex = -1;
    int shortestBurst = 60;

    for (int i = 0; i < ARR_SIZE; i++) {
        if (!temp[i].completed && temp[i].arrival_time <= time) {
            if (temp[i].burst_time < shortestBurst) {
                shortestBurst = temp[i].burst_time;
                shortestIndex = i;
            }
        }
    }

    return shortestIndex; 
}

static void copy_process(Process src_process[], Process dest_process[])
{
    for (int i = 0; i < ARR_SIZE; i++)
    {
        dest_process[i] = src_process[i];
    }

    return;
}

int runBurst(Process process[], TimeIndex timeIndex[], int time){

 for (int i = 0; i < ARR_SIZE; i++) {
            int arrivalTime = process[i].arrival_time;
            timeIndex[i].waitingTime = abs(arrivalTime - time);
            timeIndex[i].initWaitingTime = abs(arrivalTime - time);
            while (arrivalTime > time)
            {
                time++;
            }
            timeIndex[i].startTime = time;
            process[i].actualStart = time;
            int burstTime = process[i].burst_time;
            while(burstTime > 0) {
                burstTime--;
                time++;
            }
            process[i].completed = time;
            timeIndex[i].burstTime = time - timeIndex[i].startTime;
        }

    return time;
}