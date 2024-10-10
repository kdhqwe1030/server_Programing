#include <stdlib.h>
#include <stdio.h>

int main(int argc,char* argv[]) {
    FILE *rfp;
    int c;
    int found = 0;

    rfp = fopen(argv[1], "r");

    while ((c = fgetc(rfp)) != EOF) {
        if (c == '@') {
            printf("My precious!\n");
            found = 1;
        }
    }

    if (!found) {
        printf("Where is my precious?\n");
    }

    fclose(rfp);
    return 0;
}

