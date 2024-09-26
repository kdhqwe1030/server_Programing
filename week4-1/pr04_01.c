#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]){

    char *cwd;
    if (mkdir(argv[1], 0755) == -1) {
        perror("mkdir () ");
        exit(1);
    }
    chdir(argv[1]);
    cwd = getcwd(NULL, BUFSIZ);
    printf("cwd: %s\n", cwd);

    free(cwd);
}
