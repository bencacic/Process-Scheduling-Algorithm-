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
    int i;
    //processes will be passed in sorted by arrival time.
   // uti = allof cpu time / burst time // burst time is the time where the cpu is busy
        for (i = 0; i < ARR_SIZE; i++) {
             int arrivalTime = process[i].arrival_time;
           // printf("arrival time %d\n" ,arrivalTime);

            // if (arrivalTime > time) {
                timeIndex[i].waitingTime = abs(arrivalTime - time);
            //  }
            //  else 
            //  {
            //       timeIndex[i].waitingTime = 0;
            //  }

            while (arrivalTime > time)
            {
                time++;
            }
            timeIndex[i].startTime = time;
            process[i].actualStart = time;
            int burstTime = process[i].burst_time;
           // printf("burst time %d\n" ,burstTime);

            while(burstTime > 0) {
                burstTime--;
                time++;
            }
            timeIndex[i].burstTime = time - timeIndex[i].startTime;
           // timeIndex[i].arrivalTime = arrivalTime;
           
        }
         printf("Time time 2  %d and %d and %d\n" , process[0].arrival_time, timeIndex[0].startTime, timeIndex[0].waitingTime);
          printf("Time time 2  %d and %d and %d\n" , process[1].arrival_time, timeIndex[1].startTime, timeIndex[1].waitingTime);

         printf("Time time 2  %d and %d and %d\n" , process[2].arrival_time, timeIndex[2].startTime, timeIndex[2].waitingTime);

         printf("Time time 2  %d and %d and %d\n" , process[3].arrival_time, timeIndex[3].startTime, timeIndex[3].waitingTime);
          printf("Time time 2  %d and %d and %d\n" , process[4].arrival_time, timeIndex[4].startTime, timeIndex[4].waitingTime);

        printf("Time time 2  %d and %d and %d\n" , process[5].arrival_time, timeIndex[5].startTime, timeIndex[5].waitingTime);
         printf("Time time 2  %d and %d and %d\n" , process[6].arrival_time, timeIndex[6].startTime, timeIndex[6].waitingTime);
     
         printf("Time time 2  %d and %d and %d\n" , process[7].arrival_time, timeIndex[7].startTime, timeIndex[7].waitingTime);
         printf("Time time 2  %d and %d and %d\n" , process[8].arrival_time, timeIndex[8].startTime, timeIndex[8].waitingTime);
         printf("Time time 2  %d and %d and %d\n" , process[9].arrival_time, timeIndex[9].startTime, timeIndex[9].waitingTime);
        return time;
}

int shortestJobFirst(Process process[], TimeIndex timeIndex[]){
    int time = 0; 

    for (int i = 0; i < ARR_SIZE; i++) { 
        if (process[i].arrival_time < )

    }
    


    // for (int i = 0; i < ARR_SIZE; i++) {
        



    //     int arrivalTime = process[i].arrival_time;
    //     while (arrivalTime > time) {
    //         time++;
    //     }
    //     timeIndex[i].startTime = time;
    //     timeIndex[i].waitingTime = time - arrivalTime;
    //  int burstTime = process->burst_time;
    //         while(burstTime > 0) {
    //             burstTime--;
    //             time++;
    //         }
    //         timeIndex[i].burstTime = time - timeIndex[i].startTime;
    //     }
        return time;

}

void shortestRemainingTimeFirst(Process process[]) {
//call function to give each process arrival time

}

void roundRobin(Process process[]) {

}

void priorityScheduling(Process process[]) {
    

}
