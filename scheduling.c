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
void firstComeFirstServe(Process process[], int arr_size, TimeIndex timeIndex[]) {
    int i = 0;
    int cpuBurstTime = 0;
    int cpuTime = 0;
    //cpu burst 15

    while (process[i].cpu_burst_time > 0)
    {
        //cpu time
        //start clock
        //kepp running that process
        //process[i].cpu_burst_time--;
        if (process[i].cpu_burst_time == 0)
        {
            //stop cput time
        while (process[i].io_burst_time > 0)
    {
        //start clock for io burst time
        //kepp running that process
        //process[i].cpu_burst_time--;
        // else if (process[i].cpu_burst_time == 0)
        // {
        //     /* code */
        //     //stop clock cpu time
        // } else{
        // //call clock 
        // //resume clock
        // }
        
        process[i].io_burst_time--;
        
    }
        //stop io burst time
        //cpuBurstTime+=timeIndex[i];
        timeIndex[i].cpuBurstTime = cpuTime;
        
           i++;
        }
        // else if (process[i].cpu_burst_time == 0)
        // {
        //     /* code */
        //     //stop clock cpu time
        // } else{
        // //call clock 
        // //resume clock
        // }
        
        process[i].cpu_burst_time--;
        
    }
    //end cpu clock here



}

void shortestJobFirst(Process process[], int arr_size) {

}

void shortestRemainingTimeFirst(Process process[], int arr_size) {

}

void roundRobin(Process process[], int arr_size) {

}

void priorityScheduling(Process process[], int arr_size) {

}


int main()
{
    int c;
    return 0;
}