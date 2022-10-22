// CONTAINS: main() function and process command line arguments
#include <stdio.h>
#include "traversal.c"
#include "text.c"

int main(int argc, char* argv[]) {

    char cwd[PATH_MAX]; // buffer for current working directory filepath
    getcwd(cwd, PATH_MAX);

    strcat(cwd, "/test"); // gets filepath for test dir
    TraverseDirectory(cwd);

    return 0;
}