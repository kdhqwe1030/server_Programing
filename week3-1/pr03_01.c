#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
extern int errno;
int main() {
    FILE *fp;
    fp=fopen("test.txt", "w");
    if (fp == NULL) {
        printf("errno=%d\n", errno);
        exit(1);
    }
    fclose(fp);
}
