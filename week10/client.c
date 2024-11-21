#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define CLIENT_TO_SERVER_FIFO "./client_to_server_fifo"
#define SERVER_TO_CLIENT_FIFO "./server_to_client_fifo"

int main() {
    int read_fd, write_fd;
    char buffer[1024];

    if (access(CLIENT_TO_SERVER_FIFO, F_OK) == -1) {
        perror("client_to_server_fifo not found");
        exit(1);
    }

    if (access(SERVER_TO_CLIENT_FIFO, F_OK) == -1) {
        perror("server_to_client_fifo not found");
        exit(1);
    }

    printf("Client is ready for communication...\n");

    if ((write_fd = open(CLIENT_TO_SERVER_FIFO, O_WRONLY)) == -1) {
        perror("open client_to_server_fifo");
        exit(1);
    }

    if ((read_fd = open(SERVER_TO_CLIENT_FIFO, O_RDONLY)) == -1) {
        perror("open server_to_client_fifo");
        exit(1);
    }

    while (1) {
        printf("Enter message to server: ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        if (write(write_fd, buffer, strlen(buffer) + 1) == -1) {
            perror("write to client_to_server_fifo");
            exit(1);
        }

        ssize_t bytes_read = read(read_fd, buffer, sizeof(buffer) - 1);
        if (bytes_read == -1) {
            perror("read from server_to_client_fifo");
            exit(1);
        }
        if (bytes_read == 0) {
            printf("Server has disconnected.\n");
            break;
        }

        buffer[bytes_read] = '\0';
        printf("Received from server: %s\n", buffer);
    }

    close(read_fd);
    close(write_fd);

    return 0;
}

