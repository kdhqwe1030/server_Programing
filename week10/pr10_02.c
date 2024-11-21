#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2];
    pid_t pid;
    char buffer[100];

    pipe(pipefd);
    pid = fork();

    if (pid == 0) {
        char msg[] = "Hello from child!";
        write(pipefd[1], msg, strlen(msg) + 1);
        close(pipefd[1]);
    } else {
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Received message: %s\n", buffer);
        close(pipefd[0]);
    }

    return 0;
}

