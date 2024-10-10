#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int fd, bytesRead;
    char buf[1024];
    char *ptr;
    int id, score1, score2, score3;
    float average;

    fd = open("table.txt", O_RDONLY);
    bytesRead = read(fd, buf, sizeof(buf) - 1);
    buf[bytesRead] = '\0';

    ptr = buf;
    while (*ptr) {
        id = atoi(ptr);
        while (*ptr != ' ' && *ptr != '\0') ptr++;
        ptr++;

        score1 = atoi(ptr);
        while (*ptr != ' ' && *ptr != '\0') ptr++;
        ptr++;

        score2 = atoi(ptr);
        while (*ptr != ' ' && *ptr != '\0') ptr++;
        ptr++;

        score3 = atoi(ptr);
        while (*ptr != '\n' && *ptr != '\0') ptr++;
        if (*ptr == '\n') ptr++;

        average = (score1 + score2 + score3) / 3.0;
        printf("%d %d\n", id, (int)average);
    }

    close(fd);
    return 0;
}

