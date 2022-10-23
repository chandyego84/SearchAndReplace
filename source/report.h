// contains functions for handling reports for each file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> // PATH_MAX

// for use in qsort()
int comparator(const void* a, const void* b);

// print all files in descending order of number of changes to them
void PrintRecords(report listOfReports[], int numberOfReports);
