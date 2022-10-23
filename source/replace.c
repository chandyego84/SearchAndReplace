// CONTAINS: main() function and process command line arguments
#include <stdio.h>
#include "traversal.c"
#include "text.c"
#include "report.c"

int main(int argc, char* argv[]) {

    int filesFound = 0;
    report filesWithTarget[MAX_NUM_FILES];  // files with the target string
    char cwd[PATH_MAX]; // buffer for current working directory filepath
    getcwd(cwd, PATH_MAX);

    strcat(cwd, "/test"); // gets filepath for test dir
    //printf("Target String: %s\n", argv[1]);
    printf("Search begins in current folder: %s\n\n", cwd);

    FindFilesWithTargetString(cwd, filesWithTarget, &filesFound);

    // make updates to each file with target string
    for (int changes = 0; changes < filesFound; changes++) {
        EditFile(&filesWithTarget[changes], "lone");
    }

    // sort the files by number of changes (descending)
    qsort(filesWithTarget, filesFound, sizeof(report), comparator);
    PrintRecords(filesWithTarget, filesFound);

    return 0;
}