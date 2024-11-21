#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define PORTNUM 5068

int pwnum[5] = {1234, 2345, 3456, 4567, 5678};

int main() {
    char buf[256];
    struct sockaddr_in sin, cli;
    struct in_addr in;
    int a, ind, sd, ns, valid, clientlen = sizeof(cli);
    //if sd= ????
    if((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socekt");
        exit(1);
    }

    memset((char *)&sin, '\0', sizeof(sin));
    sin.sin_family = AF_INET;
    //sin.sin_port = ????(PORTNUM);
    sin.sin_port = htons(PORTNUM);
    sin.sin_addr.s_addr = INADDR_ANY;

    if(bind(sd, (struct sockaddr *)&sin, sizeof(sin))) {
        perror("bind");
        exit(1);
    }
    if(listen(sd, 5)) {
        perror("listen");
        exit(1);
    }

    printf("* Wait Client!\n");
    if((ns = accept(sd, (struct sockaddr *)&cli, &clientlen)) == -1) {
        //perror("????");
        perror("accept");
        exit(1);
    }

    printf("* Client connected!!\n");
        srand((unsigned int)time(NULL));
        ind = rand() % 5;
        sprintf(buf, "%d", ind);
    while(1) {
        if(send(ns, buf, strlen(buf) + 1, 0) == -1) {
            perror("send");
            exit(1);
        }

        if(recv(ns, buf, sizeof(buf), 0) == -1) {
            perror("recv");
            exit(1);
        }
        printf("** Client message : %s\n", buf);

        valid = 0;
        if (atoi(buf) == pwnum[1]){
            valid = 1;
        }

        if(valid)
            sprintf(buf, "Valid Securty Number!");
        else
            sprintf(buf, "Invalid Security Number!");

        if(send(ns, buf, strlen(buf) + 1, 0) == -1) {
            perror("send");
            exit(1);
        }
        if(valid) break;
    }
    close(ns);
    close(sd);
    printf("** End of Communication!!\n");
}
