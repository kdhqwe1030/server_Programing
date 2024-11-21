#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORTNUM 5068

int main() {
    int sd;
    char buf[256];
    struct sockaddr_in sin;

    memset((char *)&sin, '\0', sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORTNUM);
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");

    if((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    if(connect(sd, (struct sockaddr *)&sin, sizeof(sin))) {
        perror("bind");
        exit(1);
    }

    while(1) {
        printf("Wait Server... \n");
        if(recv(sd, buf, sizeof(buf), 0) == -1) {
            perror("recv");
            exit(1);
        }
        if(!strncmp(buf, "Valid", 5)) break;

        printf("From Server : %s\n", buf);

        printf("Input Security Number: ");
        fgets(buf, sizeof(buf), stdin);
        if(send(sd, buf, strlen(buf)+1, 0) == -1) {
            perror("recv");
            exit(1);
        }

    }
    close(sd);
    printf("* End of Comm to Server\n");
}
