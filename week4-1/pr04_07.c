#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc,char* argv[]) {
 char buf[BUFSIZ];
 char buf2[BUFSIZ];
 int n;
symlink(argv[1], "linux.sym");
 n = readlink("linux.sym", buf, BUFSIZ);
 if (n == -1) {
    perror("readlink");
    exit(1);
 }

 buf[n] = '\0';
 printf("linux.sym : READLINK = %s\n", buf);
 
 realpath("linux.sym", buf2);
 printf("linux.sym : REALPATH = %s\n", buf2);
}

