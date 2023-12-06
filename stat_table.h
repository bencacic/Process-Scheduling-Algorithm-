/* Group Members: Mohammed Arab, Khanh Le, Ben Cacic
   Course: COMP 3659
   Assignment: Assignment 02
   Instructor: Marc Schroeder
   File Name: stat_table.h
 */
#ifndef STAT_TABLE_H
#define STAT_TABLE_H

#include "processes.h"
#include "output.h"

void statistic_table(Process process[], int choice);
static void print_table_priority(Process process[]);
static void print_table_FCFS(Process process[]);
static void print_table_ExpectedBurst(Process process[]);
static void print_label(int choice);
static void print_lable_name();
static void print_table_RR(Process process[]);
static void print_process_stat(Process process[], int index, int choice);

#endif