#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc,char* argv[]) {
    int rfd, wfd, n;
    char buf[10];
    
    rfd = open(argv[1], O_RDONLY);
   
    
    wfd = open(argv[2], O_CREAT | O_WRONLY, 0644);
    
    while ((n = read(rfd, buf, 6)) > 0) {
        if (write(wfd, buf, n) != n) perror("Write");
    }
    
    
    
    close(rfd);
    close(wfd);
}
