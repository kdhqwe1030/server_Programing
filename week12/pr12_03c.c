#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

#define SOCKET_NAME	"hbsocket1"

int main() {
    int sd, len;
    char buf[256];
    struct sockaddr_un ser;
   
    if((sd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    memset((char *)&ser, '\0', sizeof(ser));
    ser.sun_family = AF_UNIX;
    strcpy(ser.sun_path, SOCKET_NAME);
    len = sizeof(ser.sun_family) + strlen(ser.sun_path);

    if(connect(sd, (struct sockaddr *)&ser, len) < 0) {
        perror("connect");
        exit(1);
    }

    while(1) {
        printf("To Server : ");
        fgets(buf, sizeof(buf), stdin);

        if(send(sd, buf, strlen(buf)+1, 0) == -1) {
            perror("send");
            exit(1);
        }

        if(recv(sd, buf, sizeof(buf), 0) == -1) {
            perror("recv");
            exit(1);
        }
        printf("* From Server : %s\n", buf);
        buf[strlen(buf)-1]='\0';
        if(!strcmp(buf, "quit")) break;
    }
    close(sd);
}
