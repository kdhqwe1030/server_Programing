#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc,char* argv[]) {
    int fd, n;
    char buf[2];

    fd = open(argv[1], O_RDONLY);

    while ((n = read(fd, buf, 1)) > 0) {
        buf[1] = '\0';
        printf("%s", buf);
        lseek(fd, 1, SEEK_CUR);
    }

    printf("\n");
    close(fd);
    return 0;
}

