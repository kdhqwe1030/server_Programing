#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char c;

    fp = fopen(argv[1], "r");

    while (fread(&c, 1, 1, fp) == 1) {
        fwrite(&c, 1, 1, stdout);
        fseek(fp, 1, SEEK_CUR);
    }

    printf("\n");
    fclose(fp);
    return 0;
}

