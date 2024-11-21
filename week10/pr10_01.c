#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char command[100] = "man ";
    strcat(command, argv[1]);

    FILE *fp = popen(command, "r");
    char buffer[256];
    int line_count = 0;

    while (fgets(buffer, sizeof(buffer), fp) != NULL && line_count < 4) {
        printf("%s", buffer);
        line_count++;
    }

    pclose(fp);
    return 0;
}

