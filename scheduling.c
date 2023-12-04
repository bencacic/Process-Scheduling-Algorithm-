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
        //  printf("Time time 2  %d and %d and %d\n" , process[0].arrival_time, timeIndex[0].startTime, timeIndex[0].waitingTime);
        //  printf("Time time 2  %d and %d and %d\n" , process[1].arrival_time, timeIndex[1].startTime, timeIndex[1].waitingTime);

        //  printf("Time time 2  %d and %d and %d\n" , process[2].arrival_time, timeIndex[2].startTime, timeIndex[2].waitingTime);

        //  printf("Time time 2  %d and %d and %d\n" , process[3].arrival_time, timeIndex[3].startTime, timeIndex[3].waitingTime);
        //   printf("Time time 2  %d and %d and %d\n" , process[4].arrival_time, timeIndex[4].startTime, timeIndex[4].waitingTime);

        // printf("Time time 2  %d and %d and %d\n" , process[5].arrival_time, timeIndex[5].startTime, timeIndex[5].waitingTime);
        //  printf("Time time 2  %d and %d and %d\n" , process[6].arrival_time, timeIndex[6].startTime, timeIndex[6].waitingTime);
     
        //  printf("Time time 2  %d and %d and %d\n" , process[7].arrival_time, timeIndex[7].startTime, timeIndex[7].waitingTime);
        //  printf("Time time 2  %d and %d and %d\n" , process[8].arrival_time, timeIndex[8].startTime, timeIndex[8].waitingTime);
        //  printf("Time time 2  %d and %d and %d\n" , process[9].arrival_time, timeIndex[9].startTime, timeIndex[9].waitingTime);
        
        return time;
}

int shortestJobFirst(Process process[], TimeIndex timeIndex[]){
 

     Process temp[ARR_SIZE];
   // estimateBurstTime(process);
     int time = 0;
      int i;
   // qsort(process, (size_t)ARR_SIZE, sizeof(process[0]), compareArrivalTime);
    for(int i = 0; i < ARR_SIZE;i++){
        temp[i] = process[i];
    }
    qsort(temp, (size_t)ARR_SIZE, sizeof(temp[0]), compareSJF);
    sortQueue(process, temp);
    // for (int i = 0; i < ARR_SIZE; i++) {
    //     printf("Process ID: %d, Arrival Time: %d, Expected Burst Time: %f, burst_time: %d\n",
    //            process[i].process_id, process[i].arrival_time, process[i].estimatedBurstTime,process[i].burst_time);
    // }
   
   
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
    
    
    

        return time;
 

    //      printf("process 0 process_id %d and startTime %d and estimatedBurstTime %f\n" , process[0].process_id, process[0].arrival_time, process[0].estimatedBurstTime);
    //      printf("process 1 process_id %d and startTime %d and estimatedBurstTime %f\n" , process[1].process_id, process[1].arrival_time, process[1].estimatedBurstTime);

    //    printf("process 2 process_id %d and startTime %d and estimatedBurstTime %f\n" , process[2].process_id, process[2].arrival_time, process[2].estimatedBurstTime);

    //      printf("process 3 process_id %d and startTime %d and estimatedBurstTime %f\n" , process[3].process_id, process[3].arrival_time, process[3].estimatedBurstTime);
    //      printf("process 4 process_id %d and startTime %d and estimatedBurstTime %f\n" , process[4].process_id, process[4].arrival_time, process[4].estimatedBurstTime);

    //     printf("process 5 process_id %d and startTime %d and estimatedBurstTime %f\n" , process[5].process_id, process[5].arrival_time, process[5].estimatedBurstTime);
    //      printf("process 6 process_id %d and startTime %d and estimatedBurstTime %f\n" , process[6].process_id, process[6].arrival_time, process[6].estimatedBurstTime);
    //     printf("process 7 process_id %d and startTime %d and estimatedBurstTime %f\n" , process[7].process_id, process[7].arrival_time, process[7].estimatedBurstTime);
    //      printf("process 8 process_id %d and startTime %d and estimatedBurstTime %f\n" , process[8].process_id, process[8].arrival_time, process[8].estimatedBurstTime);
    //      printf("process 9 process_id %d and startTime %d and estimatedBurstTime %f\n" , process[9].process_id, process[9].arrival_time, process[9].estimatedBurstTime);

    //       printf("temp time 0 process_id %d and startTime %d and estimatedBurstTime %f\n" , temp[0].process_id, temp[0].arrival_time, temp[0].estimatedBurstTime);
    //      printf("temp time 1 process_id %d and startTime %d and estimatedBurstTime %f\n" , temp[1].process_id, temp[1].arrival_time, temp[1].estimatedBurstTime);

    //     printf("temptemp time 2 process_id %d and startTime %d and estimatedBurstTime %f\n" , temp[2].process_id, temp[2].arrival_time, temp[2].estimatedBurstTime);

    //      printf("temp time 3 process_id %d and startTime %d and estimatedBurstTime %f\n" , temp[3].process_id, temp[3].arrival_time, temp[3].estimatedBurstTime);
    //      printf("temp time 4 process_id %d and startTime %d and estimatedBurstTime %f\n" , temp[4].process_id, temp[4].arrival_time, temp[4].estimatedBurstTime);

    //      printf("temp time 5 process_id %d and startTime %d and estimatedBurstTime %f\n" , temp[5].process_id, temp[5].arrival_time, temp[5].estimatedBurstTime);
    //      printf("temp time 6 process_id %d and startTime %d and estimatedBurstTime %f\n" , temp[6].process_id, temp[6].arrival_time, temp[6].estimatedBurstTime);
    //      printf("temp time 7 process_id %d and startTime %d and estimatedBurstTime %f\n" , temp[7].process_id, temp[7].arrival_time, temp[7].estimatedBurstTime);
    //      printf("temp time 8 process_id %d and startTime %d and estimatedBurstTime %f\n" , temp[8].process_id, temp[8].arrival_time, temp[8].estimatedBurstTime);
    //      printf("temp time 9 process_id %d and startTime %d and estimatedBurstTime %f\n" , temp[9].process_id, temp[9].arrival_time, temp[9].estimatedBurstTime);
        
       

}

int shortestRemainingTimeFirst(Process process[], TimeIndex timeIndex[]) {
    int time = 0;
    int i;
     Process temp[ARR_SIZE];


    for(int i = 0; i < ARR_SIZE;i++){
        temp[i] = process[i];
    }

    qsort(temp, (size_t)ARR_SIZE, sizeof(temp[0]), compareSJF);
    sortQueue(process, temp);

    for (i = 0; i < ARR_SIZE; i++) {
        int arrivalTime = process[i].arrival_time;

        timeIndex[i].waitingTime = abs(arrivalTime - time);

        while (arrivalTime > time) {
            time++;
        }

        for (int j = 0; j < ARR_SIZE; j++) {
            if ((process[j].estimatedBurstTime > process[i].estimatedBurstTime) && (process[j].arrival_time <= time) && process[j].completed == -1) {
                swap(process, i, j);
                break;
            }
        }

        timeIndex[i].startTime = time;
        process[i].actualStart = time;

        if (process[i].burst_time > 0) {
            process[i].burst_time--;
            time++;
        }

        timeIndex[i].burstTime = time - timeIndex[i].startTime;
    }

    return time;
}

// int shortestRemainingTimeFirst(Process process[], TimeIndex timeIndex[]) {

//   Process readyQueue[ARR_SIZE];
//    // estimateBurstTime(process);
//      int time = 0;
//       int i;
//    // qsort(process, (size_t)ARR_SIZE, sizeof(process[0]), compareArrivalTime);
//     // for(int i = 0; i < ARR_SIZE;i++){
//     //     readyQueue[i] = process[i];
//     // }
//      qsort(readyQueue, (size_t)ARR_SIZE, sizeof(readyQueue[0]), compareSJF);
//     sortQueue(process, readyQueue);
   
//     //processes will be passed in sorted by arrival time.
//    // uti = allof cpu time / burst time // burst time is the time where the cpu is busy
//     //int processesRemaining = ARR_SIZE;

//         for (i = 0; i < ARR_SIZE; i++) {
//             int arrivalTime = process[i].arrival_time;

//             timeIndex[i].waitingTime = abs(arrivalTime - time);

//             while (arrivalTime > time)
//             {
//                 time++;
//             }

//             for(int j = 0; j < ARR_SIZE; j++) {
//                if((process[j].estimatedBurstTime > process[i].estimatedBurstTime) && (process[j].arrival_time <= time) && process[j].completed == -1) {
//                 swap(process, i, j);
//                 break;
//                }
//             }

//             if (process[i].completed == -1 ){
//                 timeIndex[i].startTime = time;
//                 process[i].actualStart = time;
//                 //int burstTime = process[i].burst_time;

//                 if (process[i].burst_time > 0) {
//                     process[i].burst_time--;
//                     time++;
//                 }

//                 timeIndex[i].burstTime += time - timeIndex[i].startTime;

//             }
//         }

//         return time;
// }

void roundRobin(Process process[]) {

}

// non-preemptive priority schedule
int priorityScheduling(Process process[], TimeIndex timeIndex[]) {
    int pointer_01 = 0, pointer_02;
    int elapsedTime = 0;
    Process temp_process_01, temp_process_02;
    for (int i = 0; i < ARR_SIZE; i++)
    {
        elapsedTime = process[pointer_01].arrival_time;
    }
    return 1;     
}


int findIndex(const Process *arr, int size, int searchId) {

    for (int i = 0; i < size; i++) {
        if (arr[i].process_id == searchId) {
            return i; // Return the index when the ID matches
        }
    }
    return -1; // Return -1 if not found
}


void sortQueue(Process process[], Process temp[]) {
    //Process temp[ARR_SIZE]; // Use ARR_SIZE instead of 10 for consistency

    // for (int i = 0; i < ARR_SIZE; i++) {
    //     temp[i] = readyQueue[i]; // Make a copy of the process array
    // }

    // Sort temp (copy of process array) by expected burst time using qsort
   //qsort(temp, ARR_SIZE, sizeof(Process), compareSJF);

    int currentTime = 0;
    int processedCount = 0;
  
    while (processedCount < ARR_SIZE) {
        int shortestIndex = -1;
        // Set to a large value initially
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

    // Display the sorted processes
    for (int i = 0; i < ARR_SIZE; i++) {
        printf("Process ID: %d, Arrival Time: %d, Expected Burst Time: %f, burst_time: %d\n",
               process[i].process_id, process[i].arrival_time, process[i].estimatedBurstTime,process[i].burst_time);
    }
}
