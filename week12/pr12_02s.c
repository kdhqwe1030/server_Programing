#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define PORTNUM	5068

char msg[5][50] = {"Hello!", "Good!", "Are you ok?", "Hahahahah", "Not bad."};

int main() {
    char buf[256];
    struct sockaddr_in sin, cli;
    struct in_addr in;
    int sd, ns, ind, clientlen = sizeof(cli);
    //if((sd = socket(AF_INET,????, 0)) == -1) { 
    if((sd = socket(AF_INET,  SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    memset((char *)&sin, '\0', sizeof(sin));
    sin.sin_family = AF_INET;
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
    //if((ns = ????
    if((ns = accept(sd, (struct sockaddr *)&cli, &clientlen)) == -1) {
        //perror("????");
        perror("accept");
        exit(1);
    }
    
    printf("* Client connected!!\n");
    while(1) {
        //if(????(ns, buf,
        if(recv(ns, buf, sizeof(buf), 0) == -1) {
            //perror("????");
            perror("recv");
            exit(1);
        }
        printf("** Client message : %s\n", buf);

        if(buf[0] != 'q') {
            srand((unsigned int)time(NULL));
            ind = (int)rand() % 5;
            sprintf(buf, "%s", msg[ind]);
        }
        else 
            sprintf(buf, "Bye!!");
        //if(????(ns, buf,
        if(send(ns, buf, strlen(buf) + 1, 0) == -1) {
          //perror("????");
            perror("send");
            exit(1);
        }
        if(!strcmp(buf, "Bye!!")) break;
    }
    close(ns);
    close(sd);
    printf("** End of Communication!!\n");
}
