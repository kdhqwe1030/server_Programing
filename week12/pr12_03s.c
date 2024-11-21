#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

#define SOCKET_NAME	"hbsocket1"

int main() {
    char buf[256];
    struct sockaddr_un ser, cli;
    int sd, nsd, len, clen;
   
    unlink(SOCKET_NAME);

    if((sd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    memset((char *)&ser, 0, sizeof(struct sockaddr_un));
    ser.sun_family = AF_UNIX;
    strcpy(ser.sun_path, SOCKET_NAME);
    len = sizeof(ser.sun_family) + strlen(ser.sun_path);
    
    if(bind(sd, (struct sockaddr *)&ser, len)) {
        perror("bind");
        exit(1);
    }

    if(listen(sd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    printf("Waiting ...\n");
    if((nsd = accept(sd, (struct sockaddr *)&cli, &clen)) == -1) {
printf("accept error\n");
        perror("accept");
        exit(1);
    }

    while(1) {
        if(recv(nsd, buf, sizeof(buf), 0) == -1) {
            perror("recv");
            exit(1);
        }

        printf("** From Client : %s\n", buf);
        printf("** To Client : ");
        fgets(buf, sizeof(buf), stdin);
        if(send(nsd, buf, strlen(buf) + 1, 0) == -1) {
            perror("send");
            exit(1);
        }
        if(!strcmp(buf,"quit\n")) break;
    }

    close(nsd);
    close(sd);
}
