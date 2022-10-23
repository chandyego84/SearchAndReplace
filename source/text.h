// CONTAINS: logic associated with the search and replace processing
// performed on each file
#include <stdio.h>
#include <stdlib.h> // qsort()
#include <string.h>
#include <ctype.h>

// checks if current file has the target string
// makes change to the target string in the file
int SearchTargetString(char* filename, char* targetString); 

// replaces all words in a string with newWord
// RETURNS: number of updated words
int ReplaceAll(char *str, const char* wordToReplace, const char* newWord);

// make edit to the file with target string
void EditFile(report* currentReport, char* targetString);