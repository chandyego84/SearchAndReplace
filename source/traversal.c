#include "traversal.h"
#include "text.h"

// gets filepath using filename
char* GetFilepath(char* filename, char* startFilepath) {

    char* fullFilepath = malloc(sizeof(char) * PATH_MAX);

    if (fullFilepath != NULL) {
        // successfully allocated memory
        strcat(fullFilepath, startFilepath);
        strcat(fullFilepath, "/");
        return strcat(fullFilepath, filename);
    } 

    return NULL;

}

void TraverseDirectory(char* path) {
    
    struct dirent* dirEntry; // contains content for directory
    DIR* dir = opendir(path); // pointer directory
    char cwd[PATH_MAX]; // buffer for test dir filepath

    if (dir == NULL) {
        printf("Could not open the directory path: %s\n", path);
    }

    else {
        getcwd(cwd, PATH_MAX);
        strcat(cwd, "/test");
        while ((dirEntry = readdir(dir)) != NULL) {
            // check each content while there exists content to check
            if (dirEntry->d_type == DT_DIR && 
            strcmp(dirEntry->d_name, ".") != 0 && strcmp(dirEntry->d_name, "..") != 0) { // filters out . and .. directories    
                // content is a directory
                char* fullDirPath = GetFilepath(dirEntry->d_name, cwd);
                printf("FullDirPath: %s\n", fullDirPath);
                TraverseDirectory(fullDirPath);
            }
            else if (dirEntry->d_type == DT_REG) {
                // content is a file
                printf("File: %s\n", dirEntry->d_name);
            }
        }   
    }
    
}