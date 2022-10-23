// CONTAINS: main() function and process command line arguments
#include <stdio.h>
#include "traversal.c"
#include "text.c"

int main(int argc, char* argv[]) {

    int filesFound = 0;
    char filesWithTarget[MAX_NUM_FILES][PATH_MAX];  // files with the target string
    char cwd[PATH_MAX]; // buffer for current working directory filepath
    getcwd(cwd, PATH_MAX);

    strcat(cwd, "/test"); // gets filepath for test dir
    FindFilesWithTargetString(cwd, filesWithTarget, &filesFound);

    // make updates to each file with target string
    for (int changes = 0; changes < filesFound; changes++) {
        EditFile(filesWithTarget[changes], "lone");
    }

    return 0;
}