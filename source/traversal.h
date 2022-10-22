// CONTAINS: the directory traversal logic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> // PATH_MAX
#include <dirent.h> // for reading dirs
#define _POSIX_SOURCE
#include <unistd.h> // for getting dir path
#undef _POSIX_SOURCE

// gets filepath using filename and starting filepath
char* GetFilepath(char* filename, char* startFilepath);

// opens directory and traverses through directory
void TraverseDirectory(char* path);