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

#endif