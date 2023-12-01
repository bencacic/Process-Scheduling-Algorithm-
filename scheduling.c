/*
    Group members: Mohammed Cacic, Khanh Le, Ben Cacic
    Course: COMP 3659
    Assignment 2: Process Scheduling Algorithm Simulation 
    File Name: scheduling.c
    Purpose use: Store scheduling algorithms
*/
#include "scheduling.h"

//initialize process aray
//startr clock to nanosec
//call algortihm funciton
//end clock 
// calculations in testing module
//print data

//
// 

/*
1) tested if there is no I/O burst time which should result in 100% cpu utilization


*/
int firstComeFirstServe(Process process[], TimeIndex timeIndex[]) {
    int time = 0;
    //processes will be passed in sorted by arrival time.
   // uti = allof cpu time / burst time // burst time is the time where the cpu is busy
        for (int i = 0; i < ARR_SIZE; i++) {
             int arrivalTime = process[i].arrival_time;
            while (arrivalTime < time)
            {
                time++;
            }
            timeIndex[i].startTime = time;
            timeIndex[i].waitingTime = time - arrivalTime;
            int burstTime = process->burst_time;
            while(burstTime > 0) {
                burstTime--;
                time++;
            }
            timeIndex[i].burstTime = time - timeIndex[i].startTime;
        }
        return time;
}

void shortestJobFirst(Process process[], TimeIndex timeIndex[]) {
    int time = 0; 

}

void shortestRemainingTimeFirst(Process process[]) {
//call function to give each process arrival time



}

void roundRobin(Process process[]) {

}

void priorityScheduling(Process process[]) {
    

}
