#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    char *val;

    if (argc != 2) {
        printf("Usage: %s <env>\n", argv[0]);
        return 1;
    }

    val = getenv(argv[1]);

    if (val == NULL)
        printf("%s not defined\n", argv[1]);
    else
        printf("%s = %s\n", argv[1], val);

    return 0;
}

