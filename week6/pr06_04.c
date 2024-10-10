#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc,char* argv[]) {
    int fd;

    fd = open(argv[1], O_WRONLY, 0644);
    dup2(fd, STDOUT_FILENO);

    char input[100];
    while (fgets(input, sizeof(input), stdin)) {
        printf("%s", input);
    }

    close(fd);
    return 0;
}

