#include "text.h"

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
        }
        currentLine++;
    }

    fclose(fileToSearch); // close the file

    return isFound;

}

