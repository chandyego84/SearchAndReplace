# Simple Search and Replace File Application (C)

### Outline
1. Find a user-specificed text string within a group of disk files
2. Modify those strings and update the original disk files
3. Provide a report that indicates what has been done

### Process
1. Read contents of the directory to see what files need to be checked
2. Loop through the file list, open and examine each text file
3. For each text file found in the directory, open each and check for the string that was entered at the command line. Target string may occur multiple times.
4. When target string is found, modify the text so that the target string is printed in upper case.
5. Directories can be nested. If the current directory has sub directories, must search those as well. When looping through contents of the directory, check if each content is a file or a directory
6. Keep track of the files that were changed and the number of changes made in each one. At the end of the process, print out a report including the list for each changed file and the count of the changes in each. The files should be ordered on the number of changes in descending order.

### Example Report
Target string: apple  
Search begins in current folder: /home/me/testDir  
<br>
** Search Report **  
Updates     File Name  
4           dirY\apple.txt
3           bob.txt
2           dirY\sturp.txt
<br><br>
Note: The output includes the starting folder. This can be obtained with getcwd() function in <unistd.h>. Moreover, the "File Name" includes the sub-folder element.