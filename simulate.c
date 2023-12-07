/*
    Group members: Mohammed Arab, Khanh Le, Ben Cacic
    Course: COMP 3659
    Assignment 2: Process Scheduling Algorithm Simulation 
    File Name: simulate.c
    Purpose use: Perform the simulation 
*/
#include "processes.h"
#include "scheduling.h"
#include "timeControl.h"
#include "output.h"
#include "mylib.h"
#include "stat_table.h"
#include "main_helper.h"

int main() {
    FILE *filePtr;
    filePtr = fopen("output.txt", "w+");

    if (filePtr == NULL)
    {
        printf("ERROR - UNABLE TO OPEN THE FILE\n");
    } else
    {
        menu(filePtr);
        fclose(filePtr);
    }
    return 0;
}
