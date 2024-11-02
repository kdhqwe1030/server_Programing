#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    char *val;

    val = getenv(argv[1]);

    if (val == NULL) {
        setenv(argv[1], argv[2], 0);
        val = getenv(argv[1]);
    }

    if (val != NULL) {
        printf("%s=%s\n", argv[1], val);
    }

    return 0;
}

