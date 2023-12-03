#include "output.h"
#include "processes.h"

static void preSetUp (Process process[], float scaleARR[])
{
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