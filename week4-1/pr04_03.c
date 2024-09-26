#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char* argv[]) {
 DIR *dp;
 struct dirent *dent;
 dp = opendir(".");
   int found = 0;

    
    while ((dent = readdir(dp)) != NULL) {
     
        if (strcmp(dent->d_name, argv[1]) == 0) {
            found = 1;
     
            if (dent->d_type == DT_DIR) {
                printf("File '%s' does not exist in the current directory.\n", argv[1]);
            } else {
                printf("File '%s' exists in the current directory\n", argv[1]);
            }
            break;
        }
    }

    if (!found) {
        printf("File '%s' does not exist in the current directory.\n", argv[1]);
    }
 closedir(dp);
}

