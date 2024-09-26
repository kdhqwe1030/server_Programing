#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char* argv[]) {
    DIR *dp;
    struct dirent *dent;
    int isempty = 1; 

    
    if ((dp = opendir(argv[1])) == NULL) {
        perror("opendir() ");
        exit(1);
    }

    while ((dent = readdir(dp)) != NULL) {

        if (strcmp(dent->d_name, ".") != 0 && strcmp(dent->d_name, "..") != 0) {
            isempty = 0; 
            break;
        }
    }

     if (isempty) {
        printf("The directory '%s' is empty.\n", argv[1]);
        rmdir(argv[1]);
        printf("The directory '%s' has been deleted.\n", argv[1]);
    } else {
        printf("The directory '%s' is not empty.\n", argv[1]);
    }

    closedir(dp);
    return 0;
}

