#include <stdio.h>
#include <sys/stat.h> 
#include <stdlib.h>

int main(int argc, char *argv[]) {
    struct stat statbuf;

    if (stat(argv[1], &statbuf) == -1) {
        perror("stat");
        exit(1);
    }

 
    printf("SIZE = %ld\n", statbuf.st_size);

    return 0;
}
