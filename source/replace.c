// CONTAINS: main() function and process command line arguments
#include <stdio.h>
#include "traversal.c"
#include "text.c"

int main(int argc, char* argv[]) {

    int filesFound = 0;
    report filesWithTarget[MAX_NUM_FILES];  // files with the target string
    char cwd[PATH_MAX]; // buffer for current working directory filepath
    getcwd(cwd, PATH_MAX);

    strcat(cwd, "/test"); // gets filepath for test dir
    FindFilesWithTargetString(cwd, filesWithTarget, &filesFound);

    // make updates to each file with target string
    report currentFileReport;
    for (int changes = 0; changes < filesFound; changes++) {
        currentFileReport = EditFile(filesWithTarget[changes].file, "lone");
        printf("File (%s) Number of Changes: %d\n", currentFileReport.file, currentFileReport.numberOfUpdates);
    }

    return 0;
}