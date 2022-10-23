// CONTAINS: the directory traversal logic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> // PATH_MAX
#include <dirent.h> // for reading dirs
#define _POSIX_SOURCE
#include <unistd.h> // getcwd()
#undef _POSIX_SOURCE

#define MAX_NUM_FILES 42 // max number of files to modify (arbitrary)
#define BUFFER_SIZE 1000

typedef struct Report{
    char file[PATH_MAX];
    int numberOfUpdates;
} report;

// gets filepath using filename and starting filepath
char* GetFilepath(char* filename, char* startFilepath);

// opens directory and traverses through directory
void FindFilesWithTargetString(char* path, report listOfFilesWithTarget[], int* numFilesFound);