#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
extern int errno;
int main() {
    FILE *fp;
    char *err;
    if ((fp=fopen("missing.txt", "w")) == NULL) {
        err = strerror(errno);
        printf("error: %s(missing.txt)\n", err);
        exit(errno); }
    fclose(fp); 
}
