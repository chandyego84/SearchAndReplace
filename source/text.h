// CONTAINS: logic associated with the search and replace processing
// performed on each file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// checks if current file has the target string
// makes change to the target string in the file
int SearchTargetString(char* filename, char* targetString);