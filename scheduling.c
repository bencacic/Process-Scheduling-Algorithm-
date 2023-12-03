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
  int time = 0;
  int flag = 0;
  int i ,k ,j;
  int counter = 0;
  int counter1 = 0;
  Process temp[ARR_SIZE];


    for (int i = 0; ARR_SIZE < 20; i++)
    {
        // if(process[i + 1].arrival_time == process[i].arrival_time){
        temp[i] = process[i];
    }
   // sorted by arrival time process
    sort_SJB(temp); //temp is sorted bassed on the expected burst time
    //if process[i].arr

    for (i = 0; counter < 20; i++) {
        // if more than one process is in the ready queue, decide using using process[i].expectedBurst which to run
            for (j = 0; j < ARR_SIZE; j++) {
                k = i;
                if (temp[j].arrival_time <= time && process[i].completed == -1) {
                    if (temp[j].process_id == process[k].process_id)
                    {
                        /* code */
                        flag = 1;
                        break;
                    }else{
                        for (k = i + 1; k < ARR_SIZE; k++)
                        {
                            if (temp[j].process_id == process[k].process_id){
                                flag = 1;
                                 break;
                            }
                        }
                        if (flag) {
                         break;
                            }
                    }
                }
            }

            if (flag)
            {
                   
             int arrivalTime = process[i].arrival_time;
           // printf("arrival time %d\n" ,arrivalTime);
                timeIndex[i].waitingTime = abs(arrivalTime - time);
       
            while (arrivalTime > time)
            {
                time++;
            }
            timeIndex[i].startTime = time;
            process[k].actualStart = time;
            int burstTime = process[k].burst_time;
           // printf("burst time %d\n" ,burstTime);

            while(burstTime > 0) {
                burstTime--;
                time++;
            }
            timeIndex[i].burstTime = time - timeIndex[i].startTime;
            process[k].completed = 0;
            }else{
                time++;
            }
            
       
            if (process[i].completed == -1)
            {
               i = 0;
            }
            flag = 0;
            counter++;
            // if (counter == 80)
            // {
            //     i = 0;
            // }
            

           
        }



 

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
        
        return time;

}

void shortestRemainingTimeFirst(Process process[]) {
    
//call function to give each process arrival time
//   int time = 0; 
//     Process temp[ARR_SIZE];
//     int processSize = sizeof(process) / sizeof(process[0]);
//     int timeSize = sizeof(process) / sizeof(process[0]);
//     int index = -1;
//     for (int i = 0; i < ARR_SIZE; i++)
//     {
//         temp[i] = process[i];
//     }
    
//     for (int i = 0; i < ARR_SIZE; i++) {
//         int arrivalTime = temp[i].arrival_time;
//         // if (temp[i].arrival_time > time) {

//         // }
//         while (arrivalTime > time)
//             {
//                 time++;
//             }
//             temp[i].arrival_time = -1;
//             index = findIndex(timeIndex, timeSize, temp[i].process_id);
//             timeIndex[index].startTime = time;
//             index = findIndex(process, processSize, temp[i].process_id);
//             process[index].actualStart = time;
//             int burstTime = temp[i].burst_time;
//            // printf("burst time %d\n" ,burstTime);

//             while(burstTime > 0 && temp[i + 1].arrival_time > time) {
//                 burstTime--;
//                 time++;
//             }
//             timeIndex[i].burstTime = time - timeIndex[i].startTime;
//            // timeIndex[i].arrivalTime = arrivalTime;
//     }

}

void roundRobin(Process process[]) {

}

void priorityScheduling(Process process[]) {
    

}


int findIndex(const Process *arr, int size, int searchId) {
    for (int i = 0; i < size; i++) {
        if (arr[i].process_id == searchId) {
            return i; // Return the index when the ID matches
        }
    }
    return -1; // Return -1 if not found
}