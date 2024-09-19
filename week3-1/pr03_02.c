#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
int main() {
    if (access("missing.txt", X_OK) == -1) {
        perror("missing.txt");
        exit(1);
    }
}
