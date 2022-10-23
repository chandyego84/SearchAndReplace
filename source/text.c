#include "text.h"

int SearchTargetString(char* filepath, char* targetString) {
    
    FILE* fileToSearch;
    fileToSearch = fopen(filepath, "r");
    int currentLine = 0;
    int isFound = 0;
    char* pos;

    char tempString[512];

    if (fileToSearch == NULL) {
        printf("Could not open the file to search: %s\n", filepath);
        return isFound;
    }

    while (fgets(tempString, 512, fileToSearch) != NULL) {
        // keep reading lines from file
        if ((pos = strstr(tempString, targetString)) != NULL) {
            // found first occurence of target string
            isFound = 1;
            //printf("Found target string in file: %s (Line %d)\n", filepath, currentLine);
            break;
        }
        currentLine++;
    }

    fclose(fileToSearch); // close the file

    return isFound;

}

int ReplaceAll(char *str, const char* wordToReplace, const char* newWord) {

    // position: pointer to occurence of the word in str, temp: holds original string (before modification)
    char *position, temp[BUFFER_SIZE];
    int indexOfWordToReplace = 0;
    int wordToReplaceLength = strlen(wordToReplace);
    int updatedWords = 0;

    // while loop will continue if both words are the same
    if (!strcmp(wordToReplace, newWord)) {
        return 0;
    }

    // repeat until all occurences of the current word are changed
    while ((position = strstr(str, wordToReplace)) != NULL) {

        updatedWords += 1;

        // copy of original line
        strcpy(temp, str);

        indexOfWordToReplace = position - str; // index where word found starts in the string
        str[indexOfWordToReplace] = '\0'; // terminates string where word found starts

        // strcat new word into current string
        // (this new word will end with '\0', so strcat rest of the current string)
        strcat(str, newWord);

        // strcat rest of the string to the current string
        strcat(str, temp + indexOfWordToReplace + wordToReplaceLength);

    }

    return updatedWords;

}


// make edit to the file with target string
void EditFile(report* currentReport, char* targetString) {

    FILE* fileToEdit;
    FILE* fileToOutput;
    char* filepath = currentReport->file;
    fileToEdit = fopen(filepath, "r"); // open input file in read mode
    fileToOutput = fopen("replace.txt", "w"); // new file with modifications
    char buffer[BUFFER_SIZE];

    if (fileToEdit == NULL || fileToOutput == NULL) {
        printf("Could not open the file to edit: %s\n", currentReport->file);
        exit(0);
    }

    // read line from input file, write to destination file after replacing word/s
    while (fgets(buffer, BUFFER_SIZE, fileToEdit) != NULL) {
        // replace all occurences of the word from the line
        currentReport->numberOfUpdates += ReplaceAll(buffer, targetString, "LONE");
        
        // write string to output file after replacing it
        fputs(buffer, fileToOutput);
    }
    
    // close all files
    fclose(fileToEdit);
    fclose(fileToOutput);

    // delete original path
    remove(filepath);

    // rename the output file as the original file
    rename("replace.txt", filepath);

}