#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    struct stat statbuf;
    mode_t mode;

    printf("%s : Write permission is permitted.\n", argv[2]);
    mode = strtol(argv[1], NULL, 8); 
    if (chmod(argv[2], mode) == -1) {
        perror("chmod");
        return 1;
    }

    return 0;
}

