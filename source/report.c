#include "report.h"

// for use in qsort()
int comparator(const void* a, const void* b) {

  int l = ((report*)a)->numberOfUpdates;
  int r = ((report*)b)->numberOfUpdates;

  return (r - l); // r - l for descending order

}

// print all files in descending order of number of changes to them
void PrintRecords(report listOfReports[], int numberOfReports) {
  
  // int sizeOfList = sizeof listOfReports / sizeof listOfReports[0]; // number of files in list

  printf("** Search Report ** \n\n");
  printf("Updates:         Filename:\n");
  for (int report = 0; report < numberOfReports; report++) {
    printf("%d         %s\n", listOfReports[report].numberOfUpdates, listOfReports[report].file);
  }

}