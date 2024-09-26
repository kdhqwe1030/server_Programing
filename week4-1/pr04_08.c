#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    struct stat statbuf;

    stat(argv[1], &statbuf);
    printf("Before Link Count = %ld\n", statbuf.st_nlink);

    link(argv[1], "link.ln");

    stat(argv[1], &statbuf);
    printf("After Link Count = %ld\n", statbuf.st_nlink);

    unlink("link.ln");

    stat(argv[1], &statbuf);
    printf("After Unlink Count = %ld\n", statbuf.st_nlink);

    return 0;
}

