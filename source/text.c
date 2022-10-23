#include "text.h"

typedef struct Report {
    char* file;
    int numberOfUpdates;
} report;

int SearchTargetString(char* filepath, char* targetString) {
    
    FILE* fileToSearch;
    fileToSearch = fopen(filepath, "r");
    int currentLine = 0;
    int isFound = 0;

    char tempString[512];

    if (fileToSearch == NULL) {
        printf("Could not open the file to search: %s\n", filepath);
        return isFound;
    }

    while (fgets(tempString, 512, fileToSearch) != NULL) {
        // keep reading lines from file
        if (strstr(tempString, targetString) != NULL) {
            // found first occurence of target string
            isFound = 1;
            printf("Found target string in file: %s (Line %d)\n", filepath, currentLine);
            break;
        }
        currentLine++;
    }

    fclose(fileToSearch); // close the file

    return isFound;

}

// make edit to the file with target string
int EditFile(char* filepath, char* targetString) {

    FILE* fileToEdit;
    fileToEdit = fopen(filepath, "r+"); // open input file in read/write mode
    

    if (fileToEdit == NULL) {
        printf("Could not open the file to edit: %s\n", filepath);
        exit(0);
    }

    char stringRead[512];
    char newString[512];

    while (!feof(fileToEdit)) {
        // keep reading contents of the input file
        fscanf(fileToEdit, "%s", stringRead);
        printf("%s\n", stringRead);
    }

    return 0;

}